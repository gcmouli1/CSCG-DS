#include "funcEval.h"
//#define INFS DBL_MAX

void userBasicIntialize (userData *uData, char **argv)
{
	FILE *fpArgs;
	fpArgs=fopen(argv[1],"r");
	int optionSize=1024;
	char option[optionSize];
	char optionName[50];
	char optionValue[50];

	while (fgets (option, optionSize,fpArgs) != NULL)
	{
		sscanf (option,"%s %s\n",optionName,optionValue);
	//	printf ("%s = %s\n",optionName,optionValue);
		if (strcmp(optionName,"Dimension") == 0)
		{
			uData->dimension=atoi(optionValue);
		}

		if (strcmp(optionName,"InitialPointDataFile") == 0)
		{
			FILE *fp;
			fp=fopen(optionValue,"r");
			uData->startPt=malloc (sizeof(double)*uData->dimension);
			int i;
			for (i=0; i<uData->dimension; i++) 
			{
				fscanf(fp,"%lf",&uData->startPt[i]);
			}
			fclose(fp);
		}
		if (strcmp(optionName,"Precision") == 0)
		{
			uData->precision=atof(optionValue);
		}
		if (strcmp(optionName,"BoundsDataFile") == 0)
		{
			uData->fpBound=fopen(optionValue,"r");
		}
		if (strcmp(optionName,"NumberConstraints") == 0)
		{
			uData->numConstr=atoi(optionValue);
		}
		if (strcmp(optionName,"PollPattern") == 0)
		{
			uData->p=optionValue[0];
			uData->pollPattern=&uData->p;
			if (*uData->pollPattern != 'H' && *uData->pollPattern != 'S')
			{
				printf ("unknown poll sequence type. Possible types are: 'H' or 'S'. Exiting\n");
				exit (10);
			}
		}
		if (strcmp(optionName,"InitialPointFeasible") == 0)
		{
			uData->initPtFeasibility=atoi(optionValue);
			if (uData->initPtFeasibility == false)
			{
				printf ("Initial point is not satisfying bound constraints. Exiting\n");
				exit (10);
			}
		}
		if (strcmp(optionName,"Maxevals") == 0)
		{
			uData->iterLimit=atoi(optionValue);
			if (uData->iterLimit < uData->dimension+1)
			{
				printf ("Too few evaluations supplied. Give atleast n+2 evaluations. Exiting\n");
				exit (10);
			}
		}
		if (strcmp(optionName,"Loglevel") == 0)
		{
			uData->logLevel=atoi(optionValue);
			if (uData->logLevel < 0 || uData->logLevel > 2)
			{
				printf ("Unknown logLevel. It must be between 0 to 2. Exiting\n");
				exit (10);
			}
		}
	}
//	printf ("precision is %G\n",uData->precision);
//	printf ("pollPattern is %c\n",*uData->pollPattern);
//	printf ("max Evals is %d\n",uData->iterLimit);
//	printf ("printing startPt\n");
//	printf ("printing initial pt feasibility %d\n",uData->initPtFeasibility);
//	printf ("number of constraints  %d\n",uData->numConstr);

}

void userExtraIntialize (userData *uData, char **argv)
{
	//Reducing the dimension to even numbers only
	int dimension=uData->dimension;
	if (dimension % 2 != 0)
	{
		uData->dimension=dimension-1;
	}

	double *tmpStartPt = malloc (sizeof(double)*uData->dimension);
	memcpy (tmpStartPt, uData->startPt, sizeof(double)*uData->dimension);
	free (uData->startPt);

	//Rounding to closest integer point.
	int i;
	for (i=0; i<dimension; i++)
	{
		tmpStartPt[i]=round(tmpStartPt[i]);
	}

	uData->startPt = malloc (sizeof(double)*uData->dimension);
	memcpy (uData->startPt,tmpStartPt, sizeof(double)*uData->dimension);
	free (tmpStartPt);
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
