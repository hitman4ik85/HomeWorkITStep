# # Завдання 2. Написати гру "Бики і корови". Програма "загадує" чотиризначне число і гравекь має вгадати його. 
# # Після введення користувачем числа програма повідоиляє, скільки фиір числа вгадано (бики) і скільки цифр 
# # вгадано і стоїть на потрібному місці (корови). Після відгадування числа на екран необхідно вивести кількість 
# # спроб зроблених користувачем. У програмі необхідно викорисовувати рекурсію.

rand = 5555

def game(tries = 0):
    number = int(input("Введіть чотризначне число: "))
    idRand = []
    idNumber = []
    bulls = 0
    cows = 0
    id1 = 0
    for item in str(rand):
        id2 = 0
        for item2 in str(number):
            if item == item2 and id1 not in idRand and id2 not in idNumber:
                bulls+=1
                idRand.append(id1)
                idNumber.append(id2)
            if item == item2 and id1 == id2:
                cows+=1
            id2+=1
        id+=1
    if bulls == 4 and cows == 4:
        print(f"End Game tries = {tries}")
        return
    else:
        print(f"bulls = {bulls}, cows = {cows}")
        return game(tries + 1)
    
game()

