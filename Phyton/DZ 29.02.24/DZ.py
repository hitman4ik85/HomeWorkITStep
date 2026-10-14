# # Реалізувати класс Товар, містить інформацію про товар (Назва, країна виготовлення, категорія, ціна, та знижка)

# class Product:
#     def __init__(self, name, country, category, price, discount=0):
#         self.name = name
#         self.country = country
#         self.category = category
#         self.price = price
#         self.discount = discount

#     def get_price(self):
#         discount_price = self.price - (self.price * self.discount // 100)
#         return discount_price

#     def info_product(self):
#         print("Інформація про продукт:")
#         print("Назва:", self.name)
#         print("Країна виробництва:", self.country)
#         print("Категорія:", self.category)
#         print(f"Ціна:", self.price,"$")
#         print(f"Знижка:", self.discount,"%")
#         print(f"Ціна зі знижкою:", self.get_price(),"$")
#         print("")

# product1 = Product("Ноутбук", "Китай", "Електро-техніка", 12000, 10)
# product1.info_product()

# product2 = Product("Футболка", "Турція", "Одяг", 80, 5)
# product2.info_product()




# # Завдання 2. Створити класс Магазин, містить інформацію про магазин (Назва, адресса, та список товарів)

# class Product:
#     def __init__(self, name, country, category, price, discount=0):
#         self.name = name
#         self.country = country
#         self.category = category
#         self.price = price
#         self.discount = discount

#     def get_price(self):
#         discount_price = self.price - (self.price * self.discount // 100)
#         return discount_price

#     def info_product(self):
#         print("Інформація про продукт:")
#         print("Назва:", self.name)
#         print("Країна виробництва:", self.country)
#         print("Категорія:", self.category)
#         print(f"Ціна:", self.price,"$")
#         print(f"Знижка:", self.discount,"%")
#         print(f"Ціна зі знижкою:", self.get_price(),"$")


# class Store:
#     def __init__(self, name, address):
#         self.name = name
#         self.address = address
#         self.products = []

#     def add_product(self, product):
#         self.products.append(product)

#     def info_store(self):
#         print("Інформація про магазин:")
#         print("Назва:", self.name)
#         print("Адреса:", self.address)
#         print("Доступні продукти:")
#         for product in self.products:
#             print("-", product.name)
#         print("")


# store1 = Store("СуперМаркет", "вул. Харківська, 13")
# store2 = Store("Мода Стайл", "вул. Іллінська, 46")

# product1 = Product("Ноутбук", "Китай", "Електро-техніка", 12000, 10)
# product2 = Product("Футболка", "Турція", "Одяг", 80, 5)

# store1.add_product(product1)
# store2.add_product(product2)

# store1.info_store()
# store2.info_store()




# # Завдання 3. Створити методи: для перегляду цін товарів з урахуванням знижки, для зміни знижки, 
# # додавання нового товару для списку, видалення товару зі списку, перегляду інформації про товари магазину.

# class Product:
#     def __init__(self, name, country, category, price, discount=0):
#         self.name = name
#         self.country = country
#         self.category = category
#         self.price = price
#         self.discount = discount

#     def get_price(self):
#         discount_price = self.price - (self.price * self.discount // 100)
#         return discount_price

#     def info_product(self):
#         print("Інформація про продукт:")
#         print("Назва:", self.name)
#         print("Країна виробництва:", self.country)
#         print("Категорія:", self.category)
#         print(f"Ціна:", self.price,"$")
#         print(f"Знижка:", self.discount,"%")
#         print(f"Ціна зі знижкою:", self.get_price(),"$")

# class Store:
#     def __init__(self, name, address):
#         self.name = name
#         self.address = address
#         self.products = []

#     def add_product(self, product):
#         self.products.append(product)
#         print(f"Продукт", product.name, "додано до магазину.\n")

#     def remove_product(self, product_name):
#         for product in self.products:
#             if product.name == product_name:
#                 self.products.remove(product)
#                 print(f"Продукт", product_name, "видалено з магазину.")
#                 return
#         print(f"Продукт", product_name, "не знайдено в магазині.")

#     def product_info(self):
#         if not self.products:
#             print("В магазині немає доступних продуктів.")
#             return
#         print("Доступні продукти в магазині:")
#         for product in self.products:
#             product.info_product()
#             print()

#     def prices_with_discount(self):
#         if not self.products:
#             print("В магазині немає доступних продуктів.")
#             return
#         print("Ціни на продукти зі знижкою:")
#         for product in self.products:
#             print("Назва:", product.name)
#             print(f"Ціна зі знижкою:", product.get_price(),"$")
#             print()

#     def change_discount(self, product_name, new_discount):
#         for product in self.products:
#             if product.name == product_name:
#                 product.discount = new_discount
#                 print(f"Знижка на продукт", product_name, "змінена на", new_discount, "%")
#                 return
#         print(f"Продукт", product_name, "не знайдено в магазині.")


# store = Store("СуперМаркет", "вул. Харківська, 13")

# product1 = Product("Ноутбук", "Китай", "Електро-техніка", 12000, 10)
# product2 = Product("Футболка", "Турція", "Одяг", 80, 5)

# store.add_product(product1)
# store.add_product(product2)

# store.product_info()

# store.change_discount("Ноутбук", 15)
# store.prices_with_discount()

# store.remove_product("Футболка")
# store.product_info()








# # Теж саме домашнэ завдання тыльки робив Олег:

# class Goods:
#     def __init__(self, name, country, category, price, discount=0):
#         self.name = name
#         self.country = country
#         self.category = category
#         self.price = price
#         self.discount = discount

#     def showPrice(self):
#         print(self.price - (self.price * self.discount) // 100)

#     def getPrice(self):
#         return (self.price - (self.price * self.discount) // 100)

#     def changeDiscount(self, newValue):
#         self.discount = newValue

# class Shop:
#     def __init__(self, name, address, *products):
#         self.name = name
#         self.address = address
#         self.productsList = []

#         for item in products:
#             self.productsList.append(item)
    
#     def add(self, *products):
#         count = 0
#         for item in products:
#             self.productsList.append(item)
#             count += 1
#         print(f"До магазину {self.name} додано {count} товарів")

#     def changeDisc(self, name):
#         for item in self.productsList:
#             if name == item.name:
#                 newDisc = int(input("Введіть нову знижку у відсотках: "))
#                 item.changeDiscount(newDisc)
#                 return
            
#     def delProduct(self,name):
#         for item in self.productsList:
#             if name == item.name:
#                 self.productsList.remove(item)
#                 return
            
#     def showProducts(self):
#         for item in self.productsList:
#             print(f"{item.name}, country - {item.country}, price - {item.getPrice()}")

# prod1 = Goods("Umbrella", "China", "first", 400, 50)
# prod2 = Goods("Shoes", "Nepal", "second", 4000, 30)
# shop1 = Shop("Rozetka", "ADDRESS", prod1, prod2)
# shop1.showProducts()
# shop1.changeDisc("Shoes")
# prod3 = Goods("T-shirt", "USA", "third", 2400, 15)
# shop1.add(prod3)
# shop1.delProduct(prod1.name)
# shop1.showProducts()