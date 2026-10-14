# #  Завдання 1. Написати рекурсивну функцію знаходження найбільшого спільного дільника двох цілих чисел.
# def bigSpilDebtor(a, b):
#     if b == 0:
#         return a
#     else:
#         return bigSpilDebtor(b, a%b)

# num1 = int(input("Введіть перше число: "))
# num2 = int(input("Введіть друге число: "))
# result = bigSpilDebtor(num1, num2)
# print(f"Найбільшим спільним дільником чисел {num1} та {num2}, буде: {result}")

# # Завдання 2. Написати гру "Бики і корови". Програма загадує чотиризначне число і гравець має вгадати це число. 
# # Після введення користувачем числа, програма повідомляє - скільки цифр цього числа вгадано, це будуть Бики. 
# # Скільки цифр вгадано і ці цифри стоять на тих місцях де загадане число - це Корови. Після відгадування числа, 
# # на екран необхідно вивести кількість спроб зроблених користувачем. У програмі необхідно викорисовувати рекурсію.

# import random

# def genSecretNum():
#     return ''.join(random.sample('0123456789', 4))

# def BullsAndCows(SecretNum, attempts=1):
#     guess = input("Введіть чотиризначне число: ")

#     if len(guess) != 4 or not guess.isdigit():
#         print("Будь ласка, введіть чотиризначне число!")
#         BullsAndCows(SecretNum, attempts)
#         return

#     bulls = 0
#     cows = 0

#     for item in range(4):
#         if guess[item] == SecretNum[item]:
#             cows += 1
#             print(f"Цифра {guess[item]} відгадана, та стоїть на своєму місці")
#         elif guess[item] in SecretNum:
#             bulls += 1
#             print(f"Цифра {guess[item]} відгадана, але не стоїть на своєму місці")

#     print(f"Бики: {bulls}, Корови: {cows}")

#     if cows == 4:
#         print(f"Вітаємо! Ви вгадали число {SecretNum} за {attempts} спроб!")
#     else:
#         BullsAndCows(SecretNum, attempts + 1)

# def main():
#     SecretNum = genSecretNum()
#     # print(SecretNum)
#     print("Гра 'Бики і корови'")
#     print("Спробуйте вгадати чотиризначне число.")
#     BullsAndCows(SecretNum)

# if __name__ == "__main__":
#     main()