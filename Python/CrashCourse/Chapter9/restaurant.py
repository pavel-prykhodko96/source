"""Restaurant realization"""

class Restaurant():
    def  __init__(self, name, cuisine_type):
        self.name = name
        self.cuisine_type = cuisine_type
        self.number_surved = 0
    def describe_restaurant(self):
        print(self.name + " " + self.cuisine_type)
    def open_restaurant(self):
        print("restaurant is opened")
    def set_number_surved(self, number):
        self.number_surved = number
    def increment_number_surved(self, number):
        self.number_surved += number
