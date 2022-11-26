import serial
import serial.tools.list_ports
import json
import time
import struct
from tkinter import messagebox


def findDevice():
    with open(r"./data/pacemakerData.json", "r") as f:
        data = json.load(f)

    ports = serial.tools.list_ports.comports()
    if len(ports) == 0: 
        #messagebox("connect the thing")
        print("\n**********Device Not Connected************\n")
        return None

    for p in ports:
        if p.vid == data["Vendor ID"] and p.pid == data["Product ID"]:
            return p
    return None

def getParamData(userinfo):
    with open(userinfo["filepath"]) as f:
        parameters = json.load(f)
    return parameters

def sendData(ser, signalSet):
    ser.write(b'\x16' + b'\x55' + signalSet)

    messagebox.showinfo("Connect", "Parameters Sent!")

def recieveParams(ser, signalSet):
    print("enter")
    ser.write(b'\x16' + b'\x22' + signalSet) #start, sync, signal

    rec = {}
    print("read start")
    data = ser.read(64)
    print("read end")
    rec["MODE"] = struct.unpack("H", data[0:2])[0]
    rec["LRL"] = struct.unpack("H", data[2:4])[0]
    rec["URL"] = struct.unpack("H", data[4:6])[0]

    rec["AA"] = struct.unpack("d", data[6:14])[0]
    rec["VA"] = struct.unpack("d", data[14:22])[0]
    rec["APW"] = struct.unpack("d", data[22:30])[0]
    rec["VPW"] = struct.unpack("d", data[30:38])[0]
    rec["AS"] = struct.unpack("d", data[38:46])[0]
    rec["VS"] = struct.unpack("d", data[46:54])[0]

    rec["VRP"] = struct.unpack("H", data[54:56])[0]
    rec["ARP"] = struct.unpack("H", data[56:58])[0]
    rec["PVARP"] = struct.unpack("H", data[58:60])[0]
    rec["HYS"] = struct.unpack("H", data[60:62])[0]
    rec["RS"] = struct.unpack("H", data[62:64])[0]
    
    if len(rec) != 0:
        messagebox.showinfo("Connect", "Parameters Recieved!")
    else:
        messagebox.showinfo("Connect", "An error occured when reading from pacemaker")
    return rec

def makeSignalSet(mode, parameters):
    paramDict = {}

    modeNum = 0
    if mode == "AOO":
        modeNum = 1
    elif mode == "VOO":
        modeNum = 2
    elif mode == "AAI":
        modeNum = 3
    elif mode == "VVI":
        modeNum = 4

    paramDict["Mode"] = int(modeNum)

    signalSet = struct.pack("H", modeNum)
    print("Mode signal Set:", signalSet)

    for key in parameters.keys():
        p = parameters[key]
        n = p["Name"]
        val = p["Value"]
        print(n)
        if  n == "Atrial Pulse Amplitude" or n == "Ventricular Pulse Amplitude" or n == "Atrial Pulse Width" or n == "Ventricular Pulse Width" or n == "Atrial Sensitivity" or n == "Ventricular Sensitivity":
            if val == None:
                val = 0
            paramDict[n] = float(val)
            signalSet += struct.pack("d", float(val))
        else:
            if val == None:
                val = 0
            paramDict[n] = int(val)
            signalSet += struct.pack("H", int(val))
    print("Length of Signal Set:",len(signalSet))
    return signalSet




#########################################################################

def recieveSignal(ser, signalSet):
    print("enter")
    ser.write(b'\x16' + b'\x33' + signalSet) #start, sync, signal

    data = ser.read(64)

    atr = None
    vent = None

    atr = struct.unpack("d", data[0:8])[0]
    vent = struct.unpack("d", data[8:16])[0]

    return (atr, vent)

def sendParams(userinfo, mode):
    signalSet = makeSignalSet(mode, getParams(userinfo))
    with serial.Serial(findDevice().device, 115200) as ser:
        sendData(ser, signalSet)

def getParams(userinfo, mode):
    signalSet = makeSignalSet(mode, getParams(userinfo))
    try:
        with serial.Serial(findDevice().device, 115200, timeout = 5) as ser:
            r = recieveParams(ser, signalSet)  
    except:
        r = None
    return r



def main(userinfo, mode):
    '''
    device = findDevice()
    if device == None:
        print("Device not found")
        return
    print(device.description)
    '''

    parameters = getParamData(userinfo)

    signalSet = makeSignalSet(mode, parameters)

    '''
    with serial.Serial(device.device, 115200) as ser:
        print("Port open?", ser.is_open) #port is open
        print("SignalSet:", signalSet)
        sendData(ser, signalSet)
        #print("***Data sent")
        recieveData(ser, signalSet)
        print("***Data recieved")
    '''
    print(signalSet)

with open(r"./data/userpass.json", "r") as f:
    data = json.load(f)
data = data[0]

#main(data, "VOO")
