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
        
class IceCreamStand(Restaurant):
    """Specific kind of a restaurant"""
    def __init__(self, name, cuisine_type, *flavors):
        super().__init__(name, cuisine_type)
        self.flavors = flavors
    def show_flavors(self):
        for f in self.flavors:
            print(f)
            
ics = IceCreamStand(
    "abc", "small", "vanil", "chocolate",
    "strawberry", "pineapple")
ics.show_flavors()
