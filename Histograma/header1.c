#include <ctype.h>
#include <stdio.h>
#include ".//headers//header1.h"

void cleanBuffer(){
    while( getchar()!=(int)'\n' );
}

void addLetter (char histograma[][HISTOCOL], char ch){
    int letterIndex,line=HISTOLINES-2; // (-2) linha logo acima das letras

    if ( (int)ch<65 || ((int)ch>90 && (int)ch<97) || (int)ch>122 )
        return;
    
    letterIndex=toupper(ch) - 65;

    while(line!=-1 && histograma[line][letterIndex]!='0') // empty line to add *
        line--;

    if(line==-1){
        puts("\n\n!!!!?? DEMASIADAS OCORRENCIAS: AUMENTAR TAMANHO ARRAY !!!!!!?????\n\n");
        getchar();
        exit(1);
    }

    histograma[line][letterIndex]='*';    
}

void printHistograma(char histograma[][HISTOCOL]){
    int line=0,col=0;

    for( line=0 ; line<HISTOLINES ; line++ ){
        
        for( col=0 ; col<HISTOCOL ; col++){
        
            if(histograma[line][col]=='0'){
                printf("   ");
                continue;
            }

            printf(" %c ",histograma[line][col]);
        }
        
        putchar('\n');
    }
}

void resetHistograma (char histograma[][HISTOCOL]){
    int line,col,charAscii=65;

    for (line=0 ; line<HISTOLINES ; line++){

        for ( col=0 ; col<HISTOCOL ; col++){
            if ( line==HISTOLINES-1 ){
                histograma[line][col]=(char) charAscii;
                charAscii++;
                continue;
            }

            histograma[line][col]='0';
        }
    }
}