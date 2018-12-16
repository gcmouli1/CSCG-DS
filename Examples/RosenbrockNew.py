#import numpy as np
import math as math
#x=np.loadtxt("inputPoint.txt")
fx=open('inputPoint.txt','r')
x=fx.readlines()
fx.close()
funcval=0
dimension=len(x)
for i in range(dimension-1):
    funcval += (100*math.pow(float(x[i+1])-math.pow(float(x[i]),2),2)+math.pow(float(x[i])-1,2))

f = open("funcOutput.txt","w")
f.write(str(funcval))



