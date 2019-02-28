#include <stdlib.h>

#ifndef __HEADER1__
#define __HEADER1__

#define HISTOLINES 10
#define HISTOCOL   26

#define CLEARMYSCREEN (system("cls"))

void cleanBuffer();
void addLetter (char histograma[][HISTOCOL], char);
void printHistograma(char histograma[][HISTOCOL]);
void resetHistograma (char histograma[][HISTOCOL]);

#endif