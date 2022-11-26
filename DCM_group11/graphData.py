import threading as T
import time
import serialcomm

import tkinter
from ttkthemes import themed_tk as tk
from tkinter import Button, IntVar, ttk,messagebox, font

import random
from itertools import count

import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg as FigureCanvas
from functools import partial

def close():
    try:
        plt.close()
        root.destroy()
    except:
        print("Could not close graphData")

def animate(i, mode):
    xPts.append(next(index))
    vPts.append(random.randint(0, 5))
    aPts.append(random.randint(0, 5))
    if mode == 'ventricular':
        V_axis = (plt.gcf().get_axes())[0]
    elif mode == 'atrial':
        A_axis = (plt.gcf().get_axes())[0]
    elif mode == 'both':
        V_axis, A_axis = plt.gcf().get_axes()

    if mode == 'ventricular' or mode == 'both':
        V_axis.cla()
        V_axis.plot(xPts, vPts)
    if mode == 'atrial' or mode == 'both':
        A_axis.cla()
        A_axis.plot(xPts, aPts)
    
    


def display(mode):
    mode = mode.lower()
    #mode: "Ventricular", "Atrial", "Both"
    global xPts
    global vPts
    global aPts
    global index
    xPts = []
    vPts = []
    aPts = []
    index = count()

    global root
    global masterFrame
    theme = "scidblue"
    root = tk.ThemedTk()
    root.set_theme(theme) #fitting themes: breeze, scidblue
    root.title("EGram graphs")
    root.iconbitmap(r"./images/menghi.ico")
    style = ttk.Style()

    #create frame to size the window
    masterFrame = ttk.Frame(root)
    masterFrame.pack(fill='both', expand=True)
    masterFrame.pack_propagate(0)

    root.minsize(700,500)

    root.protocol("WM_DELETE_WINDOW", lambda:[
        close()
    ])

    plt.style.use("ggplot")
    plot1 = plt.gcf()
    canvas = FigureCanvas(plot1, master=masterFrame)
    canvas.get_tk_widget().pack()
    if mode == 'both':
        plot1.subplots(1,2)
    else:
        plot1.subplots(1,1)
    animatedPlot = FuncAnimation(plot1, partial(animate, mode=mode), interval=500, blit=False)
    root.mainloop()
