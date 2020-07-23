#FIRST VERSION

current_users = ["Liza", "Nastya", "Vika", "Roma",
 "Serezha", "Salazar"]
cur_users_intens = [user.lower() for user in current_users]
new_users = ["liza", "Eric", "Svyat", "Lord", "SALAZAR"]

for new_us in new_users:
    if new_us.lower() in cur_users_intens:
        print("The name " + new_us + " is already being used")
    else:
        print("This name is available")       

#SECOND VERSION

current_users = ["Liza", "Nastya", "Vika", "Roma",
 "Serezha", "Salazar"]
new_users = ["liza", "Eric", "Svyat", "Lord", "SALAZAR"]

for new_us in new_users:
    for cur_us in current_users:
        if new_us.lower() == cur_us.lower():
            print("The name " + new_us + " is already being used")
            is_used = True
    if not is_used:
        print("This name is available")
    is_used = False

