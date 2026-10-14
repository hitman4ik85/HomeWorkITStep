#----- Task 1 ----

libraryEnFr = {
    "Text": "SMS",
    "read": "lire",
    "cat": "chat",
    "candy": "bonbon",
    "watch": "montre",
    "copy": "copier",    
}
print(libraryEnFr)

libraryEnFr["cow"] = "vache"
print(libraryEnFr["read"])

del libraryEnFr["Text"]
print(libraryEnFr)

def newWord():
    enWord = input("Enter English word: ")
    frWord = input("Enter translate French word: ")
    libraryEnFr[enWord] = frWord

newWord()
print(libraryEnFr)


def find():
    findEnWord = input("Enter English word: ")
    for item in libraryEnFr.keys():
        if item == findEnWord:
            return print(f"{findEnWord} - translate to Fr: {libraryEnFr[item]}")
        
    print(f"No {findEnWord} in En-Fr library")
          
find()