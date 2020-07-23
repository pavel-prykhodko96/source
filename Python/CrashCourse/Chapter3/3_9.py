#3_4:
guests = ['Borya','Valik','Serega','Maks']
message_0 = 'Hello, ' + guests[0] + '! Please come to the dinner tomorrow at 5 p.m.'
message_1 = 'Hello, ' + guests[1] + '! Please come to the dinner tomorrow at 5 p.m.'
message_2 = 'Hello, ' + guests[2] + '! Please come to the dinner tomorrow at 5 p.m.'
message_3 = 'Hello, ' + guests[3] + '! Please come to the dinner tomorrow at 5 p.m.'
print(message_0)
print(message_1)
print(message_2)
print(message_3)

#3_5:
doesnt_appear = 'Valik'
print('Valik' + " can't come")

guests.remove(doesnt_appear)
guests.append('Nikita')
message_0 = 'Hello, ' + guests[0] + '! Please come to the dinner tomorrow at 5 p.m.'
message_1 = 'Hello, ' + guests[1] + '! Please come to the dinner tomorrow at 5 p.m.'
message_2 = 'Hello, ' + guests[2] + '! Please come to the dinner tomorrow at 5 p.m.'
message_3 = 'Hello, ' + guests[3] + '! Please come to the dinner tomorrow at 5 p.m.'
print(message_0)
print(message_1)
print(message_2)
print(message_3)
#3_6:
print("I have found a bigger dinner table")
guests.insert(0,'Kolya')
guests.insert(2,'Tolya')
guests.append("Olya")
print("There are " + str(len(guests)) + " guests to invite")
message_0 = 'Hello, ' + guests[0] + '! Please come to the dinner tomorrow at 5 p.m.'
message_1 = 'Hello, ' + guests[1] + '! Please come to the dinner tomorrow at 5 p.m.'
message_2 = 'Hello, ' + guests[2] + '! Please come to the dinner tomorrow at 5 p.m.'
message_3 = 'Hello, ' + guests[3] + '! Please come to the dinner tomorrow at 5 p.m.'
message_4 = 'Hello, ' + guests[4] + '! Please come to the dinner tomorrow at 5 p.m.'
message_5 = 'Hello, ' + guests[5] + '! Please come to the dinner tomorrow at 5 p.m.'
message_6 = 'Hello, ' + guests[6] + '! Please come to the dinner tomorrow at 5 p.m.'
print(message_0)
print(message_1)
print(message_2)
print(message_3)
print(message_4)
print(message_5)
print(message_6)
