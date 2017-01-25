/*
@author Antonino Sauleo, Filip Isakovski, Maria-Bianca Cindroi
Create a program that checks an entered Swedish person number. The number is entered in the form of :   7107254786 (yymmddxxxc).The number should be read
in as a string and converted to integers for year, month , day and number. The last digit(here 6)is a control digit and is calculated from the other digits
by an algorithm that you can find on the internet. The user inputs the number, the program first checks that the number of month and day is in the right 
range and after that calculate and checks the control digit. The program then prints out the result and asks for a new person number. This is repeated until the user inputs a ‘q’. The program should at least consist of the functions: main() , readPersnr( char *person), int controlDigit( const char * persnr ).
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
