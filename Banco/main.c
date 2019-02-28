#include <stdio.h>
#include <stdlib.h>
#include ".//nib.h"

#define CLEARNMYSCREEN (system("cls"))

int main(){
    char nib[22],choice;

    while(1)
        {
            CLEARNMYSCREEN;
            showMenu();
            scanf("%c",&choice);
            cleanBuffer();

            if(choice=='7')
                break;

            if( !validMenuChoice(choice) )
                continue;
            
            CLEARNMYSCREEN;
            executeChoice(choice,nib);
            
            printf("(ANY KEY TO CONTINUE)");
            getchar();

        }
    
    CLEARNMYSCREEN;
    printf("TERMINAR...");
    getchar();
    CLEARNMYSCREEN;
    return 0;
}