import threading as T
import time
from tkinter import messagebox
from serial.tools.list_ports import comports
from helpers import changeButton

def checkConnection(button, style):
    #print("$$$ Daemon entered")
    if button['text'] == "Disconnect":
        while True:
            status = findDevice()
            if status == None:
                STATUS = 0
                #messagebox.showerror("Disconnected", "Disconnected")
                changeButton(button, style)
                #print("$$$ disconnected")
                return False
            else:
                #print("$$$ Connected")
                pass
            time.sleep(0.5)

def findDevice():
    ports = comports()
    
    if len(ports) == 0:
        return None
    else: 
        return 1


def main(button, style):
    global STATUS
    STATUS = 1
    t = T.Thread(target=lambda:checkConnection(button, style), daemon = True, name="Monitor")
    t.start()