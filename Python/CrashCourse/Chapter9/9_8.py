class User():
    """Stores users information"""
    def __init__(self, first_name, last_name, **info):
        self.first_name = first_name
        self.last_name = last_name
        self.full_name = first_name + " " + last_name
        self.info = info
        self.login_attempts = 0
    def describe_user(self):
        print("Name: " + self.full_name)
        if self.info:
            for key, value in self.info.items():
                print(key + ": " + value)
    def greet_user(self):
        print("We are glad to see you, " + self.full_name + "!")
    def increment_login_attempts(self):
        self.login_attempts += 1
    def reset_login_attempts(self):
        self.login_attempts = 0

class Admin(User):
    """Special kind of user"""
    def __init__(
            self, first_name, last_name, 
            *privileges, **info):
        super().__init__(first_name, last_name, **info)
        self.privileges = Privileges(*privileges)
    
class Privileges():
    """Specifies privileges of a user"""
    def __init__(self, *privileges):
        self.privileges = privileges
    def show(self):
        if self.privileges:
            print("Privileges:")
            for privilege in self.privileges:
                print("    " + privilege)
        else:
            print("No privileges")

admin = Admin("Admin", "Admin", "can add post", 
    "can delete post", age = "22", gender = "male")
admin.describe_user()
admin.privileges.show()
