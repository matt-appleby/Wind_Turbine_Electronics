"""
Build look-up table for 360 degrees
Conceptually easier and faster to run
"""
import math
import seaborn as sns
import matplotlib.pyplot as plt

frequency=1 #Hz
period=1/frequency #s
switchingPeriod=0.01 #s

scalingConstant=0.1
phaseShift=0

LineOneHigh=[]
LineOneLow=[]
LineTwoHigh=[]
LineTwoLow=[]
LineThreeHigh=[]
LineThreeLow=[]

LineOne=[]
LineOneStates=[]

for x in range(int(period/switchingPeriod)):
    time=x*switchingPeriod
    Ton=scalingConstant*math.sin((2*(3.14)/period)*time+phaseShift)
    Toff=period-Ton
    LineOneHigh.append(round(time,3))
    LineOneLow.append(round((time+Ton),3))

    LineOne.append(round(time,3))
    LineOne.append(round((time+Ton),3))

    LineOneStates.append(1)
    LineOneStates.append(0)


print(LineOneLow)


#sns.lineplot(data=[LineOne,LineOneStates], x=LineOne, y=LineOneStates, color="black", marker="o")
plt.plot(LineOne, LineOneStates)
plt.show()
#plt.title("Output", fontsize=20)