#include <stdlib.h>
#include <stdio.h>

void sort(int number, int tab[]);

int main(int argc, char **argv)
{
    int test[] = { 1,2,34,5,67,3,23,12,13,10};
    sort(10,test);

}

/*
*Sorting function
*/void sort(int number, int tab[])
{
    int tmp;
    int minIndex;
    for(int i=0; i<number; i++)
    {
        minIndex = i;
        // Search for the minimum number
        for(int j=i+1; j<number; j++)
        {
            if(tab[j]<tab[minIndex]) minIndex = j;
        }
        tmp = tab[i];
        tab[i] = tab[minIndex];
        tab[minIndex] = tmp;
    }

    for(int i=0; i<number-1; i++)
    {
        printf("%d, ",tab[i]);
    }
    printf("%d\n", tab[number-1]);
}
