import random
import tkinter as Tk
from itertools import count

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

plt.style.use('seaborn')
# values for first graph
x_vals = []
y_vals = []
# values for second graph
y_vals2 = []

index = count()
index2 = count()

def animate():
    # Generate values
    x_vals.append(next(index))
    y_vals.append(random.randint(0, 5))
    # Get all axes of figure
    ax1 = plt.gcf().get_axes()
    ax1 = ax1[0]
    # Clear current data
    ax1.cla()
    # Plot new data
    ax1.plot(x_vals, y_vals)


# GUI
root = Tk.Tk()
label = Tk.Label(root, text="Realtime Animated Graphs").pack()

# graph 1
canvas = FigureCanvasTkAgg(plt.gcf(), master=root)
canvas.get_tk_widget().pack()
# Create two subplots in row 1 and column 1, 2
plt.gcf().subplots(1, 1)
ani = FuncAnimation(plt.gcf(), animate, interval=500, blit=False)

Tk.mainloop()