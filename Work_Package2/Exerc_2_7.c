/*
File name: exerc_2_7.c
 
 Date: 2017-01-24
 
 Group Number:  #nr 4
 
 Members of students contributed:
 
 Rafael Antonino Sauleo
 
 Filip Isakovski
 
 Maria-Bianca Cindroi
 
 Demonstration code: [<Examen code> <xxxx>] PENDING
 
 */
#include<stdio.h>
#include<unistd.h>
#include<string.h>

#define MAX 10
int validate_month(int month, char * personal_number);
int validate_day(int day, char * personal_number);
int replace_value(char *array, char *array_two);

int main(void)
{
	char personal_number[10];

	printf("Insert your personal number:\n");
	fgets(personal_number, MAX, stdin);
	
	int year = (personal_number[0] - '0') * 10 + (personal_number[1] - '0');
	int month = (personal_number[2] - '0') * 10 + (personal_number[3] - '0');
	while(validate_month(month, personal_number) != 0){
		fgets(personal_number, MAX, stdin);	
	}

	int day = (personal_number[4] - '0') * 10+ (personal_number[5] - '0');
	validate_day(day, personal_number);
	while(validate_day(day, personal_number) != 0){
		fgets(personal_number, MAX, stdin);	
	}
	
		
	printf("Year: %d\n",year);
	printf("Month: %d\n",month);
	printf("Day: %d\n", day);

	return 0;
}

int validate_month(int month, char * personal_number)
{
	if (month < 0 || month > 12){
		printf("The month that you inserted is invalid. Please try again!\n");
		return 1;
	}
	else
	{
   		return 0;
	}
}

int validate_day(int day, char * personal_number)
{
	if (day < 0 || day > 31){
		printf("The day that you inserted is invalid. Please try again!\n");
		return 1;
	}
    else
	{
   		return 0;
	}
}
