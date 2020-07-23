#7_8 and 7_9
# ~ sandwich_orders = ['beacon', 'pastrami', 'cheesy', 
    # ~ 'chicken and pineapple', 'pastrami', 'pastrami']
# ~ finished_sandwiches = []

# ~ print('We have run out of pastrami')
# ~ while 'pastrami' in sandwich_orders:
    # ~ sandwich_orders.remove('pastrami')

# ~ while sandwich_orders:
    # ~ cur_sandw = sandwich_orders.pop()
    # ~ print('The ' + cur_sandw + ' has been made')
    # ~ finished_sandwiches.append(cur_sandw)

# ~ print('\nFinished sandwiches: ')
# ~ for sandwich in finished_sandwiches:
    # ~ print('\t' + sandwich)
    
#7_10
poll = {}
while True:
    name = input('What is your name?: ')
    place = input('If you could visit one place in ' +
        'the world, where would you go?: ')
    poll[name] = place
    answer = input('Would you like to ask someone else? (y/n): ')
    if answer != 'y':
        break
        
for name, place in poll.items():
    print(name + ' wants to visit ' + place)
