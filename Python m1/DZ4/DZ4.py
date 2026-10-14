#1---------------------------------------------------------
import random

tuple1 = tuple(random.randint(1, 10) for i in range(6))
tuple2 = tuple(random.randint(1, 10) for i in range(6))
tuple3 = tuple(random.randint(1, 10) for i in range(6))

print("Кортеж 1:", tuple1)
print("Кортеж 2:", tuple2)
print("Кортеж 3:", tuple3)

common_elements = set(tuple1) & set(tuple2) & set(tuple3)

print("Елементи, які є у всіх кортежах:", tuple(common_elements))

#2---------------------------------------------------------
import random

tuple1 = tuple(random.randint(1, 10) for i in range(6))
tuple2 = tuple(random.randint(1, 10) for i in range(6))
tuple3 = tuple(random.randint(1, 10) for i in range(6))

print("Кортеж 1:", tuple1)
print("Кортеж 2:", tuple2)
print("Кортеж 3:", tuple3)

unique_tuple1 = set(tuple1) - set(tuple2) - set(tuple3)
unique_tuple2 = set(tuple2) - set(tuple1) - set(tuple3)
unique_tuple3 = set(tuple3) - set(tuple1) - set(tuple2)

print("Унікальні елементи у першому кортежі:", tuple(unique_tuple1))
print("Унікальні елементи у другому кортежі:", tuple(unique_tuple2))
print("Унікальні елементи у третьому кортежі:", tuple(unique_tuple3))

#3---------------------------------------------------------
import random

tuple1 = tuple(random.randint(1, 10) for i in range(6))
tuple2 = tuple(random.randint(1, 10) for i in range(6))
tuple3 = tuple(random.randint(1, 10) for i in range(6))

print("Кортеж 1:", tuple1)
print("Кортеж 2:", tuple2)
print("Кортеж 3:", tuple3)

same_position_elements = []

for i in range(len(tuple1)):
    if tuple1[i] == tuple2[i] == tuple3[i]:
        same_position_elements.append(tuple1[i])

print("Елементи, які є у всіх кортежах на однакових позиціях:", tuple(same_position_elements))
