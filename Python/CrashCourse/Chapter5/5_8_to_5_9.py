#5_8 
users = ["admin", "Kostya", "Rita", "Sanyok", "Liza"]
if users:
    for user in users:
        if user == "admin":
            print("Hello, admin! Would you like to see the report?")
        else:
            print("Hello, " + user + "! Thank you for logging again!")
else:
    print("There are no users on the site logged")
