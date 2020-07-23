with open("book.txt") as file_obj:
    contents = file_obj.read()

print(contents.lower().count("the"))
