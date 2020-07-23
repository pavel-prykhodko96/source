import json

file_name = "dump_file.json"

try:
    with open(file_name, "r") as f_obj:
        number = json.load(f_obj)
except FileNotFoundError:
    number = input("Please enter your favorite number: ")
    with open(file_name, "w") as f_obj:
        json.dump(number, f_obj)  
else:
    print(number)       

    
