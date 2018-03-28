#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "MyFunc.h"
#include "Struct.h"

using namespace std;
int nz;

void main()
{
	setlocale(LC_ALL, "Ru");
	srand(time(NULL));
	while (true)
	{
		printf("Введите номер задания "); scanf("%d", &nz);
		if (nz == 0)
		{
			break;
		}
		else if (nz == 1)
		{
			part parts[20];
			for (int i = 0;i < 20;i++)
			{
				parts[i].shifr = creatShifr();
				for (int j = 0;j < 4;j++)
				{
					parts[i].plan[j] = creatPlan();
					parts[i].vyp[j] = creatV();
				}
			}

			/*printf("Подразделение\tКвартал 1\tКвартал 2\tКвартал 3\tКвартал 4\n");
			for (int i = 0;i < 20;i++)
			{
				printf("%d\n план\t%d\t%d\t%d\t%d\nвыполнили\t%d\t%d\t%d\t%d\n", parts[i].shifr, parts[i].plan[0], parts[i].plan[1], parts[i].plan[2], parts[i].plan[3], parts[i].vyp[0], parts[i].vyp[1], parts[i].vyp[2], parts[i].vyp[3]);
			}*/

			int vyp[20];
			for (int i = 0;i < 20;i++)
			{
				int v=0;
				for (int j = 0;j < 4;j++)
				{
					if (parts[i].vyp[j] >= parts[i].plan[j])v++;
				}
				vyp[i] = v;
			}
			part temp;
			for (int i = 0;i < 20;i++)
			{
				for (int j = 0;j < 19;j++)
				{
					if (vyp[j] < vyp[j + 1])
					{
						temp.shifr = parts[j].shifr;
						for (int k = 0;k < 4;k++)
						{
							temp.plan[k] = parts[j].plan[k];
							temp.vyp[k] = parts[j].vyp[k];
						}
						parts[j].shifr = parts[j + 1].shifr;
						for (int k = 0;k < 4;k++)
						{
							parts[j].plan[k] = parts[j+1].plan[k];
							parts[j].vyp[k] = parts[j+1].vyp[k];
						}
						parts[j + 1].shifr = temp.shifr;
						for (int k = 0;k < 4;k++)
						{
							parts[j+1].plan[k] = temp.plan[k];
							parts[j+1].vyp[k] = temp.vyp[k];
						}
					}
				}
			}
			/*printf("Подразделение\tКвартал 1\tКвартал 2\tКвартал 3\tКвартал 4\n");*/
			for (int i = 0;i < 20;i++)
			{
				printf("%d\n     план\t%d\t%d\t%d\t%d\nвыполнили\t%d\t%d\t%d\t%d\n",parts[i].shifr,parts[i].plan[0],parts[i].plan[1], parts[i].plan[2], parts[i].plan[3], parts[i].vyp[0], parts[i].vyp[1], parts[i].vyp[2], parts[i].vyp[3]);
			}		
		}
		else if (nz == 2)
		{
			system("cls");
			student *students;
			int cS;
			printf("Введите количество студентов "); scanf("%d", &cS);
			students = (student*)malloc(cS * sizeof(student));
			int dI;
			int *sr;
			sr = (int*)malloc(cS * sizeof(int));
			int *coc;
			coc = (int*)malloc(cS * sizeof(int));
			for (int i = 0;i < cS;i++)
			{				
				dI = 5 + rand() % 5;
				students[i].name = (char*)malloc(dI * sizeof(char));
				creatName(students[i].name, dI);
				/*printf("%s\n", students[i].name);*/				
				coc[i] = 5 + rand() % 5;
				students[i].oc = (int*)malloc(coc[i] * sizeof(int));
				creatOc(students[i].oc, coc[i]);				
				int sum = 0;
				for (int j = 0;j < coc[i];j++)
				{					
					sum += students[i].oc[j];
					/*printf("%d\t", students[i].oc[j]);*/
				}
				sr[i] = sum / coc[i];
				/*printf("%d\n",sr[i]);*/
			}
			for (int i = 0;i < cS;i++)
			{
				if (sr[i] >= 9)	strcpy(students[i].prizn, "отличник");
				else if(sr[i]<9&&sr[i]>=6) strcpy(students[i].prizn, "хорошист");
				else if (sr[i]<6 && sr[i] >= 4) strcpy(students[i].prizn, "троечник");
				else if (sr[i]<4) strcpy(students[i].prizn, "неуспевающий");
			}
			for (int i = 0;i < cS;i++)
			{
				if (strcmp(students[i].prizn,"отличник")==0)
				{
					printf("Студент - %s, отличник\nоценки\n",students[i].name);
					for (int j = 0;j < coc[i];j++) printf("%d\t", students[i].oc[j]);
					printf("\n\n");
				}
			}
			for (int i = 0;i < cS;i++)
			{
				if (strcmp(students[i].prizn,"хорошист")==0)
				{
					printf("Студент - %s, хорошист\nоценки\n", students[i].name);
					for (int j = 0;j < coc[i];j++) printf("%d\t", students[i].oc[j]);
					printf("\n\n");
				}
			}
			for (int i = 0;i < cS;i++)
			{
				if (strcmp(students[i].prizn,"троечник")==0)
				{
					printf("Студент - %s, троечник\nоценки\n", students[i].name);
					for (int j = 0;j < coc[i];j++) printf("%d\t", students[i].oc[j]);
					printf("\n\n");
				}
			}
			for (int i = 0;i < cS;i++)
			{
				if (strcmp(students[i].prizn,"неуспевающий")==0)
				{
					printf("Студент - %s, неуспевающий\nоценки\n", students[i].name);
					for (int j = 0;j < coc[i];j++) printf("%d\t", students[i].oc[j]);
					printf("\n\n");
				}
			}
		}
		else
		{
			printf("Такого задания не существует");
		}
	}
}