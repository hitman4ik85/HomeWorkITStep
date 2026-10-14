#1----------------------------------------------------------------
number = input("Введіть шестизначне число: ")

if len(number) == 6 and number.isdigit():
    first_part = int(number[0]) + int(number[1]) + int(number[2])
    second_part = int(number[3]) + int(number[4]) + int(number[5])

    if first_part == second_part:
        print(f"{number} - щасливе число")
    else:
        print(f"{number} - не є щасливим числом")
else:
    print("Помилка! Введіть шестизначне число.")

#2----------------------------------------------------------------
number = input("Введіть шестизначне число: ")

if len(number) == 6 and number.isdigit():
    number_swap = number[5] + number[4] + number[2] + number[3] + number[1] + number[0]
    print("Перетворене число:", number_swap)
else:
    print("Помилка! Введіть шестизначне число.")

#3----------------------------------------------------------------
month = int(input("Введіть номер місяця (1-12): "))

if 1 <= month <= 12:
    if month in [12, 1, 2]:
        print("Зима")
    elif month in [3, 4, 5]:
        print("Весна")
    elif month in [6, 7, 8]:
        print("Літо")
    else:
        print("Осінь")
else:
    print("Помилка! Введіть число від 1 до 12.")
