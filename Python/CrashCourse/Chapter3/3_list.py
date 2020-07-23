pages = ['first','second','third']
print(pages[-3].title())

preorder_games = ['TLOU2', 'Death Stranding',
'Cyberpunk 2077', 'Star Wars: Jedi']
#add elements to the end or insertion:
preorder_games.append("COD")
preorder_games.insert(0, 'MK 11')
#deleting by the index:
del preorder_games[0] 
#popping an elem in a list:
popped_game = preorder_games.pop() #last elem
print (preorder_games)
print (popped_game)
popped_game = preorder_games.pop(2) #by the index elem
print (preorder_games)
print (popped_game)
preorder_games.remove('TLOU2') #by the value
print (preorder_games)

