#1-------------------------------------------------------------------
def sumInRange(start, end):
    if start > end:
        start, end = end, start
    return sum(range(start, end + 1))

num1 = int(input("Введіть перше число: "))
num2 = int(input("Введіть друге число: "))

print("Сума чисел у діапазоні:", sumInRange(num1, num2))

#2-------------------------------------------------------------------
def productList(lst):
    result = 1
    for num in lst:
        result *= num
    return result

numbers = list(map(int, input("Введіть список чисел через пробіл: ").split()))
print("Добуток чисел у списку:", productList(numbers))

#3-------------------------------------------------------------------
findMin = lambda lst: min(lst)

numbers = list(map(int, input("Введіть список чисел через пробіл: ").split()))
print("Мінімальне число у списку:", findMin(numbers))

#4-------------------------------------------------------------------
def isPrime(num):
    if num < 2:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True

countPrimes = lambda lst: len(list(filter(isPrime, lst)))

numbers = list(map(int, input("Введіть список чисел через пробіл: ").split()))
print("Кількість простих чисел у списку:", countPrimes(numbers))

#5-------------------------------------------------------------------
removeElement = lambda lst, target: (lst.count(target), list(filter(lambda num: num != target, lst)))

numbers = list(map(int, input("Введіть список чисел через пробіл: ").split()))
targetNum = int(input("Введіть число для видалення: "))

deletedCount, newList = removeElement(numbers, targetNum)
print(f"Кількість видалених елементів: {deletedCount}")
print("Оновлений список:", newList)

#6-------------------------------------------------------------------
mergeLists = lambda lst1, lst2: lst1 + lst2

numbers1 = list(map(int, input("Введіть перший список чисел через пробіл: ").split()))
numbers2 = list(map(int, input("Введіть другий список чисел через пробіл: ").split()))

print("Об'єднаний список:", mergeLists(numbers1, numbers2))

#7-------------------------------------------------------------------
powerList = lambda lst, power: list(map(lambda num: num ** power, lst))

numbers = list(map(int, input("Введіть список чисел через пробіл: ").split()))
exp = int(input("Введіть степінь: "))

print("Список у заданому степені:", powerList(numbers, exp))
