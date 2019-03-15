#include ".//headers//auxiliares.h"

// limpa buffer
void clearBuffer(){
    while(getchar()!='\n');
}


// imprime menu inicial
void showMenu(){
    puts(" < 1 > Mostrar Tabuleiro");
    puts(" < 2 > Alterar Tabuleiro");
    puts(" < 3 > Load Tabuleiro (Ficheiro)");
    puts(" < 4 > Save Tabuleiro (Ficheiro)");
    puts(" < 5 > Sair");
    printf(" -> ");
}


// abre ficheiro, le tabuleiro e coloca no programa
void loadTabuleiro (char tabuleiro[][TAB_C],int dimensao[2]){
    int linha=0;
    FILE *myFile = fopen(FILENAME,"r");

    if(!myFile){
        printf("\n\n!!! ERRO LEITURA FICHEIRO !!!!\n\n");
        getchar();
        exit(1);
    }
    fscanf(myFile,"%d %d",dimensao,dimensao+1); // le 1º linha dimensao
    fgetc(myFile); // remove \n

    for (linha=0 ; linha<dimensao[0] ; linha++){
        fgets( &(tabuleiro[linha][0]) , dimensao[1]+2 , myFile );
    }

    fclose(myFile);
}

// guarda o tabuleiro actual do programa no ficheiro
void saveTabuleiro ( char tabuleiro[][TAB_C], int dimensao[2] ){
    int linhas;
    FILE *myFile = fopen(FILENAME,"w");
    
    fprintf(myFile,"%d %d\n",dimensao[0],dimensao[1]);

    for(linhas=0 ; linhas<dimensao[0] ; linhas++)
        fprintf(myFile,"%s", &(tabuleiro[linhas][0])  );

    fclose(myFile);  
}

// print tabuleiro actual no ecra
void showTabuleiro ( char tabuleiro[][TAB_C] , int dimensao[2] ){
    int linhas=0;

    for(linhas=0 ; linhas<dimensao[0] ; linhas++)
        printf("%s", &(tabuleiro[linhas][0]) );

}

// altera um elemento do tabuleiro
void setTabuleiro(char tabuleiro[][TAB_C],int dimensao[2],int linha, int coluna, char elemento){
    linha--;
    coluna--;
    if  (
            linha<0 || coluna<0 || 
            linha>=dimensao[0] || coluna>=dimensao[1]
        )
        {
            printf("\n!Posicao Invalida!\n\n");
            getchar();
            return;
        }

    if(elemento!='X' && elemento!='O' && elemento!='.'){
        printf("\n!Caracter Invalido!\n\n");
        getchar();
        return;
    }
    
    tabuleiro[linha][coluna]=elemento;
}

// mete todos elementos do tabuleiro com '.'
void resetTabuleiro (char tabuleiro[][TAB_C],int dimensao[2]){
    int linhas=0,colunas=0;

    for(linhas ; linhas<dimensao[0] ; linhas++){
        for(colunas=0; colunas<dimensao[1] ; colunas++)
            tabuleiro[linhas][colunas]='.';
        tabuleiro[linhas][colunas]='\n';
        tabuleiro[linhas][colunas+1]='\0';
    }
}



// retorna se escolha do menu é valida ou nao. (1-valida,0-invalida)
int validMenuChoice(char choice){
    return !(choice!='1' && choice!='2' && choice!='3' && choice!='4' && choice!='5');
}
