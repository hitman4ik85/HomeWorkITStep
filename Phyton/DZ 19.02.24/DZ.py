# # Завдання 1. Реалізуйте клас "Автомобіль". Збережіть у класі: назву моделі, рік випуску, 
# # виробника, об'єм двигуна, колір машини, ціну. Реалізуйте методи класу для введення-виведення 
# # даних та інших операцій.

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
#         print("\nЦіну на авто успішно змінено!")

#     def change_color(self, new_color):
#         self.color = new_color
#         print("\nКолір успішно змінено!")

#     def increase_price(self, amount):
#         self.price += amount
#         print("\nЦіну успішно піднято на 1000 $")

#     def discount_price(self, discount_procent):
#         discount_price = self.price * (1 - discount_procent / 100)
#         print("\nЦіну успішно знижено!")
#         return discount_price
    

# car1 = Car("Toyota Prado", 2023, "Toyota", "5.0L", "Сірий", 80000)
# car1.info()

# car1.set_price(81000)
# print("Нова ціна:", car1.price,"$")

# car1.change_color("Чорний")
# print("Новий колір:", car1.color)

# car1.increase_price(1000)
# print("Нова ціна:", car1.price,"$")

# discount_procent = 10
# discounted_price = car1.discount_price(discount_procent)
# print(f"Ціна зі знижкою {discount_procent} % : {discounted_price} $")




# # Завдання 2. Реалізуйте клас "Книга". Збережіть у класі: назву книги, рік видання, видавця, 
# # жанр, автора, ціну. Реалізуйте методи класу для введення-виведення даних та інших операцій.

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
#         print("Рік видання:", self.year,"р.")
#         print("Видавець:", self.publisher)
#         print("Жанр:", self.genre)
#         print("Автор:", self.author)
#         print("Ціна:", self.price,"грн")

#     def set_price(self, new_price):
#         self.price = new_price
#         print("\nЦіну успішно змінено!")

# book1 = Book("Війна і мир", 1869, "Видавництво", "Роман", "Лев Толстой", 500)
# book1.info()

# book1.set_price(550)
# print("Нова ціна:", book1.price,"грн")




# # Завдання 3. Реалізуте клас "Стадіон". Збережіть у класі: назву стадіону, дату відкриття, 
# # країну, місто, місткість. Реалізуйте методи класу для введення-виведення даних та інших вперацій.

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
#         print("Місткість:", self.capacity,"місць")

#     def set_capacity(self, new_capacity):
#         self.capacity = new_capacity
#         print("\nКількість місць успішно змінено!")

# # Приклад використання класу
# stadium1 = Stadion("НСК Олімпійський", "12 вересня 1923", "Україна", "Київ", 70050)
# stadium1.info()

# stadium1.set_capacity(80000)
# print("Зміна на -", stadium1.capacity,"місць")