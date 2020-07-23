def display_message():
    """Just tells the information"""
    print('It is display_message() call!')

def favorite_book(book):
    """Tells the name of favorite book"""
    print('My favorite book is ' + book.title())
    
def shirt(text, size = 'M'):
    print('Your T-shirt created with "' + text +
        '" printed on it.\n    The size of T-shirt: "' + 
        size.upper() + '"')

def city_country(city, country):
    ret_val = city + ', ' + country
    return ret_val.title()
    
def make_album(artist, album, tracks_amount =''):
    total = {'artist': artist, 'album': album}
    if tracks_amount:
        total['track_amount'] = tracks_amount
    return total


print("if you want to quit enter the 'q'" +
    "\nif you don't want to enter the amount " + 
    "\nenter '0' or nothing after prompt")
while True:
    artist = input('artist: ')
    if artist == 'q':
        break
    album = input('album: ')
    if album == 'q':
        break
    amount = input('amount: ')
    if amount == 'q':
        break
    if amount and amount != '0':
        print(make_album(artist, album, amount))
    else:
        print(make_album(artist, album))
    
