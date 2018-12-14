# CSCG-DS
Bound Constrained Derivative Free Optimization Algorithm
Make sure you have blas and lapack installed on your system.
for e.g. on ubuntu,mint,debian etc this can done by 
**$sudo apt-get install libblas-dev liblapack-dev**


To run the algorithm, do following steps:
  1. Goto the directory CSCG-DS
  2. **$make**
  3. **$./cscgds parameters.txt**

Options are given in parameters.txt file. 
One can use arguments other than regular options given in parameters.txt

For working with examples given in Example directory:
1. Copy the files to current folder with filename changed to funcEval.c i.e. **$cp Examples/evenDimRound.c funcEval.c**
2. **$make**
3. **$./cscgds parameters.txt**
