#8_9
def show_m(list_m):
    for m in list_m:
        print(m)

def make_great(list_m):
    for n in range(len(list_m)):
        list_m[n] = "Great " + list_m[n]
        
def make_great_no_change(list_m):
    for n in range(len(list_m)):
        list_m[n] = "Great " + list_m[n]
    return list_m

magicians = ["Gendalf", "Saruman", "Dambldor", "Potter"]
new_mag = []
new_mag = make_great_no_change(magicians[:])
show_m(magicians)
show_m(new_mag)
make_great(magicians)
show_m(magicians)

