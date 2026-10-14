#1----------------------------------------------------------------------------
class Car:
    def __init__(self, model, year, manufacturer, engine_volume, color, price):
        self.__model = model
        self.__year = year
        self.__manufacturer = manufacturer
        self.__engine_volume = engine_volume
        self.__color = color
        self.__price = price

    @property
    def model(self):
        return self.__model

    @property
    def year(self):
        return self.__year

    @property
    def manufacturer(self):
        return self.__manufacturer

    @property
    def engine_volume(self):
        return self.__engine_volume

    @property
    def color(self):
        return self.__color

    @color.setter
    def color(self, new_color):
        self.__color = new_color
        print(f"Колір автомобіля змінено на {new_color}")

    @property
    def price(self):
        return self.__price

    @price.setter
    def price(self, new_price):
        if new_price > 0:
            self.__price = new_price
            print(f"Ціна автомобіля змінена на {new_price} грн")
        else:
            print("Ціна повинна бути більше 0!")

    def display(self):
        print(f"Модель: {self.__model}\nРік випуску: {self.__year}\nВиробник: {self.__manufacturer}")
        print(f"Об'єм двигуна: {self.__engine_volume} л\nКолір: {self.__color}\nЦіна: {self.__price} грн")

car1 = Car("Hyundai Accent", 2016, "Hyundai", 2.5, "Білий", 480000)
car1.display()

car1.color = "Сірий"
car1.price = 650000

car1.display()

#2----------------------------------------------------------------------------
class Book:
    def __init__(self, title, year, publisher, genre, author, price):
        self.__title = title
        self.__year = year
        self.__publisher = publisher
        self.__genre = genre
        self.__author = author
        self.__price = price

    @property
    def title(self):
        return self.__title

    @property
    def year(self):
        return self.__year

    @property
    def publisher(self):
        return self.__publisher

    @publisher.setter
    def publisher(self, new_publisher):
        self.__publisher = new_publisher
        print(f"Видавця змінено на {new_publisher}")

    @property
    def genre(self):
        return self.__genre

    @property
    def author(self):
        return self.__author

    @property
    def price(self):
        return self.__price

    @price.setter
    def price(self, new_price):
        if new_price > 0:
            self.__price = new_price
            print(f"Ціна книги змінена на {new_price} грн")
        else:
            print("Ціна повинна бути більше 0!")

    def display(self):
        print(f"Назва: {self.__title}\nРік видання: {self.__year}\nВидавець: {self.__publisher}")
        print(f"Жанр: {self.__genre}\nАвтор: {self.__author}\nЦіна: {self.__price} грн")

book1 = Book("Майстер та Маргарита", 1967, "АСТ", "Роман", "Михайло Булгаков", 350)
book1.display()

book1.publisher = "Мрія"
book1.price = 450

book1.display()

#3----------------------------------------------------------------------------
class Stadium:
    def __init__(self, name, opening_date, country, city, capacity):
        self.__name = name
        self.__opening_date = opening_date
        self.__country = country
        self.__city = city
        self.__capacity = capacity

    @property
    def name(self):
        return self.__name

    @name.setter
    def name(self, new_name):
        self.__name = new_name
        print(f"Назву стадіону змінено на {new_name}")

    @property
    def opening_date(self):
        return self.__opening_date

    @property
    def country(self):
        return self.__country

    @property
    def city(self):
        return self.__city

    @property
    def capacity(self):
        return self.__capacity

    @capacity.setter
    def capacity(self, new_capacity):
        if new_capacity > 0:
            self.__capacity = new_capacity
            print(f"Місткість стадіону змінено на {new_capacity} глядачів")
        else:
            print("Місткість повинна бути більше 0!")

    def display(self):
        print(f"Назва стадіону: {self.__name}\nДата відкриття: {self.__opening_date}\nКраїна: {self.__country}")
        print(f"Місто: {self.__city}\nМісткість: {self.__capacity} глядачів")

stadium1 = Stadium("Олімпійський", "2000-02-08", "Україна", "Суми", 50000)
stadium1.display()

stadium1.name = "Динамо"
stadium1.capacity = 70000

stadium1.display()