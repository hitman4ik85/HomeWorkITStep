#1-----------------------------------------------------------------------
class Number:
    def __init__(self, value):
        self.value = value

    def __add__(self, other):
        return Number(self.value + other.value)

    def __sub__(self, other):
        return Number(self.value - other.value)

    def __mul__(self, other):
        return Number(self.value * other.value)

    def __truediv__(self, other):
        return Number(self.value / other.value)

    def __str__(self):
        return f"Number: {self.value}"

n1 = Number(10)
n2 = Number(5)
print(n1 + n2)
print(n1 - n2)
print(n1 * n2)
print(n1 / n2)

#2-----------------------------------------------------------------------
class Drib:
    def __init__(self, chuselnuk, znamennuk):
        if znamennuk == 0:
            raise ValueError("Знаменник не може бути 0")
        self.chuselnuk = chuselnuk
        self.znamennuk = znamennuk

    def __add__(self, other):
        ch = self.chuselnuk * other.znamennuk + other.chuselnuk * self.znamennuk
        zn = self.znamennuk * other.znamennuk
        return Drib(ch, zn)

    def __sub__(self, other):
        ch = self.chuselnuk * other.znamennuk - other.chuselnuk * self.znamennuk
        zn = self.znamennuk * other.znamennuk
        return Drib(ch, zn)

    def __mul__(self, other):
        return Drib(self.chuselnuk * other.chuselnuk, self.znamennuk * other.znamennuk)

    def __truediv__(self, other):
        return Drib(self.chuselnuk * other.znamennuk, self.znamennuk * other.chuselnuk)

    def __str__(self):
        return f"{self.chuselnuk}/{self.znamennuk}"

f1 = Drib(3, 4)
f2 = Drib(2, 5)
print(f1 + f2)
print(f1 - f2)
print(f1 * f2)
print(f1 / f2)

#3-----------------------------------------------------------------------
class Library:
    def __init__(self, name, address, books_count):
        self.name = name
        self.address = address
        self.books_count = books_count

    def __add__(self, value):
        return Library(self.name, self.address, self.books_count + value)

    def __sub__(self, value):
        return Library(self.name, self.address, self.books_count - value)

    def __iadd__(self, value):
        self.books_count += value
        return self

    def __isub__(self, value):
        self.books_count -= value
        return self

    def __gt__(self, other): return self.books_count > other.books_count
    def __lt__(self, other): return self.books_count < other.books_count
    def __ge__(self, other): return self.books_count >= other.books_count
    def __le__(self, other): return self.books_count <= other.books_count
    def __eq__(self, other): return self.books_count == other.books_count
    def __ne__(self, other): return self.books_count != other.books_count

    def display(self):
        print(f"Library: {self.name}\nAddress: {self.address}\nBooks: {self.books_count}")

lib1 = Library("Centralna", "Sumy Rd", 1000)
lib2 = Library("Shevchenka", "Sumy St", 800)

lib1 += 200
lib1.display()

lib2 = lib2 + 100
lib2.display()

print(lib1 > lib2)
print(lib1 == lib2)

#4-----------------------------------------------------------------------
import datetime

class Date:
    def __init__(self, day, month, year):
        self.date = datetime.date(year, month, day)

    def display(self):
        print(f"Дата: {self.date}")

    def __sub__(self, other):
        return abs((self.date - other.date).days)

    def __add__(self, days):
        new_date = self.date + datetime.timedelta(days=days)
        return Date(new_date.day, new_date.month, new_date.year)

d1 = Date(10, 3, 2024)
d2 = Date(25, 3, 2024)

print("Різниця у днях:", d2 - d1)
d3 = d1 + 10
d3.display()