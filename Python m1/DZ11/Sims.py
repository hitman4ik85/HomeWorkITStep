import random

brands_of_car = {
    "BMW": {"fuel": 100, "strength": 100, "consumption": 6},
    "Lada": {"fuel": 50, "strength": 40, "consumption": 10},
    "Volvo": {"fuel": 70, "strength": 150, "consumption": 8},
    "Ferrari": {"fuel": 80, "strength": 120, "consumption": 14}
}

job_list = {
    "Java developer": {"salary": 50, "gladness_less": 10},
    "Python developer": {"salary": 40, "gladness_less": 3},
    "C++ developer": {"salary": 45, "gladness_less": 25},
    "Rust developer": {"salary": 70, "gladness_less": 1}
}

hobby_list = {
    "reading": {"gladness": 5, "cost": 5},
    "painting": {"gladness": 7, "cost": 10},
    "playing music": {"gladness": 6, "cost": 8}
}

class Pet:
    def __init__(self, name):
        self.name = name

    def make_mess(self, home):
        if random.randint(1, 3) == 1:
            print(f"{self.name} made a mess at home!")
            home.mess += 5

    def cheer_up(self, human):
        print(f"{self.name} cheered up {human.name}!")
        human.gladness += 5

class Friend:
    def __init__(self, name):
        self.name = name

    def meet(self, human):
        print(f"{human.name} met with friend {self.name}")
        human.gladness += 7
        human.satiety -= 3

class Hobby:
    def __init__(self):
        self.hobbies = hobby_list
        self.selected = random.choice(list(self.hobbies))

    def do_hobby(self, human):
        print(f"{human.name} is doing hobby: {self.selected}")
        human.gladness += self.hobbies[self.selected]["gladness"]
        if random.randint(1, 2) == 1:
            print("Spent money on hobby materials")
            human.money -= self.hobbies[self.selected]["cost"]

class Job:
    def __init__(self, job_list):
        self.job = random.choice(list(job_list))
        self.salary = job_list[self.job]["salary"]
        self.gladness_less = job_list[self.job]["gladness_less"]

class Auto:
    def __init__(self, brand_list):
        self.brand = random.choice(list(brand_list))
        self.fuel = brand_list[self.brand]["fuel"]
        self.strength = brand_list[self.brand]["strength"]
        self.consumption = brand_list[self.brand]["consumption"]

    def drive(self):
        if self.strength > 0 and self.fuel >= self.consumption:
            self.fuel -= self.consumption
            self.strength -= 1
            return True
        else:
            print("Car can't move")
            return False

class House:
    def __init__(self):
        self.mess = 0
        self.food = 0

