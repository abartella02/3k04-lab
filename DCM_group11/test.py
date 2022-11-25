# import modules
import threading as T
import time
 

global x
x = 1
# creating a function
def checkConnection():
    while True:
        global x
        if x == 1:
            print("Connected")
        else:
            print("Not connected")
        time.sleep(1)
 
# creating a thread

t = T.Thread(target = checkConnection, daemon=True, name="Monitor")
 
# change T to daemon
#T.setDaemon(True)  
 
# starting of Thread T
print("Starting BG task")
t.start()                          
time.sleep(5)
x = 0
time.sleep(2)
x = 1
time.sleep(3)
print('this is Main Thread') 