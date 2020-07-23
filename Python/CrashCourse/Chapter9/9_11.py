import user

admin = user.Admin("Admin", "Admin", "can add post", 
    "can delete post", age = "22", gender = "male")
admin.describe_user()
admin.privileges.show()
