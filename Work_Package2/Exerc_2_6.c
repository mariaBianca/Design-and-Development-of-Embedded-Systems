#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int list[MAX];

void initQue(int list[], int max)
{
	int i = 0;
	for (i=0; i < max; i++)
	{
    	list[i] = -1;
	}
}

int input(int list[], int number, int max)
{
	int toggle = 0;
	
	int i = 0;
	for (i=0; i < max; i++)
	{
		if(list[i] == -1 && toggle == 0)
		{
    		list[i] = number;
    		toggle = 1;
    	}
	}
	
	return toggle;
}

int output(int list[], int max)
{
	int res = 0;
	if(list[0] != -1)
	{
		res = list[0];
		
		int i = 0;
		for (i=0; i < max-1; i++)
		{
    		list[i] = list[i+1];
		}
		list[max-1] = -1;
		
		return res;
	}
	return res;
}

int main(int argc, char *argv[]) {
	
	int list[MAX];
	int input_res, output_res;
	int num = 0;
	
	initQue(list, MAX);
	
	int i = 0;
	for (i=0; i < MAX; i++)
	{
		printf("%d\n", list[i]);
	}
	
	printf("Enter a postive integer:\n");
	scanf("%d", &num);	
	input_res = input(list, num, MAX);
	
	i = 0;
	for (i=0; i < MAX; i++)
	{
		printf("%d\n", list[i]);
	}
	
	printf("Enter a postive integer:\n");
	scanf("%d", &num);
	input_res = input(list, num, MAX);
	
	i = 0;
	for (i=0; i < MAX; i++)
	{
		printf("%d\n", list[i]);
	}
	
	output_res = output(list, MAX);
	printf("Output: %d\n", output_res);
	
	i = 0;
	for (i=0; i < MAX; i++)
	{
		printf("%d\n", list[i]);
	}
	
	output_res = output(list, MAX);
	printf("Output: %d\n", output_res);
	
	i = 0;
	for (i=0; i < MAX; i++)
	{
		printf("%d\n", list[i]);
	}
	
	output_res = output(list, MAX);
	printf("Output: %d\n", output_res);
	
	i = 0;
	for (i=0; i < MAX; i++)
	{
		printf("%d\n", list[i]);
	}
	
	
	
	return 0;
}
