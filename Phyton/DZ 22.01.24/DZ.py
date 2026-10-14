# Завдання 1.
# Користувач вводить із клавіатури рядок. Перевірте, чи є введений рядок паліндромом? 
# Паліндром - слово або текст, яке читається однаково зліва направо і справа наліво.

# string = input("Введіть рядок: ")
# str = ''.join(string.split())   #Видаляємо пробіли
# str = str.lower()               #Переводимо символи у нижній регістр

# if str == str[::-1]:            #Перевіряємо оригінальний рядок з перевернутим
#     print("Це паліндром.")
# else:
#     print("Це не паліндром.")

# # По іншому:

# str = "А буду я у дуба"

# str2 = str.replace(" ", "")
# print(str2)
# if str2.lower() == str2[::-1].lower:
#     print("Рядок є паліндромом")
# else:
#     print("Рядок не є паліндромом")
# charList = list(str)
    
# charList = list(str)
# print(charList)
# for item in charList:
#     if item == " " or item == "," or item == "-":
#         charList.remove(item)

# id = 0
# while id < len(charList):
#         if charList[id] == " " or charList[id] == "," or charList[id] == "-":
#             charList.remove(charList[id])
#         id+=1
# print(charList)

# charList = list(str.lower())
# newlist = []
# for item in charList:
#     if item != " " and item != "," and item != "-":
#         newlist.append(item)

# if newlist == newlist[::-1]:
#     print("Рядок є паліндромом")
# else:
#     print("Рядок не є паліндромом")

# print(newlist)


# # Завдання 2.
# # Користувач вводить із клавіатури певний текст, після чого користувач вводить список зарезервованих слів. 
# # Необхідно знайти в тексті всі зарезервовані слова і змінити їхній регістр на верхній. Вивести на екран змінений текст.

# text = input("Введіть текст: ")
# reserved = input("Введіть список зарезервованих слів (через пробіл): ")
# reserved = reserved.split()         #Перетворюємо слова на верхній регістр

# for item in reserved:
#     text = text.replace(item, item.upper())     #Замінюємо у тексті слова з регістру
    
# print("Змінений текст:", text)


# По іншому:
# text = "Hello python is Language to write code"
# reserve = ["python", "Hello", "sunday"]
# wordsList = text.split(" ")
# for item in wordsList:
#     if item.replace(",","").lower() in reserve:
#         wordsList[wordsList.index(item)] = item.upper()
# print(wordsList)
# result = " ".join(wordsList)
# print(result)

# result = text.lower()
# for item in reserve:
#     result = result.replace(item.lower(), item.upper())
# print(result)


# import re

# r"^" #початок "$" кінець
# r"a"                      # r"... - це значить що це регулярний вираз
# r"[0-9]"
# r"[a-zA-Z]"

# str = "AB0fC7G"
# result = re.findall(r"[a-zA-Z0-9]", str)  # findall - пошук у виразі
# print(result)


# import re
# str = "AAAA. CCCC Ffffa! Paaaa.Sfff ff?"
# result = re.split(r"[.!?]", str)
# print(result)

# result = re.findall(r"[.!?]", str)
# print(len(result))


# # Завдання 3.
# # Є деякий текст. Порахуйте в цьому тексті кількість речень і виведіть на екран отриманий результат.

# text = input("Введіть текст: ")
# num_text = 0                #Вводимо змінну для підрахунку речень
# end_text = ['.', '!', '?']  #Символи які позначають кінець речення

# for item in text:           #Шукаємо ці символи, якщо знаходимо, то доплюсовуємо 1 до лічильника
#     if item in end_text:    #Тобто це і буде означати кінець речення.
#         num_text += 1

# print(f"Кількість речень в тексті: {num_text}")

# # По іншому:
