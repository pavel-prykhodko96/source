import json

file_name = "username.json"

def get_stored_name():
    """Returns the name only if it has been stored already"""
    try:
        with open(file_name, "r") as f_obj:
            username = json.load(f_obj)
    except FileNotFoundError:
        return None
    else:
        return username
    
def get_new_username():
    """Gets the name and finishes only if it obtained"""
    while True:
        username = input("Please enter your name: ")
        if username:
            break
        print("Try again.")
    with open(file_name, "w") as f_obj:
        json.dump(username, f_obj)
    return username
    
def greet_user():
    username = get_stored_name()
    if username:
        while True:
            answer = input("Is your name '" + username + "'?(y/n): ")
            if answer == "n":
                username = get_new_username()
                print("Nice to meet you, " + username)
                break
            elif answer == "y":
                print("Nice to see you again, " + username)
                break
            else:
                print("Please get the correct answer.")
    else:
        username = get_new_username()
        print("Nice to meet you, " + username)

         
                
greet_user()
