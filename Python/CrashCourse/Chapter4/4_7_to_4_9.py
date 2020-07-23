values = [val for val in range(3,31,3)]
print (values)


cubes = []
for val in range(1,11):
    cubes.append(val**3)
for val in cubes:
    print(val)

cubes = [val**3 for val in range(1,11)]
for val in cubes:
    print(val)

