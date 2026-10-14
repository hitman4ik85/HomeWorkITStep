# Створіть програму "Англо-французький словник". Збережіть слово англійською 
# та його переклад на французьку. Реалізуйте можливість додавати, видаляти, 
# знаходити та змінювати дані. Використовуйте словник для збереження інформації.

library = {'hello': 'bonjour'}

def add_word():
    word = input("Введіть нове слово: ").lower()
    translation = input(f"Введіть переклад слова '{word}': ").lower()
    library[word] = translation
    print(f"Слово: '{word}' та його переклад: '{translation}' додані до словника.")

def delete_word():
    word = input("Введіть слово, яке потрібно видалити: ").lower()
    if word in library:
        del library[word]
        print(f"Слово: '{word}' та його переклад видалені зі словника.")
    else:
        print(f"Слово: '{word}' не знайдено у словнику.")

def find_word():
    word = input("Введіть слово, яке потрібно знайти: ").lower()
    if word in library:
        print(f"Переклад слова '{word}': {library[word]}")
    else:
        print(f"Слово: '{word}' не знайдено у словнику.")

def update_word():
    word = input("Введіть слово, яке потрібно оновити: ").lower()
    if word in library:
        new_translation = input(f"Введіть новий переклад для слова '{word}': ").lower()
        library[word] = new_translation
        print(f"Переклад слова: '{word}' оновлено на '{new_translation}'.")
    else:
        print(f"Слово: '{word}' не знайдено у словнику.")

def show_dictionary():
    print("\nПоточний словник:")
    for word, translation in library.items():
        print(f'Слово: {word} - Французькою: {translation}')

while True:
    print("\nВаріанти вибору:")
    print("1. Додати слово")
    print("2. Видалити слово")
    print("3. Знайти переклад")
    print("4. Оновити переклад")
    print("5. Показати словник")
    print("6. Вийти")

    
    choice = input("Ваш вибір: ")
    
    if choice == '1' or choice.lower() == 'додати слово' or choice.lower() == 'додати':
        add_word()
    elif choice == '2' or choice.lower() == 'видалити слово' or choice.lower() == 'видалити':
        delete_word()
    elif choice == '3' or choice.lower() == 'знайти переклад' or choice.lower() == 'знайти':
        find_word()
    elif choice == '4' or choice.lower() == 'оновити переклад' or choice.lower() == 'оновити':
        update_word()
    elif choice == '5' or choice.lower() == 'показати словник' or choice.lower() == 'показати':
        show_dictionary()
    elif choice == '6' or choice.lower() == 'вийти':
        print("Допобачення.")
        break
    else:
        print("Невірний вибір. Спробуйте ще раз.")