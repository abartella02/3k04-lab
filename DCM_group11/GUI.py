import json
from helpers import *
import os
import serialcomm
from connectioncheck import main as checkConnected

import tkinter
from ttkthemes import themed_tk as tk
from tkinter import Button, IntVar, ttk,messagebox, font

#note to self: for multilanguage support, https://pypi.org/project/translate/

#note to self: add confirmation message popup to "delete user" section

def mainPage(userinfo):
    clearFrame(masterFrame)
    root.minsize(330, 320)

    notebook = ttk.Notebook(masterFrame) #notebook widget for tabs
    notebook.pack(expand=True, fill='both')

    paramTab = ttk.Frame(notebook) #parameters tab
    notebook.add(paramTab, text="Parameters")

    mainTab = ttk.Frame(notebook) #general tab
    notebook.add(mainTab, text="General")

    #General tab widgets
    statusFrame = ttk.Frame(mainTab)

    connectionLabel = ttk.Label(statusFrame, text="Connection Status: ")


    imageStyle = ttk.Style(mainTab)
    imageStyle.configure('connectionImage.TFrame', background="red")

    connectButton = ttk.Button(
        mainTab, 
        text="Connect",
        command=lambda:[
            #messagebox.showinfo("Connect", "{}ion Successful".format(connectButton['text'])),
            changeButton(connectButton, imageStyle),
            checkConnected(connectButton, imageStyle),
            print("(Dis)Connection Successful")
        ]
        )
    
    connectionImage = ttk.Frame( #connection status indicator
        statusFrame, 
        style="connectionImage.TFrame"
        )
    
    #placing widgets on main page
    statusFrame.grid(row=0, column=0, sticky='NESW')
    connectionLabel.grid(row=0, column=0)
    connectionImage.grid(row=0, column=1, ipadx=5, ipady=5, padx=3, pady=3)

    connectButton.grid(row=1, column=0)
    paramFrame = ttk.Frame(paramTab)

    optionsFrame = ttk.Frame(paramTab)
    options = ["Select a mode", "AOO", "VOO", "AAI", "VVI"]
    value = tkinter.StringVar(optionsFrame)
    dropdown = ttk.OptionMenu(optionsFrame, 
        value,
        *options
        )
    optionsFrame.grid(row=0, column=0, sticky='w')
    dropdown.grid(row=0, column=0, sticky='w')
    paramFrame.grid(row=1, column=0)
    

    currentMode = ""
    optionButton = ttk.Button(optionsFrame,
        text="Select",
        command=lambda: (
            currentMode := value.get(),
            spawnParams(currentMode, paramFrame, userinfo)
            )
    )
    optionButton.grid(row=0, column=1, sticky='w', ipadx=4)

    sendButton = ttk.Button( #send data button
    mainTab, 
    text="Send Data to Pacemaker",
    command=lambda:[
        messagebox.showinfo("Connect", "Parameters Sent!"),
        serialcomm.send(userinfo, currentMode)
    ]
    )
    sendButton.grid(row=2, column=0)

    getButton = ttk.Button( #send data button
    mainTab, 
    text="Get Data from Pacemaker",
    command=lambda:[
        messagebox.showinfo("Connect", "Parameters Sent!"),
        temp := serialcomm.get(userinfo, currentMode),
        print(json.dumps(temp, indent=1))
    ]
    )
    getButton.grid(row=3, column=0)

def spawnParams(currentMode, frame, userinfo):
    clearFrame(frame)
    with open(userinfo["filepath"], "r") as f:
        parameters = json.load(f)

    with open(r"./data/modes.json", "r") as f:
        modes = json.load(f)

    try:
        reqParams = modes[currentMode]
    except:
        messagebox.showerror("Error", "Invalid Mode!!!")
        return

    widgets = []
    for paramKey in reqParams:
        widgets.append(parameters[paramKey])
        
    spin = {}
    row = 2
    for p in widgets:
        if p != None:
            spinbox = ttk.Spinbox(frame, #create spinbox widget
                values=p['Range']
                )
            spin[p["Name"]] = spinbox
            if not p["Value"]:
                spinbox.insert(0, p["Default"])
            else:
                spinbox.insert(0, p["Value"])
            spinbox.grid(row=row, column=1, padx=5, pady=5)
            ttk.Label(frame, #create label widget for spinbox
                text="{} ({})".format(p["Name"], p["Units"]), 
                font=("Calibri, 10")
                ).grid(row=row, column=0, padx=5, pady=5, sticky="w")
            row+=1
    
    newdict = parameters.copy()

    applyButton = ttk.Button(frame, #"apply" button at bottom of page
        text="Apply",
        command=lambda: [
            getParamVals(parameters, spin, widgets), #collect values inside spinbox widgets (see otherfuncs.py)
            print("Parameters Applied"),
            updateParams(newdict, userinfo)
            ]
        )
    applyButton.grid(row=row, column=1, padx=5, pady=5, ipadx=10)


