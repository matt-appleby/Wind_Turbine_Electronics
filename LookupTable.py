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


def PhaseTimingGen(phaseShift):
    LineHigh=[]
    LineLow=[]
    for cycle in range(int((int(period/switchingPeriod))/2)):#iterates throught number of cycles
        time=cycle*switchingPeriod
        TurnOn=switchingPeriod*math.sin((2*(3.14)/period)*time+phaseShift)
        LineHigh.append(round(time,3))
        LineLow.append(round((time+TurnOn),3))
    return LineHigh, LineLow


LineOneHigh, LineOneLow = PhaseTimingGen(0)
LineTwoHigh, LineTwoLow = PhaseTimingGen(2*3.14/3)
LineThreeHigh, LineThreeLow = PhaseTimingGen(-2*3.14/3)

print("Line One")
print(LineOneHigh)
print(LineOneLow)

print("Line Two")
print(LineTwoHigh)
print(LineTwoLow)

print("Line Three")
print(LineThreeHigh)
print(LineThreeLow)

print("Time between for loops in arduino")
print(period/6)


def PWMCycleOrder(PWMHigh,PWMOneLow,PWMTwoLow,PWMThreeLow):
    #sort the turn off of the three lines into cronalogical order per switching cycle
    if PWMOneLow < PWMTwoLow and PWMTwoLow < PWMThreeLow:# 1, 2 , 3
        print()
    elif PWMOneLow < PWMThreeLow and PWMThreeLow < PWMTwoLow: # 1, 3, 2
        print
    elif PWMTwoLow < PWMOneLow and PWMOneLow < PWMThreeLow# 2, 1, 3
        print()
    elif PWMTwoLow < PWMThreeLow and PWMThreeLow < PWMOneLow# 2, 3, 1
        print()
    elif PWMThreeLow < PWMOneLow and PWMOneLow < PWMTwoLow# 3, 1, 2
        print()
    #elif PWMThreeLow < PWMTwoLow and PWMTwoLow < PWMOneLow# 3, 2, 1
    else:
        print()
