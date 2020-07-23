phrase = '"if you love pivko, \n\tyou will be a great person"'
author_name = " \t\nJohn Lennon\n\n\n\n\n\n   "
total_message = "\n\t" + author_name + " once said, " + phrase
print (total_message)

# ~ author_name = author_name.rstrip()
total_message = "\n\t" + author_name.rstrip() + " once said, " + phrase
print (total_message)

total_message = "\n\t" + author_name.lstrip() + " once said, " + phrase
print (total_message)

total_message = "\n\t" + author_name.strip() + " once said, " + phrase
print (total_message)