def deleteAccount(username):
    #note to self: require enter password for selected username
    print('entered delete account') ##
    with open(r"./data/userpass.json", "r") as f: #get usernames and passwords from json file
        print('opened file')
        data = json.load(f)
    for index, object in enumerate(data): #iterating through login information
        if object['username'] == username: #searching for selected username
            print('found') ##
            filepath = object['filepath']
            os.remove(filepath)
            data.pop(index) #deleting specified login info

    with open(r"./data/userpass.json", "w") as f: 
        f.write(json.dumps(data, indent=2)) #updating json file
    
    if not username == '':
        messagebox.showinfo("Delete user", "User \"{}\" has been deleted.".format(username)) #confirmation message
    else:
        messagebox.showwarning("Delete user", "No account was selected.")


def newAccount(username, password):
    print('entered create account') ##
    with open(r"./data/userpass.json", "r") as f: #get existing login info from json file
        print('opened file') ##
        data = json.load(f)

    filepath = r"./data/userdata/{}.json".format(username)
    with open(filepath, "w") as userfile: #create new template for data
        with open(r"./data/parametersBlank.json") as template:
            userfile.write(json.dumps(json.load(template), indent=2))

    data.append({'username':username, 'password':password, 'filepath':filepath}) #adding new username and password

    with open(r"./data/userpass.json", "w") as f: 
        f.write(json.dumps(data, indent=2)) #updating json file
    print('new user created:', username)  ##

def maxUsersReached():
    popup = tk.ThemedTk() #new window
    popup.set_theme(theme)
    popup.title("Max Users Reached!")
    frame = ttk.Frame(popup)
    frame.pack(anchor='c', fill='both', expand=True)
    popup.minsize(250, 130)

    header = ttk.Label(
        frame, 
        text="Maximum Users Reached!", 
        font="Calibri, 16"
        )
    header.grid(row = 0, column=0, padx=5)
    subheader = ttk.Label(
        frame, 
        text="Select a user to delete",
        font="Calibri, 12"
    )
    subheader.grid(row=1, column=0)

    selectedUser = tkinter.StringVar(frame) #initializing selected user var
    with open(r"./data/userpass.json", "r") as f: #get login info from json file
        data = json.load(f)

    optionFrame = ttk.Frame(frame) #frame to contain account selection
    optionFrame.grid(row=2, column=0)

    optionStyle = ttk.Style(optionFrame)
    optionStyle.configure("option.TRadiobutton", font="Calibri 12") ####
    
    #iterating through login info to display options
    row=0
    for loginInfo in data:
        user = loginInfo['username']
        print(user) ##
        ttk.Radiobutton(
            optionFrame, 
            style="option.TRadiobutton", ####
            text=user, 
            var=selectedUser, 
            value = user
            ).grid(row=row, column=0, sticky='w')
        row+=1

    buttonFrame = ttk.Frame(frame) #frame for delete button
    
    deleteButton = ttk.Button(
        buttonFrame, 
        text="Delete", 
        command=lambda: [
            print("Now deleting:"+selectedUser.get()+"**"), ##
            deleteAccount(selectedUser.get()), #delete selected user (see otherfuncs.py)
            popup.destroy() #close window
            ]
        )
    cancelButton = ttk.Button( #abort deleteAccount()
        buttonFrame,
        text="Cancel",
        command=lambda: popup.destroy() #close window
    )
    buttonFrame.grid(column=0, row=3, pady=(2,5))
    deleteButton.grid(column=0, row=0, padx=2, ipadx=7)
    cancelButton.grid(column=1, row=0, padx=2, ipadx=7)


def login(userEnter, passEnter): #login button command
    if checkEmptyCredentials(userEnter, passEnter): #see otherfuncs.py
        messagebox.showwarning("Login", "Enter a valid Username and Password.")
        return
    userEnter = userEnter.lower()
    passEnter = passEnter.lower()
    print('Success') ##
    userPassFound = False
    with open(r"./data/userpass.json", "r") as f:
        data = json.load(f) #get login info from json file
    for userinfo in data:
        if userinfo['username'].lower() == userEnter and userinfo['password'].lower() == passEnter: #search for matching username AND password
            userPassFound = True #login info found
            messagebox.showinfo("Login", "Login Successful!")
            mainPage(userinfo) #go to mainpage
            return
    if not userPassFound: 
        messagebox.askretrycancel("Login", "Login Unsuccessful.\nUsername or password not found.\nPlease Try Again.")


