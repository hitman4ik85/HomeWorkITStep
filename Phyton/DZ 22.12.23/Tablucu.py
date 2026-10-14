print("Завдання №1")

# Два списки цілих заповнюються випадковими числами. Необхідно: 
# сформувати третій список, що містить елементи обох списків; 
# сформувати третій список, що містить елементи обох списків без повторів; 
# сформувати третій список, що містить елементи спільні для двох списків; 
# сформувати третій список, що містить тільки унікальні елементи кожного зі списків; 
# сформувати третій список, що містить тільки мінімальне та максимальне значення кожного зі списків.

import random

list1 = [random.randint(1, 10) for item in range(5)]
list2 = [random.randint(1, 10) for item in range(5)]

print("Список 1:", list1)
print("Список 2:", list2)

list3 = list1 + list2

print("Список 3: що містить елементи обох списків:", list3)

list3_unique = []

for item in list1 + list2:
    if (list1 + list2).count(item) == 1:
        list3_unique.append(item)

print("Список 3: що містить елементи обох списків без повторів:", list3_unique)

list3_spilne = []

for item in list1:
    if item in list2:
        list3_spilne.append(item)

print("Список 3: що містить елементи спільні для двох списків:", list3_spilne)

list3_unique_elements = []

for item in list1:
    if not item in list2 and not item in list3_unique_elements:
        list3_unique_elements.append(item)

for item in list2:
    if not item in list1 and not item in list3_unique_elements:
        list3_unique_elements.append(item)

print("Список 3: що містить тільки унікальні елементи кожного зі списків:", list3_unique_elements)

min1 = list1[0]
max1 = list1[0]
min2 = list2[0]
max2 = list2[0]

for item in list1:
    if item > max1:
        max1 = item
    if item < min1:
        min1 = item
for item in list2:
    if item > max2:
        max2 = item
    if item < min2:
        min2 = item

list3_min_max = [min1, max1, min2, max2]

print("Список 3: що містить тільки мінімальне та максимальне значення кожного зі списків", list3_min_max)
