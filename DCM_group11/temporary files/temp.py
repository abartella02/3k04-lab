import serial
import serial.tools.list_ports as s

def findDevice():
    ports = s.comports()
    targetPort = 0
    for port in ports:
        #print("Serial Number", port.serial_number)
        if str(port.serial_number) == "000000123456":
            print("Serial Device Found")
            targetPort = port
            break
        else:
            targetPort = 0
    
    if targetPort != 0:
        return "Pacemaker Found"
    else: 
        return "Not found"

class ClassVar:
    def __init__(self):
        self.value = 0
        pass
    def set(self, val):
        self.value = val
    def get(self):
        return self.value