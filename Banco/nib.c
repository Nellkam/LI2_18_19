#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include ".//nib.h"



void cleanBuffer(){
    while(getchar()!=(int)'\n');
}

void showMenu(){
    puts("< 1 > Ler NIB");
    puts("< 2 > Indicar Banco do NIB");
    puts("< 3 > Indicar Numero de Conta");
    puts("< 4 > Indicar Numeros de Controlo");
    puts("< 5 > Escrever NIB");
    puts("< 6 > Verificar NIB");
    printf("< 7 > Sair\n-> ");
}

int validMenuChoice (char choice){
    switch (choice){
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
            return 1; // escolha valida
        case '7':
            return -1; // sair
        default:
            return 0; // escolha invalida
    }
}

void readNIB (char* nib){
    printf("Insira NIB (21 digitos): ");
    scanf("%s",nib);
    printf("\n");
    getchar();
}

void showBank (char* nib){
    char bankID[5];
    int i;
    
    bankID[4]='\0';
    for(i=0 ; i<4 ; i++)
        bankID[i]=nib[i];

    if      ( !strcmp(bankID,"0007") )
        puts("Novo Banco\n");
    else if ( !strcmp(bankID,"0010") )
        puts("BPI\n");
    else if ( !strcmp(bankID,"0018") )
        puts("Santander Totta\n");
    else if ( !strcmp(bankID,"0019") )
        puts("BBVA\n");
    else if ( !strcmp(bankID,"0023") )
        puts("Activo Bank\n");
    else if ( !strcmp(bankID,"0025") )
        puts("Caixa BI\n");
    else if ( !strcmp(bankID,"0032") )
        puts("Barclays\n");
    else if ( !strcmp(bankID,"0033") )
        puts("Millennium BCP\n");
    else if ( !strcmp(bankID,"0034") )
        puts("BNP Paribas\n");
    else if ( !strcmp(bankID,"0035") )
        puts("CGD\n");
    else if ( !strcmp(bankID,"0235") )
        puts("Banco Carregosa\n");
    else
        puts("NOT FOUND\n");
    
    printf("\n");
}

void showAccount (char* nib){
    int i,counter=0;

    printf("Numero de Conta: ");
    for ( i=8 ; i<=18 ; i++,counter++ ){
        if(counter==4){
            printf(" ");
            counter=0;
        }
        printf("%c",nib[i]);
    }
        
    printf("\n\n");
}

void showControl (char* nib){    
    printf("Numero de controlo: %c%c\n\n",nib[19],nib[20]); 
}

void showNIB (char* nib){
    int i,counter=0;

    printf("NIB: ");
    for(i=0 ; i<22 ; i++,counter++){
        if(counter==4 && i<=16){
            printf(" ");
            counter=0;
        }
        if (counter==3 && i>=17){
            printf(" ");
            counter=0;
        }
        //printf("\nC:%d I:%d",counter,i);
        printf("%c",nib[i]);
    }
        
    printf("\n\n");
}

void executeChoice(char choice, char* nib){
    switch (choice){
        case '1':
            readNIB(nib);
            break;
        case '2':
            showBank(nib);
            break;
        case '3':
            showAccount(nib);
            break;
        case '4':
            showControl(nib);
            break;
        case '5':
            showNIB(nib);
            break;
        case '6':
            break;
        case '7':
            break;
        default:
            printf ("\n\n\n!!!!! FALHA DE ARGUMENTOS FUNCAO executeChoice !!!!!\n->TERMINAR\n");
            exit(1);        
    }
}