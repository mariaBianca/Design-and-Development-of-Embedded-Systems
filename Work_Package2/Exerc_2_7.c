/*
File name: exerc_2_7.c 
 
 Date: 2017-01-25
 
 Group Number:  #nr 4
 
 Members of students contributed:
 
 Rafael Antonino Sauleo
 
 Filip Isakovski
 
 Maria-Bianca Cindroi
 
 Demonstration code: [<Examen code> <xxxx>] PENDING
 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 9

long readPersnr(char * person);
int validateDay(int day);
int validateMonth(int month);

int main()
{
	
	char person[MAX];
	char *pointer = person;	
	long personal_number = 0;
	char text[60] = "Introduce a personal number!";

	do
	{
		printf("%s\n", text);
		personal_number = readPersnr(pointer);
		//printf("%ld\n\n",personal_number);
		if (personal_number == 2){
			char textC[] = "The number you have introduced is invalid. Please try again!";
			strcpy(text, textC);
			
		}
		else
		{
			char textC[] = "Introduce a personal number!";
			strcpy(text, textC);
		}
	}
	while (personal_number != 1);

return 0;
}

long readPersnr(char *person){		
	//read the user's input	
	fgets(person, MAX, stdin);
	long personal_number;

	//check if the month and the day have valid values
	int month = (person[2]-'0')* 10 + (person[3]-'0');
	int day = (person[4] -'0')*10 + (person[5]-'0');
	int checkDay = validateDay(day);
	int checkMonth = validateMonth(month);

	//check user input
	if (person[0] == 'q')
	{
		personal_number = 1;
	}
	else if ((checkDay!=1)&& (checkMonth!=1))
	{
		int control = person[MAX]-'0';	
	}	
	else
	{
		personal_number = 2;			
	}

	return personal_number;
}

int controlDigit(const char* persnr)
{
	int controlDig = (persnr[0]-'0') + (persnr[1]-'0') + (persnr[2]-'0') +
				(persnr[3]-'0') + (persnr[4]-'0') + (persnr[5]-'0') + 
				(persnr[7]-'0') + (persnr[8]-'0') + (persnr[9]-'0') +
				(persnr[10]-'0');
	controlDig = 10-(controlDig % 10);
	return controlDig;
}

/*
Method used to check the validity of the introduced day
*/
int validateDay(int day)
{
	if (day<0 || day > 31){
		return 1;		
	}
	else
	{	
		return 0;
	}
}

/*
Method used to check the validity of the introduced month
*/
int validateMonth(int month)
{
	if (month < 0 || month > 12)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
