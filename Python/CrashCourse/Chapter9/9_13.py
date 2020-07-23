from collections import OrderedDict


dictionary = OrderedDict()
dictionary['a'] = 1
dictionary['b'] = 888
dictionary['c'] = 3
dictionary['d'] = 96
dictionary['e'] = 769
dictionary['f'] = 125
dictionary['g'] = 1002

for key, value in dictionary.items():
    print("The key: " + key +
        ", the value: " + str(value))
    
for key in dictionary.keys():
    print(key)

for value in sorted(set(dictionary.values())):
    print(value)
    
del dictionary
