#1------------------------------------------------------------------
try:
    num1 = float(input("Введіть перше число: "))
    num2 = float(input("Введіть друге число: "))
    result = num1 / num2
    print(f"Результат: {result}")
except ValueError:
    print("Помилка: введене значення не є числом!")
except ZeroDivisionError:
    print("Помилка: ділення на нуль неможливе!")
finally:
    print("Операція завершена.")

#2------------------------------------------------------------------
myList = [10, 20, 30, 40, 50]

try:
    index = int(input("Введіть індекс елемента: "))
    print(f"Елемент за індексом {index}: {myList[index]}")
except ValueError:
    print("Помилка: введене значення не є числом!")
except IndexError:
    print("Помилка: індекс виходить за межі списку!")
finally:
    print("Операція завершена.")

#3------------------------------------------------------------------
try:
    sales = list(map(float, input("Введіть продажі через пробіл: ").split()))
    total = sum(sales)
    print(f"Загальна сума продажів: {total}")
except ValueError:
    print("Помилка: некоректне введення, введіть тільки числа!")
finally:
    print("Обробку завершено.")

#4------------------------------------------------------------------
import math

try:
    num = float(input("Введіть число: "))
    if num < 0:
        raise Exception("Не можна обчислити квадратний корінь від'ємного числа")
    print(f"Квадратний корінь: {math.sqrt(num)}")
except ValueError:
    print("Помилка: введене значення не є числом!")
except Exception as e:
    print(f"Помилка: {e}")
finally:
    print("Обчислення завершено.")

#5------------------------------------------------------------------
try:
    product_data = input("Введіть товар у форматі: назва, ціна, кількість: ")
    name, price, quantity = product_data.split(", ")
    price = float(price)
    quantity = int(quantity)
    print(f"Назва: {name}, Ціна: {price}, Кількість: {quantity}")
except ValueError:
    print("Помилка: некоректний формат даних! Ціна має бути числом, а кількість цілим числом.")
finally:
    print("Парсинг завершено.")

#6------------------------------------------------------------------
import random

def connect_to_server():
    if random.choice([True, False]):
        return "Підключення успішне"
    else:
        raise ConnectionError("Помилка підключення")
try:
    print(connect_to_server())
except ConnectionError:
    print("Не вдалося підключитися до сервера")
finally:
    print("Спробу завершено.")

