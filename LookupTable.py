"""
Build look-up table for 360 degrees
Conceptually easier and faster to run

local: wind
Todo:
--Assuming when a dead time occurs there won't be any current due to wave shape

"""
import math
import seaborn as sns
import matplotlib.pyplot as plt

frequency=1 #Hz
period=1/frequency #s
switchingPeriod=0.05 #s

scalingConstant=1#0.1
phaseShift=0


def PhaseTimingGen(phaseShift):
    LineHigh=[]
    LineLow=[]
    for cycle in range(int((int(period/switchingPeriod))/2)):#iterates throught number of cycles
        time=cycle*switchingPeriod
        TurnOn=abs(switchingPeriod*math.sin((2*(3.14)/period)*time+phaseShift))
        LineHigh.append(round(time,3))
        LineLow.append(round((time+TurnOn),3))
    return LineHigh, LineLow


LineOneHigh, LineOneLow = PhaseTimingGen(0)
LineTwoHigh, LineTwoLow = PhaseTimingGen(2*3.14/3)
LineThreeHigh, LineThreeLow = PhaseTimingGen(-2*3.14/3)

#Convert from secounds to millis for Arduino
LineOneHigh=[x*1000 for x in LineOneHigh]
LineOneLow=[x*1000 for x in LineOneLow]
LineTwoLow=[x*1000 for x in LineTwoLow]
LineThreeLow=[x*1000 for x in LineThreeLow]

print("High")
print(LineOneHigh)

print("Line One")
print(LineOneLow)

print("Line Two")
print(LineTwoLow)

print("Line Three")
print(LineThreeLow)

print("Time between for loops in arduino:")
print(period/6)

# think we need to find a whole number so we dont have to deal with decimals and pain