#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


/*
 *
 *
 * Pack and unpack variables into a byte. You need to store 4 different values in a byte. The values are:
Name Range Bits Info
engine_on 0..1 1 Is engine on or off
gear_pos 0..4 3 What gear position do we have
key_pos 0..2 2 What position is the key in
brake1 0..1 1 Are we breaking (told by sensor 1)
brake2 0..1 1 Are we breaking (told by sensor 2) = bit nr 0
 */


struct s1 {
    unsigned char engine_on : 1;
    unsigned char gear_pos : 3;
    unsigned char key_pos : 2;
    unsigned char brake1 : 1;
    unsigned char brake2 : 1;
} s;


int main(int argc, char **argv ) {

    for (int j = 0; j < argc; j++) {
        printf("Decode argc=%d arg %d is %s\n", argc, j, argv[j]);
    }

    printf("%d\n", argc);
    printf("%c\n", *argv[1] + 1);


    unsigned int k = 0;
    switch(*argv[1] + 0){
        case '0': k|= (0<<4); printf("0000"); break; //int 0
        case '1': k|= (1<<4); printf("0001"); break; //int 1
        case '2': k|= (2<<4); printf("0010"); break; //int 2
        case '3': k|= (3<<4); printf("0011"); break; //int 3
        case '4': k|= (4<<4); printf("0100"); break; //int 4
        case '5': k|= (5<<4); printf("0101"); break; //int 5
        case '6': k|= (6<<4); printf("0110"); break; //int 6
        case '7': k|= (7<<4); printf("0111"); break; //int 7
        case '8': k|= (8<<4); printf("1000"); break; //int 8
        case '9': k|= (9<<4); printf("1001"); break; //int 9
        case 'A': k|= (10<<4); printf(" k with only a : %d\n", k); printf("1010"); break; //int 10
        case 'B': k|= (11<<4); printf("1011"); break; //int 11
        case 'C': k|= (12<<4); printf("1100"); break; //int 12
        case 'D': k|= (13<<4); printf("1101"); break; //int 13
        case 'E': k|= (14<<4); printf("1110"); break; //int 14
        case 'F': k|= (15<<4); printf("1111"); break; //int 15
        case 'a': k|= (10<<4); printf("1010"); break; //int 10
        case 'b': k|= (11<<4); printf("1011"); break; //int 11
        case 'c': k|= (12<<4); printf("1100"); break; //int 12
        case 'd': k|= (13<<4); printf("1101"); break; //int 13
        case 'e': k|= (14<<4); printf("1110"); break; //int 14
        case 'f': k|= (15<<4); printf("1111"); break; //int 15
        default:  printf("\nInvalid hexadecimal digit %s ",argv[1]); return exit(2);
    }


    switch(*argv[1] + 1){
        case '0': k|= (0<<0); printf("0000"); break; //int 0
        case '1': k|= (1<<0); printf("0001"); break; //int 1
        case '2': k|= (2<<0); printf("0010"); break; //int 2
        case '3': k|= (3<<0); printf("0011"); break; //int 3
        case '4': k|= (4<<0); printf("0100"); break; //int 4
        case '5': k|= (5<<0); printf("0101"); break; //int 5
        case '6': k|= (6<<0); printf("0110"); break; //int 6
        case '7': k|= (7<<0); printf("0111"); break; //int 7
        case '8': k|= (8<<0); printf("1000"); break; //int 8
        case '9': k|= (9<<0); printf("1001"); break; //int 9
        case 'A': k|= (10<<0); printf(" k : %d\n", k); printf("1010"); break; //int 10
        case 'B': k|= (11<<0); printf("\n k with b : %d\n", k); printf("1011"); break; //int 11
        case 'C': k|= (12<<0); printf("1100"); break; //int 12
        case 'D': k|= (13<<0); printf("1101"); break; //int 13
        case 'E': k|= (14<<0); printf("1110"); break; //int 14
        case 'F': k|= (15<<0); printf("1111"); break; //int 15
        case 'a': k|= (10<<0); printf("1010"); break; //int 10
        case 'b': k|= (11<<0); printf("1011"); break; //int 11
        case 'c': k|= (12<<0); printf("1100"); break; //int 12
        case 'd': k|= (13<<0); printf("1101"); break; //int 13
        case 'e': k|= (14<<0); printf("1110"); break; //int 14
        case 'f': k|= (15<<0); printf("1111"); break; //int 15
        default:  printf("\nInvalid hexadecimal digit %s ",argv[1]); return exit(2);
    }

    s.engine_on = k>>7;
    printf("engine is %d\n", s.engine_on);
    s.gear_pos = k>>4;
    printf("gear is %d\n", s.gear_pos);
    s.key_pos = k>>2;
    printf("keypos is %d\n", s.key_pos);
    s.brake1 = k>>1;
    printf("brake is %d\n", s.brake1);
    s.brake2 = k>>0;
    printf("brake is %d\n", s.brake2);


    return 0;
}