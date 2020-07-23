from random import randint

class Die():
    def __init__(self, sides=6):
        self.sides = sides
    def roll_die(self):
        side = randint(1, self.sides)
        print(str(side))
        
die_six = Die()
print("Rolling of 6-sided die")
for n in range(10):
    die_six.roll_die()
    
die_ten = Die(10)
print("Rolling of 10-sided die")
for n in range(20):
    die_ten.roll_die()
