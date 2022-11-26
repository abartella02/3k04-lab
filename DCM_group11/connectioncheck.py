import threading as T
import time
from tkinter import messagebox
from serial.tools.list_ports import comports
from helpers import changeButton

def checkConnection(button, style, frame):
    #print("$$$ Daemon entered")
    if button['text'] == "Disconnect":
        while True:
            status = findDevice()
            if status == None:
                STATUS = 0
                #messagebox.showerror("Disconnected", "Disconnected")
                changeButton(button, style, frame)
                #print("$$$ disconnected")
                return False
            else:
                #print("$$$ Connected")
                pass
            time.sleep(0.5)

def findDevice():
    ports = comports()
    targetPort = 0
    for port in ports:
        #print("Serial Number", port.serial_number)
        if str(port.serial_number) == "000000123456":
            #print("Serial Device Found")
            targetPort = port
            break
        else:
            targetPort = 0
    
    if targetPort != 0:
        return 1
    else: 
        return None


def main(button, style, frame):
    global STATUS
    STATUS = 1
    t = T.Thread(target=lambda:checkConnection(button, style, frame), daemon = True, name="Monitor")
    t.start()