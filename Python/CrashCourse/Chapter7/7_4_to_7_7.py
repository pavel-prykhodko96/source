#7_4
# ~ toppings = []
# ~ while True:
    # ~ topping = input('Please add the topping to the pizza: ')
    # ~ if topping != 'quit':
        # ~ toppings.append(topping)
        # ~ print("Your pizza consists of: ")
        # ~ for value in toppings: 
            # ~ print("    " + value)
    # ~ else:
        # ~ break
    
#7_5
while True:
    age = input('Please enter you age: ')
    if age == 'quit':
        break
    else:
        age = int(age)
        if age < 3:
            price = 'free'
        elif age < 12:
            price = '12$'
        else:
            price = '15$'
        print('The cost of your movie ticket is ' + price)
        
