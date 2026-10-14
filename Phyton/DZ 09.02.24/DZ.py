# # Завдання 1. Маємо два текстові файли. З'ясуйте, чи співпадають їхні рядки. Якщо ні,
# # то виведіть із файлу рядок, який не співпадає.

# with open('text1.txt', 'r') as file:
#     text1 = set(file.read().splitlines())
# with open('text2.txt', 'r') as file:
#     text2 = set(file.read().splitlines())

# uniq_text1 = text1 - text2
# uniq_text2 = text2 - text1

# if not uniq_text1 and not uniq_text2:
#     print("Рядки співпадають.")
# else:
#     if uniq_text1:
#         print("Рядки, які є в файлі text1, але відсутні в файлі text2:")
#         for line in uniq_text1:
#             print(line)
#     if uniq_text2:
#         print("Рядки, які є в файлі text2, але відсутні в файлі text1:")
#         for line in uniq_text2:
#             print(line)

# # Завдання 3. Маємо текстовий файл. Видаліть з нього останній рядок. 
# # Результат запишіть до іншого файлу.

# with open('text1.txt', 'r') as file:
#     lines = file.readlines()
# lines = lines[:-1]

# with open('text2.txt', 'w') as file:
#     file.writelines(lines)

# # Завдання 4. Маємо текстовий файл. Знайдіть довжину найдовшого рядка.

# with open('text1.txt', 'r') as file:
#     lines = file.readlines()
# max_line = max(lines, key=len)
# print(f"Найдовший рядок: {max_line}, та його довжина: {len(max_line)} символів")

# # Завдання 5. Маємо текстовий файл. Підрахуйте кількість заданого 
# # користувачем слова у ньому.

# search_word = input("Введіть слово для пошуку: ")

# with open('text1.txt', 'r') as file:
#     content = file.read()
# word_count = content.lower().split().count(search_word.lower())

# print(f"Кількість слова '{search_word}' у файлі, зустрічається: {word_count} раз(и)")

# # Завдання 6. Маємо текстовий файл. Знайдіть і замініть у ньому задане слово. 
# # Яке слово шукати і на яке змінювати - встановлюється користувачем.

# search_word = input("Введіть слово для пошуку: ")
# replace_word = input("Введіть слово для заміни: ")

# with open('text1.txt', 'r') as file:
#     content = file.read()
# new_content = content.replace(search_word, replace_word)

# with open('text1.txt', 'w') as file:
#     file.write(new_content)
# print(f"Слово '{search_word}', було замінено на '{replace_word}'.")






# file.print("aaaaaa")
# # Task 4.
# file = open("data.txt", "r", encoding="utf8")   # Для того щоб зчитувало укр/рус літери
# max = 0
# for line in file:
#     if len(line.replace("\n","")) > max:
#         max = len(line.replace("\n",""))
# print(f"Довжина найбільшого рядка = {max}")
# # Task 6.
# file = open("data.txt", "r", encoding="utf8")
# content = file.read

# new = int("Введіть слово для вставки: ")
# old = input("Введіть слово яке замінюємо: ")
# repContent = content.replace(old, new)
# file.close()
# file = open("data.txt", "w", encoding="utf8")
# file.write(repContent)