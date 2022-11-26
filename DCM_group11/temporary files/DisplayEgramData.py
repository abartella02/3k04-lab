#initial framework for displaying Egram Data from pacemaker

import matplotlib.pyplot as graph
import random #remove after we have real data (was only used for testing)

x = [] #x-axis
y = [] #y-axis
t = 0.0 #time

for i in range(50): #range will change depending on number of inputs
    x.append(t)
    t += 0.001 #setting up x axis (change 1ms to whatever correct sampling interval)
    data = random.randint(0,30) #replace this with sampling data
    y.append(data) 
    print(data)#just to test

graph.plot(x, y)
graph.title('Egram Data from Pacemaker')
graph.xlabel('Time(s)') #change if its different i wasn't sure
graph.ylabel('Voltage(mV)')  #change if its different i wasn't sure
graph.savefig('EgramData.png')

