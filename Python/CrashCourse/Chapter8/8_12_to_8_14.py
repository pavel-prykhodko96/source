#8_12
def summary(*ingredients):
    print("Sandwich consists of: ")
    for ingr in ingredients:
        print(" - " + ingr)
        
summary('beacon', 'cheese', 'onion', 'tomato')
summary('chicken', 'pineapple', 'cucumber')
summary('beaf', 'tomato', 'cucumber', 'chili')

#8_13 = 8_14
def user_profile(first_n, last_n, **other_info):
    profile = {
        "first_name": first_n,
        "last name": last_n}
    for key, val in other_info.items():
        profile[key] = val
    return profile

print(user_profile(
    "Pavlo", "Prykhodko", birth="20.09.1996", 
    education="bachelor of biology"
    ))

