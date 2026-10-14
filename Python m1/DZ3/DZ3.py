#1 --------------------------------------------------
import random

numbers = [random.randint(-10, 10) for i in range(10)]
print("Список:", numbers)

# Сума від'ємних чисел
sum_negative = 0
for i in range(len(numbers)):
    if numbers[i] < 0:
        sum_negative += numbers[i]

# Сума парних чисел
sum_even = 0
for i in range(len(numbers)):
    if numbers[i] % 2 == 0:
        sum_even += numbers[i]

# Сума непарних чисел
sum_odd = 0
for i in range(len(numbers)):
    if numbers[i] % 2 != 0:
        sum_odd += numbers[i]

# Добуток елементів з індексами, кратними 3
product_multiple_3 = 1
for i in range(len(numbers)):
    if i % 3 == 0:
        product_multiple_3 *= numbers[i]

# Добуток елементів між мінімальним і максимальним
min_index = numbers.index(min(numbers))
max_index = numbers.index(max(numbers))
if min_index > max_index:
    min_index, max_index = max_index, min_index

product_between_min_max = 1
for i in range(min_index + 1, max_index):
    product_between_min_max *= numbers[i]

# Сума елементів між першим і останнім додатними
first_pos, last_pos = -1, -1
for i in range(len(numbers)):
    if numbers[i] > 0:
        if first_pos == -1:
            first_pos = i
        last_pos = i

sum_between_pos = 0
if first_pos != -1 and first_pos != last_pos:
    for i in range(first_pos + 1, last_pos):
        sum_between_pos += numbers[i]

print("Сума від'ємних чисел:", sum_negative)
print("Сума парних чисел:", sum_even)
print("Сума непарних чисел:", sum_odd)
print("Добуток елементів з індексами кратними 3:", product_multiple_3)
print("Добуток елементів між мінімальним і максимальним:", product_between_min_max)
print("Сума елементів між першим і останнім додатними:", sum_between_pos)

#2 --------------------------------------------------
import random

numbers = [random.randint(-10, 10) for i in range(10)]
print("Список:", numbers)

even_numbers = []
odd_numbers = []
negative_numbers = []
positive_numbers = []

for i in range(len(numbers)):
    if numbers[i] % 2 == 0:
        even_numbers.append(numbers[i])
    if numbers[i] % 2 != 0:
        odd_numbers.append(numbers[i])
    if numbers[i] < 0:
        negative_numbers.append(numbers[i])
    if numbers[i] > 0:
        positive_numbers.append(numbers[i])

print("Парні числа:", even_numbers)
print("Непарні числа:", odd_numbers)
print("Від'ємні числа:", negative_numbers)
print("Додатні числа:", positive_numbers)

#3 --------------------------------------------------
strings = input("Введіть список рядків через кому: ").split(", ")

shortest = strings[0]
for i in range(len(strings)):
    if len(strings[i]) < len(shortest):
        shortest = strings[i]

print("Найкоротший рядок:", shortest)

#4 --------------------------------------------------
strings = input("Введіть список рядків через кому: ").split(", ")
letter = input("Введіть літеру: ")

filtered_strings = []
for i in range(len(strings)):
    if strings[i].startswith(letter):
        filtered_strings.append(strings[i])

print("Рядки, які починаються з", letter, ":", filtered_strings)

#5 --------------------------------------------------
strings = input("Введіть список рядків через кому: ").split(", ")

palindromes = []
for i in range(len(strings)):
    if strings[i] == strings[i][::-1]:
        palindromes.append(strings[i])

# Сортування за спаданням довжини (по уроках - циклом)
for i in range(len(palindromes)):
    for j in range(i + 1, len(palindromes)):
        if len(palindromes[i]) < len(palindromes[j]):
            palindromes[i], palindromes[j] = palindromes[j], palindromes[i]

print("Паліндроми:", palindromes)
