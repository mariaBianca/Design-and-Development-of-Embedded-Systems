/* *******************************
Program file : bit_manage_function.c
Peter Lundin / 2016-01-97
For test IO program function

******************************** */

/*

 File name: exerc_4_5a.c (or cpp)

 Date: 2017-02-20

 Group Number:  #nr 4

 Members of students contributed:

 Rafael Antonino Sauleo

 Filip Isakovski

 Maria-Bianca Cindroi

 Demonstration code: [<Examen code> <PENDING>]
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void f_delay(int);
unsigned char random_inport( void);
void printport( int);
unsigned char check_keyboard(void);

struct s1 {
    unsigned char keypressed : 1;
    unsigned char allhigh: 4;
} s;

int main(){
    int nr;
    unsigned char port;
    srand(time(0));

    for ( nr=0; nr < 10; nr++){
        port = random_inport();
        printport( port);
        check_keyboard();
        f_delay(5);
    }
    return(0);
}

unsigned char check_keyboard(void){
    if(s.keypressed == 1){
        printf("The key pressed is %d\n", s.allhigh);
    }
    if(s.keypressed == 0){
        s.allhigh = 15;
        printf("No Key pressed HEXADECIMAL \"%02x\"\n", s.allhigh);
    }
}


void f_delay( int tenth_sec){

    clock_t start_t, end_t;
    long int i;
    start_t = clock();
    do{
        for(i=0; i< 10000000; i++);
        end_t = clock();
    }while ((end_t - start_t) < (tenth_sec*CLOCKS_PER_SEC)/10);
    return;
}

unsigned char random_inport( void){
    unsigned int inport = 0;
    int zero = 0;
    inport=  rand() % 256;
    s.keypressed = inport>> 7;
    printf("Inbit 7 is %d ", s.keypressed);
    //printf("before inport %d ", inport);
    if(s.keypressed == 1){
        s.allhigh =inport;
        printf("key pressed");
        return (inport);
    }
    if(s.keypressed == 0){
        s.allhigh =zero;
        printf("key not pressed");
        return (zero);
    }

    return (inport);
}

void printport( int portvalue){
    int binchar[8], rest,j, i=0;
    rest = portvalue;
    while(rest!=0){
        binchar[i++]= rest % 2;
        rest = rest / 2;
    }
    // Fill to 8 bits
    while( i<8){
        binchar[i++]=0;
    }
    // Print bits and at the end corresponding decimal value
    for(j =i-1 ;j > -1;j--)
        printf("  %d",binchar[j]);
    printf(" --------Porten value = %d  \n", portvalue);
    return ;
}


