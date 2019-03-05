#include <stdio.h>
#include <stdlib.h>


#ifndef __AUXILIARES1___
#define __AUXILIARES1___

#define TAB_L 40
#define TAB_C 42
#define FILENAME ".//tabuleiro.txt"
#define CLEARMYSCREEN (system("cls"))

void clearBuffer();
void showMenu();
void loadTabuleiro (char [][TAB_C],int [2]);
void saveTabuleiro ( char [][TAB_C], int [2] );
void showTabuleiro ( char [][TAB_C] , int [2] );
void setTabuleiro(char [][TAB_C],int [2],int,int,char);
void resetTabuleiro (char [][TAB_C],int [2]);
int validMenuChoice(char);

#endif




