from tkinter import messagebox
import json
from serialcomm import findDevice
import threading as T
import time



def checkConnectionDaemon(button):
    global STATUS
    STATUS = 1
    while True:
        status = findDevice()
        if status == None:
            STATUS = 0
            return
    

def checkConnection(button):
    global STATUS
    t = T.Thread(target = checkConnectionDaemon, daemon=True, name="Monitor")
    if button["text"] == "Disconnect":
        t.start()
        if STATUS == 0:
            print("disconnected")
            return False
    

def changeButton(button, style):
    if button['text'] == "Connect":
        button.configure(text="Disconnect")
        style.configure('connectionImage.TFrame', background="green")
    else:
        button.configure(text="Connect")
        style.configure('connectionImage.TFrame', background="red")
    button.update()

def clearFrame(frame): #clear all existing widgets from tkinter frame
    try:
        for i in frame.winfo_children(): #iterating through widgets
            i.destroy()
    except:
        print('**CLEARFRAME ERROR')

def checkEmptyCredentials(username, password): #check if login info is blank
    if username == '' or password == '':
        return True

def checkInvalidChars(username):
    invalidStrs = ['&', '=', '_', '+', ',', '<', '>', 
        '..', '/', '\\', '\'', '"', '$', '\#', '!', 
        '(', ')', '*', ':', ';', '@', '[', ']', '^', 
        '`', '{', '|', '}', '~']

    for i in invalidStrs:
        if i in username:
            return False
    return True


def getParamVals(parameters, spin, widgets): #get new parameter values from GUI
    for i in parameters: #iterating through dictionary
        p = parameters[i]
        if p in widgets: #check that parameter is not blank
            print(p["Name"])
            cur = spin[p["Name"]].get() #get current value from GUI spinbox
            if float(cur) in p['Range']: #check if value is in acceptable range
                p["Value"] = float(cur)
            else:
                messagebox.showwarning("Parameter Editor", "Invalid Value for {}".format(p["Name"]))
                p["Value"] = None #reset current value to noneType

def updateParams(parameters, userinfo):
    with open(userinfo["filepath"], "w") as f: 
        f.write(json.dumps(parameters, indent=2))