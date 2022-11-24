import json
from helpers import *
import os

import tkinter
from ttkthemes import themed_tk as tk
from tkinter import Button, IntVar, ttk,messagebox, font

selectedMode = "VVI"

with open(r"./data/parametersBlank.json", "r") as f:
    parameters = json.load(f)

with open(r"./data/modes.json", "r") as f:
    modes = json.load(f)

for mode in modes.keys():
    pass

try:
    reqParams = modes[selectedMode]
except:
    pass

widgets = []
for paramKey in reqParams:
    widgets.append(parameters[paramKey])