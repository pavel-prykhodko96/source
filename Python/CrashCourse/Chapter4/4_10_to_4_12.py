#4_10
# ~ elements = [1,2,3,4,5,6,8653,425,46,3563,35735734,]
# ~ print ("The first 3 elements are: " + str(elements[0:3]))
# ~ print ("The items from the middle are: " + str(elements[2:5]))
# ~ print ("The last 3 elements are: " + str(elements[-3:]))

#4_11
my_pizzas = ["havaian", "munchen", "texas", "zalupa"]
friends_pizzas = my_pizzas[:]
my_pizzas.append("cheesy")
friends_pizzas.append("carbonara")

print ("My favorite pizzas are: ")
for p in my_pizzas:
    print (p)
print ("\nMy friend's favorite pizzas are: ")
for p in friends_pizzas:
    print (p)
