languages = ["c++",  "c", "java", "assembler",
"python", "c#", "f", "perl", "scala", "html", "css"]

languages.append("pascal")
languages.insert(3, "ruby")
languages.remove("html")
del languages[-2]
best_lang = languages.pop(0)

print("There are " + str(len(languages)) + " in the list")
print("The best language is " + best_lang.title())

print(sorted(languages))
