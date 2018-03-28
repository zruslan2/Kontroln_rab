#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int creatShifr()
{
	int sh;
	
	sh = 100 + rand() % 800;
	return sh;
}

int creatPlan()
{
	int p;	
	p = 1000 + rand() % 100;
	return p;
}

int creatV()
{
	int v;
	
	v = 900 + rand() % 500;
	return v;
}

void creatName(char*name,int r)
{			
		name[0] = (char)(65 + rand() % 27);
		for (int i = 1;i < r;i++)
		{
			name[i] = (char)(97 + rand() % 27);
		}
		name[r] = '\0';	
}

void creatOc(int*oc, int r)
{
	for (int i = 0;i < r;i++)
	{
		*oc = 1 + rand() % 9;
		oc++;
	}
}
