#1-------------------------------------------------------------------
def displayVuvid():
    print(f'''"Don't let the noise of others' opinions
    drown out your own inner voice."
        Steve Jobs''')

displayVuvid()
#2-------------------------------------------------------------------
def displayEvenNumbers(start, end):
    for i in range(start, end + 1):
        if i % 2 == 0:
            print(i)

num1 = int(input("Введіть перше число: "))
num2 = int(input("Введіть друге число: "))
displayEvenNumbers(num1, num2)
#3-------------------------------------------------------------------
def drawSquare(size, symbol, isFilled):
    if isFilled:
        for i in range(size):
            print(symbol * size)
    else:
        print(symbol * size)
        for i in range(size - 2):
            print(symbol + " " * (size - 2) + symbol)
        if size > 1:
            print(symbol * size)
s = int(input("Введіть розмір квадрата: "))
sym = input("Введіть символ: ")

while True:
    filledInput = input("Заповнений квадрат? (True/False): ").strip().lower()
    if filledInput in ["true", "false"]:
        filled = filledInput == "true"
        break
    else:
        print("Помилка! Введіть тільки 'True' або 'False'.")

drawSquare(s, sym, filled)
#4-------------------------------------------------------------------
def minOfFive(a, b, c, d, e):
    return min(a, b, c, d, e)

x1 = int(input("Введіть перше число: "))
x2 = int(input("Введіть друге число: "))
x3 = int(input("Введіть третє число: "))
x4 = int(input("Введіть четверте число: "))
x5 = int(input("Введіть п’яте число: "))
print("Мінімальне число:", minOfFive(x1, x2, x3, x4, x5))
#5-------------------------------------------------------------------
def countDigits(num):
    return len(str(abs(num)))

number = int(input("Введіть число: "))
print("Кількість цифр:", countDigits(number))
#6-------------------------------------------------------------------
def isPalindrome(num):
    numStr = str(num)
    return numStr == numStr[::-1]

palNum = int(input("Введіть число: "))
print("Паліндром:", isPalindrome(palNum))
