#6_7
# ~ my_friend_01 = {
    # ~ 'first_name': 'Tina',
    # ~ 'second_name': 'Krasilyik',
    # ~ 'age': 25,
    # ~ 'city': 'Kharkiv',
    # ~ }
# ~ my_friend_02 = {
    # ~ 'first_name': 'Vova',
    # ~ 'second_name': 'Dopira',
    # ~ 'age': 22,
    # ~ 'city': 'Kiyv',
    # ~ }
# ~ my_friend_03 = {
    # ~ 'first_name': 'Sasha',
    # ~ 'second_name': 'Topcheva',
    # ~ 'age': 22,
    # ~ 'city': 'Praga',
    # ~ }
# ~ people = [my_friend_01, my_friend_02, my_friend_03]
# ~ for friend in people:
    # ~ print(
        # ~ "Full name: " + friend['first_name'] + 
        # ~ ' ' + friend['second_name'] +
        # ~ "\n\tAge: " + str(friend['age']) + 
        # ~ "\n\tCity: " + friend['city']
        # ~ )

#6_8
# ~ Gans = {'name': 'Gans',
    # ~ 'kind': 'dog',
    # ~ 'owner': 'Pasha',
    # ~ }
# ~ Filya = {'name': 'Filya',
    # ~ 'kind': 'cat',
    # ~ 'owner': 'Anya',
    # ~ }
# ~ Lensi = {'name': 'Lensi',
    # ~ 'kind': 'dog',
    # ~ 'owner': 'Mila',
    # ~ }
# ~ pets = [Gans, Filya, Lensi]

# ~ for pet in pets:
    # ~ print('_____________________')
    # ~ for key, val in pet.items():
        # ~ if key != 'name':
            # ~ print('\t' + key + ': ' + val)
        # ~ else:
            # ~ print(key + ': ' + val)

#6_9
# ~ favorite_places = {
    # ~ 'Nastya': ['den', 'cave', 'beach'],
    # ~ 'Kolya': ['cave'],
    # ~ 'Valik': ['hole', 'safari', 'sea'],
    # ~ }
# ~ for name, places in favorite_places.items():
    # ~ if len(places) > 1:
        # ~ print(name + "'s favorite places are: ")
    # ~ else:
        # ~ print(name + "'s favorite place is: ")
    # ~ for place in places:
        # ~ print('\t' + place)
            
#6_10
# ~ favorite_numbers = {
    # ~ 'Vadik': [28, 2, 89, 1],
    # ~ 'Liza': [13, 77, 90, 9],
    # ~ 'Eric': [1, 3],
    # ~ 'Vika': [7],
    # ~ 'Oksana': [22, 78, 90, 8, 65],
    # ~ }
# ~ print("Vadik's favorite number is: " + str(favorite_numbers['Vadik']))
# ~ print("Liza's favorite number is: " + str(favorite_numbers['Liza']))
# ~ print("Eric's favorite number is: " + str(favorite_numbers['Eric']))
# ~ print("Vika's favorite number is: " + str(favorite_numbers['Vika']))
# ~ print("Oksana's favorite number is: " + str(favorite_numbers['Oksana']))

#6_11
# ~ cities = {
    # ~ 'Kyiv': {
        # ~ 'country': 'Ukraine',
        # ~ 'population': 3000000,
        # ~ 'fact': 'the capital of Ukraine',
        # ~ },
    # ~ 'Berlin': {
        # ~ 'country': 'Germany',
        # ~ 'population': 2000000,
        # ~ 'fact': 'the capital of Germany',
        # ~ },
    # ~ 'Munchen': {
        # ~ 'country': 'Germany',
        # ~ 'population': 500000,
        # ~ 'fact': 'known by tasty sausages',
        # ~ },
    # ~ }
# ~ for city, info in cities.items():
    # ~ print(city + ':')
    # ~ for key, value in info.items():
        # ~ print('    ' + key.title() + ': ' + str(value))




















