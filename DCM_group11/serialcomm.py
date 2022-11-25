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
    ser.write(b'\x16\x55'+signalSet)

def recieveData(ser, signalSet):
    print("enter")
    ser.write(b'\x16\x22'+signalSet) #start, sync, signal

    rec = {}
    a = None
    print("read start")
    data = ser.read(63)
    print("read end")
    rec["MODE"] = data[0]
    rec["LRL"] = struct.unpack("H", data[1:3])[0]
    rec["URL"] = struct.unpack("H", data[3:5])[0]

    rec["AA"] = struct.unpack("d", data[5:13])[0]
    rec["VA"] = struct.unpack("d", data[13:21])[0]
    rec["APW"] = struct.unpack("d", data[21:29])[0]
    rec["VPW"] = struct.unpack("d", data[29:37])[0]
    rec["AS"] = struct.unpack("d", data[37:45])[0]
    rec["VS"] = struct.unpack("d", data[45:53])[0]

    rec["VRP"] = struct.unpack("H", data[53:55])[0]
    rec["ARP"] = struct.unpack("H", data[55:57])[0]
    rec["PVARP"] = struct.unpack("H", data[57:59])[0]
    rec["HYS"] = struct.unpack("H", data[59:61])[0]
    rec["RS"] = struct.unpack("H", data[61:63])[0]
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

    paramDict["Mode"] = (int(modeNum))
    #bModeNum = '{}'.format(modeNum)
    signalSet = bytes(str(modeNum).encode())
    print("Mode signal Set:", str(modeNum).encode())

    for key in parameters.keys():
        p = parameters[key]
        n = p["Name"]
        val = p["Value"]
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
        #sendData(ser, signalSet)
        #print("***Data sent")
        recieveData(ser, signalSet)
        print("***Data recieved")

    print("Port open?", ser.is_open)

with open(r"./data/userpass.json", "r") as f:
    data = json.load(f)
data = data[0]


main(data, "VOO")

