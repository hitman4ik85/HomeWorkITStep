# # Завдання 1. До вже реалізованого класу «Автомобіль» додайте конструктор та 
# # необхідні перевантажені методи.

# class Car:
#     def __init__(self, model, year, manufacturer, engine_volume, color, price):
#         self.model = model
#         self.year = year
#         self.manufacturer = manufacturer
#         self.engine_volume = engine_volume
#         self.color = color
#         self.price = price

#     def info(self):
#         print("Модель:", self.model)
#         print("Рік випуску:", self.year)
#         print("Виробник:", self.manufacturer)
#         print("Об'єм двигуна:", self.engine_volume)
#         print("Колір:", self.color)
#         print("Ціна:", self.price,"$")

#     def set_price(self, new_price):
#         self.price = new_price

#     def change_color(self, new_color):
#         self.color = new_color

#     def increase_price(self, amount):
#         self.price += amount

#     def discount_price(self, discount_procent):
#         discount_price = self.price * (1 - discount_procent / 100)
#         return discount_price

#     def __str__(self):
#         return f"Виробник: {self.manufacturer}, Назва моделі: {self.model}, {self.year} р., Колір: {self.color}, Об'єм двигуна: {self.engine_volume}, Ціна: {self.price}$"

#     def __eq__(self, other):
#         return self.price == other.price

#     def __lt__(self, other):
#         return self.price < other.price

#     def __gt__(self, other):
#         return self.price > other.price
    
#     def __le__(self, other):
#         return self.price <= other.price

#     def __ge__(self, other):
#         return self.price >= other.price
    
#     def __add__(self, other):
#         if isinstance(other, int) or isinstance(other, float):
#             return self.price + other
#         else:
#             raise TypeError("Непідтримуваний тип операції для +: 'Aвтомобіль' та '{}'".format(type(other).__name__))

#     def __sub__(self, other):
#         if isinstance(other, int) or isinstance(other, float):
#             return self.price - other
#         else:
#             raise TypeError("Непідтримуваний тип операції для -: 'Aвтомобіль' та '{}'".format(type(other).__name__))

# car1 = Car("Toyota Prado", 2023, "Toyota", "5.0L", "Сірий", 80000)
# car2 = Car("Honda Civic", 2022, "Honda", "2.0L", "Червоний", 25000)

# print(car1)
# print(car2)
# print(car1 == car2)
# print(car1 < car2)
# print(car1 > car2)
# print(car1 <= car2)
# print(car1 >= car2)
# print(car1 + 5000)
# print(car2 - 5000)



# # Завдання 2. До вже реалізованого класу «Книга» додайте конструкторта необхідні перевантажені методи.

# class Book:
#     def __init__(self, title, year, publisher, genre, author, price):
#         self.title = title
#         self.year = year
#         self.publisher = publisher
#         self.genre = genre
#         self.author = author
#         self.price = price

#     def info(self):
#         print("Назва книги:", self.title)
#         print("Рік видання:", self.year, "р.")
#         print("Видавець:", self.publisher)
#         print("Жанр:", self.genre)
#         print("Автор:", self.author)
#         print("Ціна:", self.price, "грн")

#     def set_price(self, new_price):
#         self.price = new_price
#         print("\nЦіну успішно змінено!")

#     def __str__(self):
#         return f"Назва: {self.title}, Рік: {self.year}, Видавництво: {self.publisher}, Жанр: {self.genre}, Автор: {self.author}, Ціна: {self.price}"

#     def __eq__(self, other):
#         return self.title == other.title and self.author == other.author

#     def __lt__(self, other):
#         return self.price < other.price

#     def __gt__(self, other):
#         return self.price > other.price

#     def __le__(self, other):
#         return self.price <= other.price

#     def __ge__(self, other):
#         return self.price >= other.price

#     def __ne__(self, other):
#         return not self == other
    
#     def __add__(self, other):
#         if isinstance(other, int) or isinstance(other, float):
#             return self.price + other
#         else:
#             raise TypeError("Непідтримуваний тип операції для +: 'Книга' та '{}'".format(type(other).__name__))

#     def __sub__(self, other):
#         if isinstance(other, int) or isinstance(other, float):
#             return self.price - other
#         else:
#             raise TypeError("Непідтримуваний тип операції для -: 'Книга' та '{}'".format(type(other).__name__))


# book1 = Book("Війна і мир", 1869, "Видавництво", "Роман", "Лев Толстой", 500)
# book2 = Book("Анна Кареніна", 1877, "Видавництво", "Роман", "Лев Толстой", 450)
# print(book1)
# print(book2)

# print(book1 == book2)
# print(book1 != book2)
# print(book1 < book2)
# print(book1 > book2)
# print(book1 <= book2)
# print(book1 >= book2)
# print(book1 + 50)  
# print(book2 - 50)



# # Завдання 3. До вже реалізованого класу «Стадіон» додайте конструктор та необхідні перевантажені методи.
# class Stadion:
#     def __init__(self, name, opening_date, country, city, capacity):
#         self.name = name
#         self.opening_date = opening_date
#         self.country = country
#         self.city = city
#         self.capacity = capacity

#     def info(self):
#         print("Назва стадіону:", self.name)
#         print("Дата відкриття:", self.opening_date)
#         print("Країна:", self.country)
#         print("Місто:", self.city)
#         print("Місткість:", self.capacity, "місць")

#     def set_capacity(self, new_capacity):
#         self.capacity = new_capacity
#         print("\nКількість місць успішно змінено!")

#     def __str__(self):
#         return f"Назва стадіону: {self.name}, Дата відкриття: {self.opening_date}, Країна: {self.country}, Місто: {self.city}, Вмістимість: {self.capacity}"

#     def __eq__(self, other):
#         return (self.name, self.opening_date, self.country, self.city, self.capacity) == (other.name, other.opening_date, other.country, other.city, other.capacity)

#     def __lt__(self, other):
#         return self.capacity < other.capacity

#     def __gt__(self, other):
#         return self.capacity > other.capacity

#     def __le__(self, other):
#         return self.capacity <= other.capacity

#     def __ge__(self, other):
#         return self.capacity >= other.capacity

#     def __ne__(self, other):
#         return not self == other

#     def __add__(self, other):
#         if isinstance(other, int) or isinstance(other, float):
#             return self.capacity + other
#         else:
#             raise TypeError("Непідтримуваний тип операції для +: 'Стадіон' та '{}'".format(type(other).__name__))

#     def __sub__(self, other):
#         if isinstance(other, int) or isinstance(other, float):
#             return self.capacity - other
#         else:
#             raise TypeError("Непідтримуваний тип операції для -: 'Стадіон' та '{}'".format(type(other).__name__))

# stadium1 = Stadion("НСК Олімпійський", "12 вересня 1923", "Україна", "Київ", 70050)
# stadium2 = Stadion("Camp Nou", "24 вересня 1957", "Іспанія", "Барселона", 99354)
# print(stadium1)
# print(stadium2)

# print(stadium1 == stadium2)
# print(stadium1 != stadium2)
# print(stadium1 < stadium2)
# print(stadium1 > stadium2)
# print(stadium1 <= stadium2)
# print(stadium1 >= stadium2)
# print(stadium1 + 5000)
# print(stadium2 - 5000)