class Human:
    def __init__(self, name="Human", job=None, home=None, car=None):
        self.name = name
        self.job = job
        self.home = home
        self.car = car
        self.money = 100
        self.gladness = 50
        self.satiety = 50
        self.sick = False
        self.sick_days = 0
        self.pet = Pet("Rex")
        self.friend = Friend("Alex")
        self.hobby = Hobby()

    def get_home(self):
        self.home = House()

    def get_job(self):
        if self.car.drive():
            pass
        else:
            self.to_repair()
            return self.job
        self.job = Job(job_list)

    def get_car(self):
        self.car = Auto(brands_of_car)

    def eat(self):
        if self.home.food <= 0:
            self.shopping("food")
        else:
            if self.satiety >= 100:
                self.satiety = 100
                return
            self.satiety += 5
            self.home.food -= 5

    def work(self):
        if self.car.drive():
            pass
        else:
            if self.car.fuel < 20:
                self.shopping("fuel")
                return
            else:
                self.to_repair()
                return
        self.money += self.job.salary
        self.gladness -= self.job.gladness_less
        self.satiety -= 4

    def shopping(self, manage):
        if self.car.drive():
            pass
        else:
            if self.car.fuel < 20:
                manage = "fuel"
            else:
                self.to_repair()
                return

        if manage == "fuel":
            print("I bought fuel")
            self.money -= 100
            self.car.fuel += 100
        elif manage == "food":
            print("I bought food")
            self.money -= 50
            self.home.food += 50
        elif manage == "delicacies":
            print("Delicious!")
            self.gladness += 10
            self.satiety += 2
            self.money -= 15

    def chill(self):
        self.gladness += 10
        self.home.mess += 5

    def clean_home(self):
        self.gladness -= 5
        self.home.mess = 0

    def to_repair(self):
        self.car.strength += 100
        self.money -= 50

    def sleep(self):
        print("I decided to sleep to restore energy")
        self.gladness += 5
        self.satiety -= 3

    def donate(self, amount):
        if self.money >= amount:
            print(f"I donated {amount} money to help others")
            self.money -= amount
            self.gladness += 7
        else:
            print("Not enough money to donate")

    def exercise(self):
        print("Sport is life!")
        self.satiety -= 4
        self.gladness += 6

    def get_sick(self):
        print("Oh no, I feel sick 🤒")
        self.sick = True
        self.sick_days = 0
        self.gladness -= 7
        self.satiety -= 4

    def go_to_doctor(self):
        if self.money >= 50:
            print("Went to the doctor 💊")
            self.money -= 50
            self.sick = False
            self.sick_days = 0
            self.gladness += 5
        else:
            print("No money for doctor 😢")
            self.gladness -= 5

    def play_with_pet(self):
        self.pet.cheer_up(self)
        self.pet.make_mess(self.home)

    def visit_friend(self):
        self.friend.meet(self)

    def enjoy_hobby(self):
        self.hobby.do_hobby(self)

    def days_indexes(self, day):
        print(f"Day {day}".center(50, "-"))
        print(f"Name: {self.name}")
        print(f"Money: {self.money} | Satiety: {self.satiety} | Gladness: {self.gladness} | Sick: {self.sick}")
        print(f"Home: food {self.home.food} | mess {self.home.mess}")
        print(f"Car: {self.car.brand} | Fuel {self.car.fuel} | Strength {self.car.strength}")
        print("-" * 50)

    def is_alive(self):
        if self.gladness < 0:
            print("Depression...")
            return False
        if self.satiety < 0:
            print("Died from hunger...")
            return False
        if self.money < -500:
            print("Bankrupt...")
            return False
        return True

    def live(self, day):
        if self.is_alive() == False:
            return False
        if self.home is None:
            print("Set house")
            self.get_home()
        if self.car is None:
            self.get_car()
            print(f"I buy {self.car.brand}")
        if self.job is None:
            self.get_job()
            print(f"I don't have job, going to job {self.job.job} with salary {self.job.salary}")
        self.days_indexes(day)

        if self.sick:
            self.sick_days += 1
            if random.randint(1, 100) <= 50:
                self.go_to_doctor()
            else:
                print("Resting at home to recover... 🛌")
                if self.sick_days >= 5:
                    print("Recovered at home! 🎉")
                    self.sick = False
                    self.sick_days = 0

        dice = random.randint(1, 11)
        if self.satiety < 20:
            print("I go eat")
            self.eat()
        elif self.gladness < 20:
            if self.home.mess > 15:
                print("I can't rest need clean house(")
                self.clean_home()
            else:
                print("Let's chill")
                self.chill()
        elif self.money < 0:
            print("Start working")
            self.work()
        elif self.car.strength < 15:
            print("i need repair a car")
            self.to_repair()
        elif dice == 1:
            print("Let's chill")
            self.chill()
        elif dice == 2:
            print("Start working")
            self.work()
        elif dice == 3:
            print("Cleaning time")
            self.clean_home()
        elif dice == 4:
            print("Let's chill and eat delicacies")
            self.shopping(manage="delicacies")
        elif dice == 5:
            print("Time to exercise")
            self.exercise()
        elif dice == 6:
            print("Let's be kind and donate")
            self.donate(10)
        elif dice == 7:
            if not self.sick:
                self.get_sick()
            else:
                print("Already sick 😓")
        elif dice == 8:
            print("Visiting friend")
            self.visit_friend()
        elif dice == 9:
            print("Playing with pet 🐾")
            self.play_with_pet()
        elif dice == 10:
            print("Doing hobby!")
            self.enjoy_hobby()
        elif dice == 11:
            print("Sleeping... 💤")
            self.sleep()

nick = Human(name="Nick")
for day in range(1, 31):
    if nick.live(day) == False:
        break
