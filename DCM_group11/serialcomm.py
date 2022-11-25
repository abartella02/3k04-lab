import serial
import serial.tools.list_ports
import json


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



def main(userinfo, mode):
    device = findDevice()
    if device == None:
        print("Device not found")
        return
    print(device.description)

    parameters = getParams(userinfo)

    paramList = []

    modeNum = 0
    if mode == "AOO":
        modeNum = 1
    elif mode == "VOO":
        modeNum = 2
    elif mode == "AAI":
        modeNum = 3
    elif mode == "VVI":
        modeNum = 4

    paramList.append(int(modeNum))

    for key in parameters.keys():
        p = parameters[key]
        n = p["Name"]
        if p["Value"]:
            if  n == "Atrial Pulse Amplitude" or n == "Ventricular Pulse Amplitude" or n == "Atrial Pulse Width" or n == "Ventricular Pulse Width" or n == "Atrial Sensitivity" or n == "Ventricular Sensitivity":
                paramList.append(float(p["Value"])) 
            else:
                paramList.append(int(p["Value"]))
        else:
            paramList.append(None)

    print("Parameter Array:", paramList)

    strParamList = str(paramList).encode("utf-8")
    print("Byte array:", strParamList)

    ser = serial.Serial(device.device)
    ser.write(strParamList)
    print("Port open?", ser.is_open) #port is open
    print("Data Recieved:" ser.readline())
    ser.close()
    print("Port open?", ser.is_open)


with open(r"./data/userpass.json", "r") as f:
    data = json.load(f)
data = data[0]


main(data, "AOO")

