/*Write a program that reads a string with a max of 20 characters from the keobyard and stores it in a local string variable.
a)Copy the string to another string by using the library function "strcpy(..)*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

int main(void){
	char c, text[MAX], copiedText[100];
	int n= MAX;
	
	fflush(stdin);
	printf("Enter something:");
	fgets(text, MAX, stdin);

	while(((c=getchar())!='\n') && n==0){
		text[n]=c;
		n--;
	}

	strcpy(copiedText, text);
	printf("Text to be copied: %s\n", text);
	printf("Final copied string: %s\n", copiedText);

	return(0);
}
