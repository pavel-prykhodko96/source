# ~ user_name = input("Please enter your name!\n>>> ")
# ~ with open("guest.txt", "w") as file_object:
    # ~ file_object.write(user_name + "\n")

# ~ while True:
    # ~ user_name = input("Please enter your name!\n>>> ")
    # ~ if user_name == "q":
        # ~ break
    # ~ print(user_name + ", nice to see you here!")
    # ~ with open("guest.txt", "a") as file_object:
        # ~ file_object.write(user_name + " visited the site!\n")
        
counter = 0
while True:
    response = input("Why do you like programming?\n>>> ")
    with open("guest.txt", "a") as file_object:
        file_object.write(str(counter) + " response: " 
            + response + "\n")
        counter += 1
