import pygal
import matplotlib.pyplot as plt
from die import Die

# Create two D6 dice.
die_1 = Die()
die_2 = Die()

# Make some rolls, and store results in a list.
results = []
for roll_num in range(1000):
    result = die_1.roll() + die_2.roll()
    results.append(result)
    
# Analyze the results.
frequencies = []
max_result = die_1.num_sides + die_2.num_sides
for value in range(1, max_result+1):
    frequency = results.count(value)
    frequencies.append(frequency)
    
    
# Visualize the results.
variants = list(range(1, max_result + 1))
plt.plot(variants, frequencies, linewidth=2)
plt.title('Results of rolling two D6 dice 1000 times.', fontsize=14) 
plt.xlabel("Variant", fontsize=14)
plt.ylabel("Frequency of Variant", fontsize=14)

plt.show()

x_values = list(range(1, 1001))
y_values = [x**2 for x in x_values]

hist = pygal.Bar()
hist.title = "Square Numbers"
hist.x_labels = [str(x) for x in x_values]
hist.x_title = "Value"
hist.y_title = "Square of Value"

hist.add('Square', y_values)
hist.render_to_file('dice_visual.svg')
