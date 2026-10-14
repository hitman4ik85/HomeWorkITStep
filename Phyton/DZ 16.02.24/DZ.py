# # Завдання 1. Напишите программу которая запрашивает у пользователя число и вычисляет его файториал. 
# # Обработайте исключение, возникающее при вводе отрицательного числа, и выведите сообщение об ошибке.

# def factorial():
#     try:
#         num = int(input("ВВедіть число для знаходження факторіалу: "))
#         if num < 0:
#             raise ValueError
#         if num == 0:
#             print(f"Факторіал {num} = 1")
#         result = 1
#         for item in range(1, num + 1):
#             result = result * item
#         print(f"Факторіал {num} = {result}")
#     except ValueError:
#         print("Введені дані не яввляються цілим числом.")
#         factorial()
# factorial()




# # Завдання 3. Напишите программу которая позволяем заполнить пользователю список с клавиатуры числами. 
# # После получения данных отобразите на экран меню, которое позволит выполнить следующие операции:
# # Отображение списка, Получение макс значения в списке, Получение мин значения в списке, Отображение 
# # значения элемента по индексу, введёному пользователем, Удаление элемента по индексу, введенному пользователем.
# # Обработайте исключение, возникающее при выходе за приделы списка (пользователь ввёл неверное значение для 
# # индекса елемента в списке) и выведите сообщение об ошибке.

# def menue():
#     print("\nМеню:")
#     print("1. Відобразити список")
#     print("2. Отримання максимального значення")
#     print("3. Отримання мінімального значення")
#     print("4. Отримання значення елемента по індексу")
#     print("5. Видалення елемента по індексу")
#     print("6. Вихід\n")

# def main():
#     string_num = input("Введіть числа через пробіл: ")
#     numbers = string_num.split()
#     numbers = [int(number) for number in numbers]
#     while True:
#         menue()
#         choice = input("Оберіть опцію: ")
#         if choice == "1":
#             print("Список:", numbers)
#         elif choice == "2":
#             if numbers:
#                 print("Максимальне значення:", max(numbers))
#             else:
#                 print("Список пуст")
#         elif choice == "3":
#             if numbers:
#                 print("Мінімальне значення:", min(numbers))
#             else:
#                 print("Список порожній")
#         elif choice == "4":
#             if numbers:
#                 try:
#                     index = int(input("Введіть індекс елемента: "))
#                     print("Значення елементу по індексу", index, ": буде", numbers[index])
#                 except IndexError:
#                     print("Помилка: Індекс знаходиться за межами діапазону списку")
#             else:
#                 print("Список порожній")
#         elif choice == "5":
#             if numbers:
#                 try:
#                     index = int(input("Введіть індекс елемента для видалення: "))
#                     del numbers[index]
#                     print("Елемент успішно видалено")
#                 except IndexError:
#                     print("Помилка: Індекс знаходиться за межами діапазону списку")
#             else:
#                 print("Список порожній")
#         elif choice == "6":
#             print("До побачення!")
#             break
#         else:
#             print("Невірний вибір")

# if __name__ == "__main__":
#     main()




# # Завдання 4. Реализуйте третье задание через функции. Создайте две версии реализации функции:
# # Вся обработка находится снаружи функции; Обработка внутри функции.

# def display_menu():
#     print("\nМеню:")
#     print("1. Відображення списку")
#     print("2. Отримання максимального значення")
#     print("3. Отримання мінімального значення")
#     print("4. Отримання значення елемента по індексу")
#     print("5. Видалення елемента по індексу")
#     print("6. Вихід\n")

# def max_value(lst):
#     return max(lst)

# def min_value(lst):
#     return min(lst)

# def element_index(lst, index):
#     return lst[index]

# def del_element_index(lst, index):
#     del lst[index]
#     print("Елемент успішно видалено")

# def main():
#     string_num = input("Введіть числа через пробіл: ")
#     numbers = string_num.split()
#     numbers = [int(number) for number in numbers]
#     while True:
#         display_menu()
#         choice = input("Виберіть опцію: ")
#         if choice == '1':
#             print("Список:", numbers)
#         elif choice == '2':
#             if numbers:
#                 print("Максимальне значення:", max_value(numbers))
#             else:
#                 print("Список порожній")
#         elif choice == '3':
#             if numbers:
#                 print("Мінімальне значення:", min_value(numbers))
#             else:
#                 print("Список порожній")
#         elif choice == '4':
#             if numbers:
#                 index = int(input("Введіть індекс елемента: "))
#                 print("Значення елемента:", element_index(numbers, index))
#             else:
#                 print("Список порожній")
#         elif choice == '5':
#             if numbers:
#                 index = int(input("Введіть індекс елемента для видалення: "))
#                 del_element_index(numbers, index)
#             else:
#                 print("Список порожній")
#         elif choice == '6':
#             print("До побачення!")
#             break
#         else:
#             print("Невірний вибір")

# if __name__ == "__main__":
#     main()



# def menue():
#     print("\nМеню:")
#     print("1. Відображення списку")
#     print("2. Отримання максимального значення")
#     print("3. Отримання мінімального значення")
#     print("4. Отримання значення елемента по індексу")
#     print("5. Видалення елемента по індексу")
#     print("6. Вихід\n")

# def max_value(lst):
#     return max(lst)

# def min_value(lst):
#     return min(lst)

# def element_index(lst, index):
#     try:
#         return lst[index]
#     except IndexError:
#         raise IndexError("Невірний індекс")

# def del_element_index(lst, index):
#     try:
#         del lst[index]
#         print("Елемент успішно видалено")
#     except IndexError:
#         raise IndexError("Невірний індекс")

# def main():
#     string_num = input("Введіть числа через пробіл: ")
#     numbers = string_num.split()
#     numbers = [int(number) for number in numbers]
#     while True:
#         menue()
#         choice = input("Виберіть опцію: ")
#         if choice == '1':
#             print("Список:", numbers)
#         elif choice == '2':
#             if numbers:
#                 print("Максимальне значення:", max_value(numbers))
#             else:
#                 print("Список порожній")
#         elif choice == '3':
#             if numbers:
#                 print("Мінімальне значення:", min_value(numbers))
#             else:
#                 print("Список порожній")
#         elif choice == '4':
#             if numbers:
#                 try:
#                     index = int(input("Введіть індекс елемента: "))
#                     print("Значення елемента:", element_index(numbers, index))
#                 except ValueError:
#                     print("Введіть ціле число для індексу")
#                 except IndexError as e:
#                     print("Помилка:", e)
#             else:
#                 print("Список порожній")
#         elif choice == '5':
#             if numbers:
#                 try:
#                     index = int(input("Введіть індекс елемента для видалення: "))
#                     del_element_index(numbers, index)
#                 except ValueError:
#                     print("Введіть ціле число для індексу")
#                 except IndexError as e:
#                     print("Помилка:", e)
#             else:
#                 print("Список порожній")
#         elif choice == '6':
#             print("До побачення!")
#             break
#         else:
#             print("Невірний вибір")

# if __name__ == "__main__":
#     main()