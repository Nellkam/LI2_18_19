#include ".//headers//auxiliares.h"


int main(){
    char tabuleiro[TAB_L][TAB_C];
    int dimensao[2]={3,4};
    int linha,coluna;
    char choice;

    resetTabuleiro(tabuleiro,dimensao);

    // menu inicial
    GOTO_MENUINI:
    do{
        CLEARMYSCREEN;
        showMenu();
        choice=getchar();
        clearBuffer();
        CLEARMYSCREEN;
    } while (!validMenuChoice(choice));

    // executa escolha do menu
    switch (choice){
        case '1': 
            showTabuleiro(tabuleiro,dimensao);
            break;
        
        case '2':
            printf(" Insira linha e coluna\n -> ");
            scanf("%d %d",&linha,&coluna);
            clearBuffer();
            printf(" Insira elemento de substituicao (X,O,.)\n -> ");
            choice=getchar();
            clearBuffer();
            setTabuleiro(tabuleiro,dimensao,linha,coluna,choice);
            break;
        
        case '3':
            loadTabuleiro(tabuleiro,dimensao);
            break;
        
        case '4':
            saveTabuleiro(tabuleiro,dimensao);
            break;
            
        case '5':
            return 0;
    }
    
    printf("\n\nPress to continue....");
    getchar();
    clearBuffer();
    CLEARMYSCREEN;
    goto GOTO_MENUINI;

    return 0;
}
