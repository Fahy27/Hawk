// AssignmentWeek14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <string.h>


FILE *fptr;

int openFile()
{
	fptr = fopen("C:\\Users\\evan\\Desktop\\SampleData.txt", "r");
	if (fptr == NULL)
	{
		return 0;
	}
	else return 1;
}

void closeFile()
{
	fclose(fptr);
}

void main(void)
{
	char response[10], orderdate[20], region[20], rep[20], item[20];
	int units;
	float unitcost, total, item_total;
	int openOK = 0;
	openOK = openFile();
	if (openOK)
	{
		while (1)
		{
			item_total = 0;
			printf("\nEnter product name <or return to quit> : ");
			gets_s(response);
			if (response[0] != '\0')
			{
				while (!feof(fptr))
				{
					fscanf(fptr, "%s%s%s%s%d%f%f", &orderdate, &region, &rep, &item, &units, &unitcost, &total);
					if (strcmp(item, response) == 0)
					{
						item_total += total;
					}
				}
				printf("\nTotal Sales for %s = %.2f", response, item_total);
				fseek(fptr, 0, SEEK_SET);
			}
			else
			{
				printf("\nEnd of processing");
				break;
			}
		}
	}

	else
	{
		printf("Error opening file ! \n");
	}


	closeFile();
}