#1------------------------------------------------------------------------
with open("data.txt", "w", encoding="utf-8") as file:
    for i in range(1, 4):
        text = input(f"Введіть рядок {i}: ")
        file.write(text + "\n")
print("Рядки успішно записані у файл data.txt.")

#2------------------------------------------------------------------------
try:
    with open("data.txt", "r", encoding="utf-8") as file:
        lines = file.readlines()
        if len(lines) == 0:
            print("Файл порожній")
        else:
            print("Кожен другий рядок у файлі:")
            for i in range(1, len(lines), 2):
                print(lines[i].strip())
except FileNotFoundError:
    print("Файл data.txt не існує")

#3------------------------------------------------------------------------
with open("data.txt", "r", encoding="utf-8") as file, open("filtered.txt", "w", encoding="utf-8") as output:
    for line in file:
        if "Python" in line:
            output.write(line)

#4------------------------------------------------------------------------
file_name = input("Введіть ім'я файлу: ")

with open(file_name, "r", encoding="utf-8") as file, open("cleaned.txt", "w", encoding="utf-8") as output:
    for line in file:
        cleaned_line = ""
        for char in line:
            if not char.isdigit():
                cleaned_line += char
        output.write(cleaned_line)

#5------------------------------------------------------------------------
def generateWordStats(inputPath, outputPath):
    word_counts = {}

    with open(inputPath, "r", encoding="utf-8") as file:
        line = file.readline()
        while line:
            words = line.split()
            for word in words:
                word = word.strip(".,!?()[]{}").lower()
                word_counts[word] = word_counts.get(word, 0) + 1
            line = file.readline()

    sorted_words = sorted(word_counts.items(), key=lambda x: x[1], reverse=True)

    with open(outputPath, "w", encoding="utf-8") as file:
        count = 0
        for word, countWord in sorted_words:
            file.write(f"{word}: {countWord}\n")
            count += 1
            if count == 10:
                break

generateWordStats("log.txt", "word_stats.txt")

#6------------------------------------------------------------------------
with open("data.txt", "r", encoding="utf-8") as file:
    lines = file.readlines()

with open("reversed.txt", "w", encoding="utf-8") as file:
    for line in reversed(lines):
        file.write(line)

