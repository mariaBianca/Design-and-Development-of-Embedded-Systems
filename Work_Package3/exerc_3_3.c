/********************************************
DIT1165 Program file exerc_3_3.c **
2013-01-04 **
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//##### Constants #####
#define MAX 5

//##### Typedefs #####
typedef struct q{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

//##### Function declarations #####
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

int main() {
    printf("Starting application...\n");

    int nr=0;
    REGTYPE *akt_post, *head=NULL;
    srand(time(0)); // Random seed
    head=random_list();
    akt_post=head;
    while(akt_post!=NULL){
        printf("\n Post nr %d : %d" , nr++, akt_post->number);
        akt_post=akt_post->next;
    }
    nr=0;

    //reading int from user
    int user_input;
    printf("\n\nEnter an integer:\n");
    scanf("%d", &user_input);

    //setting new int first on the list
    akt_post = add_first(head, user_input);
    printf("\n\nAfter adding your number first on the list:");
    while(akt_post!=NULL){
        printf("\n Post nr %d : %d" , nr++, akt_post->number);
        akt_post=akt_post->next;
    }

    // --- Free of allocated memory ---
    while((akt_post=head)!=NULL){
        head=akt_post->next;
        free(akt_post);
    }

    printf("\n\n");

    //------------------
    system("PAUSE");

    return 0;
}
//==== End of main ======================================


REGTYPE* random_list(void){
    int nr = rand() % (100), i=0;
    //printf("%d\n", nr);
    REGTYPE *top, *old, *item;

    top = (REGTYPE *) malloc( sizeof(REGTYPE) );
    top->number = nr;
    top->prev = NULL;
    //top = old;
    old = (REGTYPE *) malloc( sizeof(REGTYPE) );
    old->prev = top;
    //top->next = old;

    while(i<MAX-1){
        nr = rand() % (100);
        //printf("%d\n", nr);
        item = (REGTYPE *) malloc( sizeof(REGTYPE) );
        if(i==0){
            top->next = item;
        }
        old->next = item;
        item->number = nr;
        item->prev = old;
        old = item;
        old->next=NULL;
        i++;
    }

//    top->next = malloc( sizeof(struct node) );
//    top = top->next;



    return(top);
}

//==========================================================
REGTYPE* add_first(REGTYPE* temp, int data){
// Adds a record first in the list and sets the field number to data
    REGTYPE *newNode;
    newNode = (REGTYPE *) malloc( sizeof(REGTYPE) );
    newNode->number = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(temp == NULL) {
        return newNode;
    }

    temp->prev = newNode;
    newNode->next = temp;
    return newNode;
}
