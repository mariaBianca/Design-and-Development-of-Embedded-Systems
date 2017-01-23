/*
@author Antonino Sauleo, Maria-Bianca Cindroi, Filip Isakovski
Write a program that reads a string with a max of 20 characters from the keobyard and stores it in a local string variable.
/*b) A new function void copyString(..) not using any library function.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20
void copyString(char* text, char* textCopied);

int main(void){
	char c, text[MAX], copiedText[100];
	int n= MAX;
	
	fflush(stdin);
	printf("Enter something:");
	fgets(text, MAX, stdin);

	copyString(text, copiedText);

	printf("Text to be copied: %s\n", text);
	printf("Final copied string: %s\n",copiedText);

	return 0;
}

void copyString(char* text, char* copiedText){
	
	int check=0;
	while(check<=MAX){
		copiedText[check]=text[check];
		check++;
	}
	
	return;
}
