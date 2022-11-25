import serial
import serial.tools.list_ports
import json
import time
import struct


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

def getParams(userinfo):
    with open(userinfo["filepath"]) as f:
        parameters = json.load(f)
    return parameters

def sendData(ser, signalSet):
    ser.write(b'\x16' + b'\x55' + signalSet)

def recieveData(ser, signalSet):
    print("enter")
    ser.write(b'\x16' + b'\x22' + signalSet) #start, sync, signal

    rec = {}
    a = None
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
    ser.close()
    print("Port open?", ser.is_open)

    for key in rec.keys():
        print(key, rec[key])

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
    #bModeNum = '{}'.format(modeNum)
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
    print("ssssssss",len(signalSet))
    return signalSet

def main(userinfo, mode):
    device = findDevice()
    if device == None:
        print("Device not found")
        return
    print(device.description)

    parameters = getParams(userinfo)

    signalSet = makeSignalSet(mode, parameters)

    #print(paramDict)
    #print(signalSet)
    #strParamList = str(paramList).encode("utf-8")
    #print("Byte array:", strParamList)

    with serial.Serial(device.device, 115200) as ser:
        print("Port open?", ser.is_open) #port is open
        print("SignalSet:", signalSet)
        sendData(ser, signalSet)
        #print("***Data sent")
        recieveData(ser, signalSet)
        print("***Data recieved")

    print("Port open?", ser.is_open)

with open(r"./data/userpass.json", "r") as f:
    data = json.load(f)
data = data[0]


main(data, "VOO")

