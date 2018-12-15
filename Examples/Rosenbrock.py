import numpy as np
import math as math
x=np.loadtxt("inputPoint.txt")
funcval=0
dimension=len(x)
for i in range(dimension-1):
    funcval += 100*math.pow(x[i+1]-math.pow(x[i],2),2)+math.pow(x[i]-1,2)

f = open("funcOutput.txt","w")
f.write(str(funcval))



