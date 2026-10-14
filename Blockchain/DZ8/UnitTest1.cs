using UnitTestDemo;

namespace BankTestProject1
{
    [TestFixture]
    public class Tests
    {
        private BankAccount ac1;
        private BankAccount ac2;

        [SetUp]
        public void Setup()
        {
            ac1 = new BankAccount();
            ac2 = new BankAccount();
        }

        [Test]
        public void DepositTest()
        {
            ac1.Deposit(100);
            Assert.That(ac1.Balance == 120);
        }

        [Test]
        public void TransferTest1()
        {
            ac1.Deposit(100);
            ac1.Transfer(ac2, 100);
            Assert.That(ac2.Balance == 120);
            Assert.That(ac1.Balance == 20);
        }

        [Test]
        public void TransferTest2()
        {
            WrongBalance ex = Assert.Throws<WrongBalance>(() =>
            {
                ac1.Transfer(ac2, 100);
            });
            Assert.AreEqual("Exception WrongBalance :  current balance is 20", ex.Message);
        }

        [Test]
        public void DepositNegativeThrows()
        {
            WrongAmount ex = Assert.Throws<WrongAmount>(() =>
            {
                ac1.Deposit(-30);
            });
            Assert.AreEqual("Exception WrongAmount :  amount is -30", ex.Message);
        }

        [Test]
        public void WithdrawSuccess()
        {
            ac1.Deposit(50); // баланс = 70
            ac1.Withdraw(30);
            Assert.That(ac1.Balance == 40);
        }

        [Test]
        public void BalanceUnchangedOnFailedWithdraw()
        {
            try
            {
                ac1.Withdraw(100);
            }
            catch (WrongBalance)
            {
            }
            Assert.That(ac1.Balance == 20);
        }

        [Test]
        public void DefaultLimitCheck()
        {
            Assert.That(ac1.Limit == 20);
        }

        [Test]
        public void MultipleDepositsAddCorrectly()
        {
            ac1.Deposit(10);
            ac1.Deposit(15);
            ac1.Deposit(5);
            Assert.That(ac1.Balance == 50); // 20 + 10 + 15 + 5
        }

        [Test]
        public void TransferThrowsWhenDestinationDepositFails()
        {
            // Тут не викличе помилку, бо destination.Deposit не перевіряє баланс
            ac1.Deposit(50);
            ac1.Transfer(ac2, 50);
            Assert.That(ac1.Balance == 20);
            Assert.That(ac2.Balance == 70);
        }

        [Test]
        public void DepositZeroThrows()
        {
            WrongAmount ex = Assert.Throws<WrongAmount>(() =>
            {
                ac1.Deposit(0);
            });
            Assert.AreEqual("Exception WrongAmount :  amount is 0", ex.Message);
        }

        [Test]
        public void WithdrawExactlyToLimitWorks()
        {
            ac1.Deposit(30); // balance = 50
            ac1.Withdraw(30); // balance = 20 (== limit)
            Assert.That(ac1.Balance == 20);
        }
    }
}
