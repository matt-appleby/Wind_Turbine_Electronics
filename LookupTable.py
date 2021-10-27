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
        print("PWM one low")
        print("wait PWMHigh-PWM low 1")
        print("PWM two low")
        print("wait PWMHigh-PWMLow1-PWMLow2")
        print("PWM three low")
        print("wait PWMHigh-PWMLow1-PWMLow2-PWMLow3")
    elif PWMOneLow < PWMThreeLow and PWMThreeLow < PWMTwoLow: # 1, 3, 2
        print()
        #like above but change for each switch
    elif PWMTwoLow < PWMOneLow and PWMOneLow < PWMThreeLow:# 2, 1, 3
        print()
    elif PWMTwoLow < PWMThreeLow and PWMThreeLow < PWMOneLow:# 2, 3, 1
        print()
    elif PWMThreeLow < PWMOneLow and PWMOneLow < PWMTwoLow:# 3, 1, 2
        print()
    #elif PWMThreeLow < PWMTwoLow and PWMTwoLow < PWMOneLow# 3, 2, 1
    else:
        print()

def Switchingcycle(degrees):
    if degrees < 60:#0-60
        print("1 high, 2 low, 3 high")
        #MOSFETS
        PhaseOneTransistor = 1
        PhaseTwoTransistor = 5 
        PhaseThreeTransistor = 3
    elif degrees < 120:#60-120
        print("1 high, 2 low, 3 low")
        PhaseOneTransistor = 1 
        PhaseTwoTransistor = 5 
        PhaseThreeTransistor = 6
    elif degrees < 180:#120-180
        print("1 high, 2 high, 3 low")
        PhaseOneTransistor = 1
        PhaseTwoTransistor = 2 
        PhaseThreeTransistor = 6
    elif degrees < 240:#180-240
        print("1 low, 2 high, 3 high")
        PhaseOneTransistor = 4
        PhaseTwoTransistor = 2 
        PhaseThreeTransistor = 3
    else:# degrees      240-360
        print("1 low, 2 low, 3 high")
        PhaseOneTransistor = 4
        PhaseTwoTransistor = 5 
        PhaseThreeTransistor = 3
    return PhaseOneTransistor, PhaseTwoTransistor, PhaseThreeTransistor

for x in range(6):
    p1mos, p2mos, p3mos = Switchingcycle(x*10)
    cycles= #number of cycles in 60 degrees
    for y in range(cycles)
        counter=cycles*x+y
        PWMCycleOrder(LineOneHigh[counter], LineOneLow[counter], LineTwoLow[counter], LineThreeLow[counter])#takes in timing arguments
        

# think we need to find a whole number so we dont have to deal with decimals and pain

#def a function to do the execute stage of the if
#def a function to tell which mosfets to switch
#assume ideal switch then fix