def read_contents(file_name):
    try:
        with open(file_name) as file_object:
            contents = file_object.read()
            print(contents)
    except FileNotFoundError:
        print("File " + file_name + " isn't found!")

file_names = ["cats.txt", "dogs.txt"]
for file_name in file_names:
    read_contents(file_name)
