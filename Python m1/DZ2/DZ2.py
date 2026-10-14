import random
# set – це множина, яка містить унікальні елементи.
# Створення двох списків випадкових чисел
list1 = [random.randint(1, 20) for _ in range(10)]
print("Список 1:", list1)
list2 = [random.randint(1, 20) for _ in range(10)]
print("Список 2:", list2)

# Всі елементи обох списків
combined_list = list1 + list2
print("\nВсі елементи обох списків:", combined_list)

# Елементи обох списків без повторень
unique_combined = list(set(combined_list))
print("Елементи обох списків без повторень:", unique_combined)

# Спільні елементи для двох списків
common_elements = list(set(list1) & set(list2))
print("Спільні елементи для двох списків:", common_elements)

# Унікальні елементи кожного списку
unique_list1 = list(set(list1) - set(list2))
print("Унікальні елементи першого списку:", unique_list1)
unique_list2 = list(set(list2) - set(list1))
print("Унікальні елементи другого списку:", unique_list2)

# Мінімальне та максимальне значення кожного списку
min_max_list1 = [min(list1), max(list1)]
print("Мінімальне та максимальне значення першого списку:", min_max_list1)
min_max_list2 = [min(list2), max(list2)]
print("Мінімальне та максимальне значення другого списку:", min_max_list2)

