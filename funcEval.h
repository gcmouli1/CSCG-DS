#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h> /* use C99 or above versions */
#ifndef _FUNCEVAL_
#define _FUNCEVAL_
#ifndef INFS
#define INFS DBL_MAX
#endif
#ifndef MAX
#define MAX(a,b) ((a) > (b) ? a : b)
#endif
#ifndef MIN
#define MIN(a,b) ((a) < (b) ? a : b)
#endif
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct
{
	int dimension;
	int numConstr;
	int iterLimit;
	char *pollPattern;
	bool initPtFeasibility;
	double *startPt;
	FILE *fpBound;
} userData;

//#include "vecLapack.h"
//#include "madsDeclare.h"
//double funcEvalValue (vectorD *point, madsStructure *mads);
//void constrEval (vectorD *x, madsStructure *mads);
void userIntialize (userData *uData, char **argv);
double funcEvalValue(double *x, userData *uData);
void constrEval (double *x, double *constrVec, userData *uData);
void boundsEval (double *varLB, double *varUB, double *constrLB, double *constrUB, userData *uData);
void eiud29_(int *dimension, double *inputVector, double *fmin, double *xmax, int *problemNum, int *iext, int *ierr);
void effu29_(int *dimension, double *inputVector, double *funcValue, int *problemNum);
#endif
