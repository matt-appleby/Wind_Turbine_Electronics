"""
Build look-up table for 360 degrees
Conceptually easier and faster to run

local: wind

todo:
--output a pwm wave that actually works
--Do that for all three phases both positive and negative parts

"""
import math
import seaborn as sns
import matplotlib.pyplot as plt

frequency=1 #Hz
period=1/frequency #s
switchingPeriod=0.05 #s

scalingConstant=1#0.1
phaseShift=0

LineOneHigh=[]
LineOneLow=[]
LineTwoHigh=[]
LineTwoLow=[]
LineThreeHigh=[]
LineThreeLow=[]

LineOne=[]
LineOneStates=[]

for cycle in range(int((int(period/switchingPeriod))/2)):#iterates throught number of cycles
    time=cycle*switchingPeriod
    TurnOn=switchingPeriod*math.sin((2*(3.14)/period)*time+phaseShift)
    #TurnOff=period-TurnOn
    
    #turn on is turn on length

    
    LineOneHigh.append(round(time,3))
    LineOneLow.append(round((time+TurnOn),3))

    LineOne.append(round(time,3))
    LineOne.append(round((time+TurnOn),3))

    LineOneStates.append(1)
    #LineOneStates.append(0)

print(LineOneHigh)
print(LineOneLow)


plt.scatter(LineOneLow, LineOneStates, c='y')
plt.scatter(LineOneHigh, LineOneStates, c='b')
plt.show()

#plt.plot(LineOne,1)