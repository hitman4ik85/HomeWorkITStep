#1------------------------------------------------------------------------
class Device:
    def __init__(self, brand, power):
        self.brand = brand
        self.power = power

    def display(self):
        print(f"Brand: {self.brand}")
        print(f"Power: {self.power}W")

class CoffeeMachine(Device):
    def __init__(self, brand, power, coffee_type):
        super().__init__(brand, power)
        self.coffee_type = coffee_type

    def display(self):
        super().display()
        print(f"Coffee type: {self.coffee_type}")

    def make_coffee(self):
        print(f"Making {self.coffee_type} coffee... ☕")

class Blender(Device):
    def __init__(self, brand, power, speed_levels):
        super().__init__(brand, power)
        self.speed_levels = speed_levels

    def display(self):
        super().display()
        print(f"Speed levels: {self.speed_levels}")

    def blend(self):
        print("Blending ingredients... 🥤")

class MeatGrinder(Device):
    def __init__(self, brand, power, blade_type):
        super().__init__(brand, power)
        self.blade_type = blade_type

    def display(self):
        super().display()
        print(f"Blade type: {self.blade_type}")

    def grind_meat(self):
        print("Grinding meat... 🍖")

c = CoffeeMachine("DeLonghi", 1200, "Espresso")
b = Blender("Philips", 600, 5)
m = MeatGrinder("Bosch", 800, "Stainless Steel")

c.display()
c.make_coffee()
print("-" * 30)
b.display()
b.blend()
print("-" * 30)
m.display()
m.grind_meat()

#2------------------------------------------------------------------------
class Ship:
    def __init__(self, name, crew_size):
        self.name = name
        self.crew_size = crew_size

    def display(self):
        print(f"Ship name: {self.name}")
        print(f"Crew size: {self.crew_size}")

class Frigate(Ship):
    def __init__(self, name, crew_size, missiles):
        super().__init__(name, crew_size)
        self.missiles = missiles

    def display(self):
        super().display()
        print(f"Missiles onboard: {self.missiles}")

class Destroyer(Ship):
    def __init__(self, name, crew_size, torpedoes):
        super().__init__(name, crew_size)
        self.torpedoes = torpedoes

    def display(self):
        super().display()
        print(f"Torpedoes onboard: {self.torpedoes}")

class Cruiser(Ship):
    def __init__(self, name, crew_size, armor_level):
        super().__init__(name, crew_size)
        self.armor_level = armor_level

    def display(self):
        super().display()
        print(f"Armor level: {self.armor_level}")

f = Frigate("Freedom", 200, 24)
d = Destroyer("Thunder", 250, 16)
c = Cruiser("Invincible", 300, "Heavy")

f.display()
print("-" * 30)
d.display()
print("-" * 30)
c.display()

#3------------------------------------------------------------------------
class Money:
    def __init__(self, major, minor):
        self.major = major      # гривні / долари / євро
        self.minor = minor      # копійки / центи

    def display(self):
        print(f"{self.major} грн {self.minor:02} коп")

    def set_value(self, major, minor):
        self.major = major
        self.minor = minor

class Product(Money):
    def __init__(self, name, major, minor):
        super().__init__(major, minor)
        self.name = name

    def display(self):
        print(f"Product: {self.name}")
        super().display()

    def discount(self, grn, kop):
        total_cents = self.major * 100 + self.minor
        discount_cents = grn * 100 + kop
        new_total = total_cents - discount_cents
        if new_total < 0:
            new_total = 0
        self.major = new_total // 100
        self.minor = new_total % 100

p = Product("Chocolate", 25, 50)
p.display()
print("Applying discount: 5 грн 75 коп")
p.discount(5, 75)
p.display()

