# # Завдання 1. Напишіть функцію, що обчислює добуток елементів списку цілих. 
# # Список передається як параметр. Отриманий результат повертається з функції.

# spysok = [4, 7, 9, 5, 2]

# def Dobutok(spysok):
#     dob = 1
#     for item in spysok:
#         dob *= item
#     return dob

# result = Dobutok(spysok)
# print(f"Добуток елементів списку: {result}")




# # Завдання 2. Напишіть функцію для знаходження мінімуму в списку цілих. 
# # Список передається як параметр. Отриманий результат повертається з функції.

# def spysokCul(num1, num2, num3, num4):
#     minOflist = min(num1, num2, num3, num4)
#     print(f"Мінімальне число зі списку: {minOflist}")

# spysokCul(12, 5, 8, 9)




# # Завдання 3. Напишіть функцію, що визначає кількість простих чисел у списку цілих.
# # Список передається як параметр. Отриманий результат повертається з функції.

# def isSimple(num):
#     if num < 2:
#         return False
#     for item in range(2, num):
#         if num % item == 0:
#             return False
#     return True

# def countList(spysok):
#     count = 0
#     for num in spysok:
#         if isSimple(num):
#             count += 1
#     return count

# spysok = [2, 3, 5, 7, 10, 11, 13, 17]
# result = countList(spysok)
# print(f"Кількість простих чисел у списку: {result}")




# # Завдання 4. Напишіть функцію, що видаляє зі списку цілих деяке задане число.
# # З функції потрібно повернути кількість видалених елементів.

# def removeNum(spysok, numToremove):
#     count = 0
#     while numToremove in spysok:
#         spysok.remove(numToremove)
#         count += 1
#     return count

# spysok = [1, 2, 3, 4, 3, 5, 3, 6]
# numToremove = 3

# result = removeNum(spysok, numToremove)
# print(f"Кількість видалених елементів: {result}")
# print(f"Оновлений список: {spysok}")





# # Завдання 5. Напишіть функцію, яка отримує два списки як параметр 
# # і повертає список, що містить елементи обох списків.

# def spysokPar(spysok1, spysok2):
#     spysokPar = spysok1 + spysok2
#     return spysokPar

# spysok1 = [1, 2, 3]
# spysok2 = [4, 5, 6]

# result = spysokPar(spysok1, spysok2)
# print(f"Об'єднаний список: {result}")





# # Завдання 6. Напишіть функцію, що обчислює ступінь кожного елемента списку цілих.
# # Значення для ступеня передається як параметр, список теж передається як параметр.
# # Функція повертає новий список, що містить отримані результати.

# spysok = [2, 3, 4, 5]
# stepin = 2

# def stepOfelements(spysok, step):
#     neWspysok = []
#     for item in spysok:
#         neWspysok.append(item**step)
#     return neWspysok

# result = stepOfelements(spysok, stepin)
# print(f"Список, піднятий до ступеня {stepin}: {result}")