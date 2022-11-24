import serial
import serial.tools.list_ports


def findDevice():
    target_desc = "SAMSUNG Mobile USB Modem"
    ports = serial.tools.list_ports.comports()

    for port in ports:
        if port.description == target_desc:
            return port
    return None



def main():
    print(findDevice().name)

main()

