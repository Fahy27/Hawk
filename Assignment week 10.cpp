#include "stdafx.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"

struct date
{
	int day, month, year;
};

struct customer
{
	char name[50];
	int accountNumber;
	double balance;
	struct date lastTrans;
};

int getDay(int month);
int getMonth();
int getYear();
double getBalance();

void printCustomers(struct customer customers[], int nCustomers);
void populateCustomers(struct customer customers[], int nCustomers);
int transaction(struct customer customers[], int accountNumber, double amount, int nCustomers);

int main()
{
	srand(time(NULL));
	int i;

	struct customer customers[10];

	populateCustomers(customers, 10);

	printf("%25s\t%13s\t%12s\t%s\n\n", "Name", "Account Number", "Balance", "Date of Last Transaction");

	printCustomers(customers, 10);

	printf("\n\n");

	if (!(transaction(customers, 10001, -967.89, 10)))
	{
		printf("account number %d not found - transaction cancelled", 10001);
	}
	else
	{
		printf("account number %d - transaction processed", 10001);
	}
	printf("\n\n");

	if (!(transaction(customers, 33, -967.89, 10)))
	{
		printf("account number %d not found - transaction cancelled", 33);
	}
	else
	{
		printf("account number %d  - transaction processed", 33);
	}
	printf("\n\n");

	printf("%25s\t%13s\t%12s\t%s\n\n", "Name", "Account Number", "Balance", "Date of Last Transaction");

	printCustomers(customers, 10);

	printf("\n\n");


	return 0;
}

int getDay(int month)
{
	int day;
	if (month == 2) {
		day = rand() % 28 + 1;
	}
	else if (month <= 7 && month % 2 != 0) {
		day = rand() % 31 + 1;
	}
	else if (month >= 8 && month % 2 == 0) {
		day = rand() % 31 + 1;
	}
	else  day = rand() % 30 + 1;

	return day;
}

int getMonth()
{
	int month;
	month = rand() % 12 + 1;


	return month;
}

int getYear()
{
	int year;
	year = rand() % 4 + 2013;

	return year;
}

double getBalance()
{
	int balance;
	balance = rand() % 10000 - 5000;
	return balance;
}

void printCustomers(struct customer customers[], int nCustomers)
{
	int i;
	for (i = 0; i < nCustomers; i++) {
		printf("%25s\t", customers[i].name);
		printf("%14d\t", customers[i].accountNumber);
		printf("%12.2f\t", customers[i].balance);
		printf("%d/%d/%d\n", customers[i].lastTrans.day, customers[i].lastTrans.month, customers[i].lastTrans.year);
	}


	return;
}

void populateCustomers(struct customer customers[], int nCustomers)
{
	int i;
	char names[10][50] = { "Haiden Soto","Oscar Hernandez","Heath Hickman","Reagan Mcknight","Noah Bartlett","Ross Day","Maribel Livingston","Jewel Phillips","Blake Gardner","Fernanda Ponce" };

	for (i = 0; i < nCustomers; i++)
	{
		strcpy(customers[i].name, names[i]);
		customers[i].accountNumber = 10000 + i;
		customers[i].balance = getBalance();
		customers[i].lastTrans.month = getMonth();
		customers[i].lastTrans.day = getDay(customers[i].lastTrans.month);
		customers[i].lastTrans.year = getYear();
	}

	return;

}

int transaction(struct customer customers[], int accountNumber, double amount, int nCustomers)
{
	for (int i = 0; i < nCustomers; i++) {
		if (customers[i].accountNumber == accountNumber) {
			customers[i].balance = customers[i].balance + amount;
			return 1;
		}
	}


	return 0;
}






