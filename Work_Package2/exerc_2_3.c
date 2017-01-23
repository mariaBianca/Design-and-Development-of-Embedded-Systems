#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	char *string1 = argv[1];
	char *string2 = argv[2];
	int res=0;
	
	printf("String 1: %s\n", string1);

	printf("String 2: %s\n", string2);
	
	int str1length = 0;
	int str2length = 0;
	
	//Getting the lengths of the strings
	str1length = strlen(argv[1]);
	str2length = strlen(argv[2]);

	//Checking with strcmp()
	res = strcmp(string1, string2);
	
	//Using result from strcmp(), AND doing another check without it
	if(res < 0 && str1length < str2length)
	{
		printf("String 1 is shorter!");
	}
	else if(res > 0 && str1length > str2length) 
	{
		printf("String 2 is shorter!");
	}
	else 
	{
		printf("Both strings are equal in length!");
	}
	
	return 0;
}
