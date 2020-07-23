#6_4
dictionary = {
    'a': 1,
    'b': 2,
    'c': 3,
    'd': 2,
    'e': 1,
    'f': 4,
    'g': 5,
    'h': 4,
    }

for key, value in dictionary.items():
    print("The key: " + key +
        ", the value: " + str(value))
    
for key in dictionary.keys():
    print(key)

for value in sorted(set(dictionary.values())):
    print(value)
    
del dictionary

#6_5
rivers = {
    'Dnipro': 'Ukraine',
    'Nile': 'Egypt',
    'Yellowstone': 'USA',
    }
for river, country in rivers.items():
    print("The " + river + 
        " runs through " + country)
        
for river in rivers.keys():
    print(river)
for country in rivers.values():
    print(country)

#6_6
dictionary = {
    'a': 1,
    'b': 2,
    'c': 3,
    'd': 2,
    'e': 1,
    'f': 4,
    'g': 5,
    'h': 4,
    }
    
letters = ['a','l','m','s','e','k','z']
for letter in letters:
    if letter in dictionary.keys():
        print(letter + ' already has a value: ' + 
            str(dictionary[letter]))
    else:
        print(letter + ' needs a value!')













