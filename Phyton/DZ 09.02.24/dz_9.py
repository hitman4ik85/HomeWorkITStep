# Task 1
# file1 = 'file1.txt'
# file2 = 'file2.txt'

# with open(file1, 'r', encoding='utf-8') as file_1, open(file2, 'r', encoding='utf-8') as file_2:
#     lines_file_1 = file_1.readlines()
#     lines_file_2 = file_2.readlines()

#     diff_file_1 = [line for line in lines_file_1 if line not in lines_file_2]
#     diff_file_2 = [line for line in lines_file_2 if line not in lines_file_1]

# print(f'Lines that do not match in {file1}:')
# for line in diff_file_1:
#     print(line.strip())

# print(f'\nLines that do not match in {file2}:')
# for line in diff_file_2:
#     print(line.strip())



#Task 3
# source_file = 'source.txt'
# new_file = 'new.txt'


# with open(source_file, 'r', encoding='utf-8') as input_file:
#     lines = input_file.readlines()

# with open(new_file, 'w', encoding='utf-8') as output_file:
#     output_file.writelines(lines[:-1])

# print(f'The last line has been removed, and the result has been written to the file {new_file}.')

#Task 4
# file = 'text_file.txt'

# with open(file, 'r', encoding='utf-8') as text_file:
#     lines = text_file.readlines()

# longest_line = max(lines, key=len)

# length_of_longest_line = len(longest_line)

# print(f"The length of the longest line in the file {file}: {length_of_longest_line} characters.")


#Task 5
# file = 'text_file.txt'

# user_word = input("Enter the word to count in the file: ")

# with open(file, 'r', encoding='utf-8') as text_file:
#     content = text_file.read()

# word_count = content.lower().split().count(user_word.lower())

# print(f"The word '{user_word}' appears {word_count} times in the file {file}.")


#Task 6
# file = 'text_file.txt'

# search_word = input("Enter the word to search in the file: ")
# replace_word = input("Enter the word to replace it with: ")

# with open(file, 'r', encoding='utf-8') as text_file:
#     content = text_file.read()

# updated_content = content.replace(search_word, replace_word)

# with open(file, 'w', encoding='utf-8') as text_file:
#     text_file.write(updated_content)

# print(f"The word '{search_word}' has been replaced with '{replace_word}' in the file {file}.")