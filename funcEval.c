#include "funcEval.h"
#define INFS DBL_MAX
 
void userIntialize (userData *uData, char **argv)
{
	uData->dimension=atoi(argv[1]);
	FILE *fp;
	fp=fopen(argv[2],"r");
	uData->startPt=malloc (sizeof(double)*uData->dimension);
	int i;
       	for (i=0; i<uData->dimension; i++) 
	{
		fscanf(fp,"%lf",&uData->startPt[i]);
	}
	fclose(fp);
	uData->iterLimit=atoi(argv[3]);
	uData->pollPattern=argv[4];
	//uData->numConstr=atoi(argv[5]);
	uData->numConstr=0;
//	uData->initPtFeasibility=atoi(argv[5]);
	uData->initPtFeasibility=1;
	uData->fpBound=fopen(argv[5],"r");
	
}

double funcEvalValue(double *x, userData *uData)
{
	double funcval=0;
	int i;
	for(i=0; i < uData->dimension-1; i++)
	{
		funcval += 100*pow(x[i+1]-pow(x[i],2),2)+pow(x[i]-1,2);
	}
	return funcval;
}

void constrEval (double *x, double *constrVec, userData *uData)
{
}

void boundsEval (double *varLB, double *varUB, double *constrLB, double *constrUB, userData *uData)
{
	int i;
	for (i=0; i<uData->dimension; i++)
	{
		fscanf(uData->fpBound,"%lf %lf",&varLB[i], &varUB[i]);
	}
	fclose(uData->fpBound);
}