def createNewUser(userEnter, passEnter): #new user button command
    if checkEmptyCredentials(userEnter, passEnter) and checkInvalidChars(userEnter): #see otherfuncs.py
        messagebox.showwarning("Login", "Enter a Username and Password.")
        return 
    userEnter = userEnter.lower()
    passEnter = passEnter.lower()
    UserAlreadyExists = False
    with open(r"./data/userpass.json", "r") as f:
        data = json.load(f) #get login info from json file
    for i in data: #iterate through login info to check if user already exists
        if i['username'].lower() == userEnter:
            UserAlreadyExists = True
            messagebox.askretrycancel("New User", "Username already exists!")
            return
    if not UserAlreadyExists:
        if len(data) >= maxUsers: #ensure max users is not reached
            maxUsersReached()
        else:
            newAccount(userEnter, passEnter) #append to login info json file
            messagebox.showinfo("New User", "New User Added!")

    
def loginPage(): #login page
    clearFrame(masterFrame) #remove all widgets from frame
    frame = ttk.Frame(masterFrame)
    frame.pack(padx=0, pady=0)

    titleLabel = ttk.Label(frame, text="Login", font="Calibri 20")

    userLabel = ttk.Label(frame, text="Username: ", font="Calibri 16")
    passLabel = ttk.Label(frame, text="Password: ", font = "Calibri 16")

    userBox = ttk.Entry(frame, font="Calibri 12") #username entry widget
    passBox = ttk.Entry(frame, show="*", font="Calibri 12") #password entry widget

    buttonFrame = ttk.Frame(frame) #frame for createnewuser and login buttons

    style.configure("enter.TButton", font=('Calibri', 12))
    loginButton = ttk.Button( #login button
        buttonFrame, 
        text="LOGIN", 
        style="enter.TButton", 
        command= lambda: login(userBox.get(), passBox.get()) #login function call
    )
    create = ttk.Button( #create new user button
        buttonFrame,
        text="CREATE NEW",
        style="enter.TButton",
        command= lambda: [
            createNewUser(userBox.get(), passBox.get()),
            login(userBox.get(), passBox.get())
        ] #new user function call
    )
    
    titleLabel.grid(row=0, column=0) #inserting widgets
    userLabel.grid(row=1, column=0, sticky='w')
    userBox.grid(row=2, column=0, sticky='w', ipadx=50)
    passLabel.grid(row=3, column=0, sticky='w')
    passBox.grid(row=4, column=0, sticky='w', ipadx=50)
    
    buttonFrame.grid(row=5, column=0)
    loginButton.grid(row=0, column=1, pady=(8, 0), padx=(3,0), ipadx=10)
    create.grid(row=0, column=0, pady=(8, 0), padx=(0,3), ipadx=10)

    root.minsize(300, 210)

def welcome(): #welcome page
    frame = ttk.Frame(masterFrame)
    frame.pack(padx=0, pady=0)

    titleLabel = ttk.Label(frame, text="Welcome", font="Calibri 25")
    subtitleLabel = ttk.Label(frame, text="3K04 Pacemaker Project", font="Calibri 14")
    style.configure("enter.TButton", font=('Calibri', 12))
    welcomeButton = ttk.Button(frame, 
        style="welcome.TButton", 
        text="Ok", 
        command=lambda: loginPage() #navigate to login page upon button press
        )
    
    titleLabel.pack() #inserting widgets
    subtitleLabel.pack(pady=(0, 5))
    welcomeButton.pack(ipadx=20, pady=(0, 4))

    root.minsize(230, 110)

def main():
    #instantiate global variables
    global root
    global style
    global masterFrame
    global maxUsers
    global theme
    maxUsers = 2
    #create tkinter window instance
    theme = "scidblue"
    root = tk.ThemedTk()
    root.set_theme(theme) #fitting themes: breeze, scidblue
    root.title("3K04 app")
    root.iconbitmap(r"./images/menghi.ico")
    style = ttk.Style()

    #create frame to size the window
    masterFrame = ttk.Frame(root)
    masterFrame.pack(fill='both', expand=True)
    welcome()

    root.mainloop()

main()