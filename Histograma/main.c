#include <stdio.h>
#include ".//headers//header1.h"

int main(){
    char histograma[HISTOLINES][HISTOCOL];
    char ch,text[102];
    int index=0;

    CLEARMYSCREEN;

    resetHistograma(histograma);

    printf("\nInsira uma linha de texto\n-> ");
    fgets(text,102,stdin);

    while( text[index]!='\n' && text[index]!='\0' ){
        addLetter(histograma, text[index] );
        index++;
    }
        
    putchar('\n');
    printHistograma(histograma);

    getchar();
    return 0;
}