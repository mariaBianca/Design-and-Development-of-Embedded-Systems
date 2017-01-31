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
#include <unistd.h>
#include <math.h>
#include <ctype.h>
#define MAX 11

/*
 * This method will just read the input and fill the personal number. If the input is not valid it exits.
 */
void readPersnr(char *person){
    fgets(person, MAX, stdin);
    
    long personalNumber = atol(person);
    printf("personal number %ld\n", personalNumber);
    
    long numberOfDigits = floor(log10(abs(personalNumber))) + 1 ;
    printf("size %ld\n", numberOfDigits);
    
    
    /*
     int potato = strlen(personalNumber);
     printf("size of the potato %d\n", potato);
     */
    /*
     int count = countDigits(person);
     printf("count %d\n", count);
     */
    
    if(person[0] == 'q'){
        exit(0);
    } else if (numberOfDigits !=9) {
        printf("Input not valid!\n");
        exit(0);
    }
}

/*
 * This method is used to count the number of digits in an array
 */
int countDigits(const char* person){
    int count = 0;
    for (int i = 0; i < strlen(person); i ++) { //This method checks the day of the personal number
        count++;
        printf("count %d\n", count);
    }
    return count;
}


/*
 * Algorith to check someone's birthday
 */
long controlDigit(const char* person) { //algorithm MAYBE DECLARE IT AS INT
    int sum = 0;
    //char numberInArray[0]; //another way of tranforming char to int is creating a char mini array
    
    for (int i = 0; i < 10; i ++) { //This method checks the day of the personal number
        sum = (person[i]-'0') + sum;
        
        /*
         numberInArray[0] = person[i];   THIS CAN BE AN ALTERNATIVE TO SUM THE DIGITS FROM CHAR TO INT
         printf("before sum %d\n", sum);
         sum = atoi(numberInArray) + sum;
         printf("after sum %d\n", sum);
         */
    }
    
    printf("sum is: %d\n", sum);
    long controlD = 10 -(sum %10); //atol() takes a bigger number.
    return controlD;
}

/*
 *Method used to take the introduced month
 */
int takeDay(char *person) {
    char dayChar[1];
    int i;
    int j =0; //j is used for the index of the temporary array
    for (i = 4; i < 6; i ++) { //This method checks the day of the personal number
        dayChar[j] = person[i];
        j++;
    }
    
    int day = atoi(dayChar);
    
    if(day>0 && day <32){
        return day;
    }
    printf("the day you entered is not valid\n");
    return 0;
}


/*
 *Method used to take the introduced month
 */
int takeMonth(char *person) {
    char monthChar[1];
    int i;
    int j =0; //j is used for the index of the temporary array
    for (i = 2; i < 4; i ++) { //This method checks the month of the personal number
        monthChar[j] = person[i];
        j++;
    }
    
    int month = atoi(monthChar);
    if(month>0 && month <13){
        return month;
    }
    printf("the month you entered is not valid\n");
    return 0;
}
/*
 * Method used to take the introduced year
 */
int takeYear(char *person) {
    char yearChar[1];
    int i;
    int j =0; //j is used for the index of the temporary array
    for (i = 0; i < 2; i ++) { //This method checks the year of the personal number
        yearChar[j] = person[i];
        j++;
    }
    int year = atoi(yearChar);
    if(year>=0 && year <100){
        return year;
    }
    printf("the year you entered is not valid\n");
    return 0;
}

int main() {
    char person[MAX];
    char exit[1];
    char *pointer = person;
    long personal_number;
    int day;
    int month;
    int year;
    
    do {
        printf("Introduce a personal number!\n");
        readPersnr(pointer);
        exit[0] = person[0];
        
        year = takeYear(pointer);
        printf("The year of your birthday is: %d\n", year);
        
        month = takeMonth(pointer);
        printf("The month of your birthday is: %d\n", month);
        
        day = takeDay(pointer);
        printf("The day of your birthday is: %d\n", day);
        
        personal_number = controlDigit(person);//check this algorithm
        printf("%ld\n", personal_number); //this returns 6?
        fseek(stdin,0,SEEK_END); //we need to flush the input of before.
        
    } while(exit[0] != 'q');
    
    
    return 0;
}
