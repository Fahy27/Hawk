// Assignment15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

typedef struct
{
	int day, month, year;
} date;

typedef struct
{
	char firstName[50];
	char lastName[50];
	char email[50];
	date dob;
} person;

char months[12][12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
int numContacts = 0;
person people[10];

int readFile(char *fileName);
date getDate(char *dateString);
int getAge(date dob);
char *getMonth(int month);
void printPerson(person p1);

int  main()
{
	char fileName[] = "C:\\Users\\evan\\Desktop\\people.txt";
	int i = 0;

	if (!readFile(fileName))
	{
		printf("File could not be opened !!\n");
		return 0;
	}


}

void printPerson(person p1)
{
	// CODE TO PRINT OUT PERSON AS PER SAMPLE OUTPUT
	printf("\nFirst Name: %s", p1.firstName);
	printf("\nLast Name: %s", p1.lastName);
	printf("\ne-mail: %s", p1.email);
	printf("\nDOB: %s %d, %d", getMonth(p1.dob.month), p1.dob.day, p1.dob.year);
	printf("\nAge: %d", getAge(p1.dob));

}


int readFile(char *fileName)
{
	char line[400];
	FILE *fptr = fopen(fileName, "r");
	char *token;
	char delim[6] = ",";
	int n = 0, i = 0;
	person p1;
	date d1;

	if (fptr == NULL)
	{
		printf("Error opening file ! \n");
		return 0;
	}

	// use fgets to skip first line
	fgets(line, 400, fptr);

	//first data line
	fgets(line, 400, fptr);
	while (!feof(fptr))
	{
		token = strtok(line, delim);
		strcpy(p1.firstName, token);
		token = strtok(NULL, delim);
		strcpy(p1.lastName, token);
		token = strtok(NULL, delim);
		strcpy(p1.email, token);
		token = strtok(NULL, delim);
		p1.dob = getDate(token);


		printPerson(p1);
		people[n] = p1;
		n++;
		//next data line
		fgets(line, 200, fptr);

	}
	numContacts = n;

	fclose(fptr);

	return 1;
}

date getDate(char *dateString)
{
	date d1;
	char delim[2] = "/";
	char *token;
	int day, month, year;

	// TO CONVERT THE DATE STRING INTO A DATE STRUCTURE
	token = strtok(dateString, delim);
	d1.day = atoi(token);
	token = strtok(NULL, delim);
	d1.month = atoi(token);
	token = strtok(NULL, delim);
	d1.year = atoi(token);
	return d1;
}


int getAge(date dob)
{
	int age;

	age = 2019 - dob.year;

	return age;

}

char *getMonth(int month)
{
	return months[month - 1];

}