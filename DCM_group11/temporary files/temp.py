import tkinter
from ttkthemes import themed_tk as tk
from tkinter import Button, IntVar, ttk,messagebox, font

root = tk.ThemedTk()
root.set_theme('scidblue') #fitting themes: breeze, scidblue
root.title("3K04 app")

root.minsize(200, 200)

notebook = ttk.Notebook(root)
frame = ttk.Frame(notebook)
notebook.add(frame, text="tab 1")

l = ttk.Label(frame, text="this is a label")
l.pack(expand=False, fill='x')
ttk.Separator(frame, orient='horizontal').pack(expand=False, fill='x')

#frame.pack(expand=True, fill='both')
notebook.pack(expand=True, fill='both')


root.mainloop()