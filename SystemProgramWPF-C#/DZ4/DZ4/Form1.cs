using System;
using System.Collections.Generic;
using System.Threading;
using System.Windows.Forms;

namespace DZ4
{
    public partial class Form1 : Form
    {
        private Thread primeThread;
        private Thread fibonacciThread;
        private bool isRunningPrime;
        private bool isRunningFibonacci;

        public Form1()
        {
            InitializeComponent();
            isRunningPrime = false;
            isRunningFibonacci = false;
        }

        private bool Chuslo(int num)
        {
            if (num < 2) return false;
            for (int i = 2; i <= Math.Sqrt(num); i++)
            {
                if (num % i == 0)
                    return false;
            }
            return true;
        }

        private void GenChusel(int nuz_mezha, int verh_mezha)
        {
            listBoxPrimes.Invoke((Action)(() => listBoxPrimes.Items.Clear()));
            for (int i = nuz_mezha; i <= verh_mezha && isRunningPrime; i++)
            {
                if (Chuslo(i))
                {
                    listBoxPrimes.Invoke((Action)(() => listBoxPrimes.Items.Add(i)));
                    Thread.Sleep(200);
                }
            }
            isRunningPrime = false;
        }

        private void GenFibonacci(int limit)
        {
            listBoxFibonacci.Invoke((Action)(() => listBoxFibonacci.Items.Clear()));
            int a = 0, b = 1;
            while (isRunningFibonacci && a <= limit)
            {
                listBoxFibonacci.Invoke((Action)(() => listBoxFibonacci.Items.Add(a)));
                int temp = a;
                a = b;
                b = temp + b;
                Thread.Sleep(200);
            }
            isRunningFibonacci = false;
        }

        private void buttonStartPrime_Click(object sender, EventArgs e)
        {
            if (isRunningPrime) StopGenPrime();
            listBoxPrimes.Items.Clear();

            int nuz_mezha = string.IsNullOrEmpty(textBoxLowerLimit.Text) ? 2 : Convert.ToInt32(textBoxLowerLimit.Text);
            int verh_mezha = string.IsNullOrEmpty(textBoxUpperLimit.Text) ? int.MaxValue : Convert.ToInt32(textBoxUpperLimit.Text);

            primeThread = new Thread(() => GenChusel(nuz_mezha, verh_mezha));
            isRunningPrime = true;
            primeThread.Start();
        }

        private void buttonStartFibonacci_Click(object sender, EventArgs e)
        {
            if (isRunningFibonacci) StopGenFibonacci();
            listBoxFibonacci.Items.Clear();

            int limit = string.IsNullOrEmpty(textBoxUpperLimit.Text) ? int.MaxValue : Convert.ToInt32(textBoxUpperLimit.Text);

            fibonacciThread = new Thread(() => GenFibonacci(limit));
            isRunningFibonacci = true;
            fibonacciThread.Start();
        }

        private void buttonStopPrime_Click(object sender, EventArgs e)
        {
            StopGenPrime();
        }

        private void buttonStopFibonacci_Click(object sender, EventArgs e)
        {
            StopGenFibonacci();
        }

        private void StopGenPrime()
        {
            if (isRunningPrime)
            {
                isRunningPrime = false;
                primeThread.Join();
            }
        }

        private void StopGenFibonacci()
        {
            if (isRunningFibonacci)
            {
                isRunningFibonacci = false;
                fibonacciThread.Join();
            }
        }

        private void buttonClearPrimes_Click(object sender, EventArgs e)
        {
            listBoxPrimes.Items.Clear();
        }

        private void buttonClearFibonacci_Click(object sender, EventArgs e)
        {
            listBoxFibonacci.Items.Clear();
        }
    }
}
