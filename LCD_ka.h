#ifndef LCD_H
#define LCD_H
#include "mbed.h"

// Comando que indica para o LCD que metade dos bits foram enviados:
void bate_enable(void);


// Função de inicialização do LCD:
void Inicia_LCD(void);


// Função que recebe string e escreve no display:
void disp(char* value);


// Função que limpa o display e volta o cursor para (1,1):
void clc(void);

// Função que volta o cursor para (1,1):
void home(void);


// Função que manda o cursor para a direita:
void direita(void);


// Função quem manda o cursor para a esquerda:
void esquerda(void);


// Função que apaga o que está no cursor:
void apaga(void);


// Função que manda o display para linha de cima:
void cima(void);


// Função que manda o display para linha de baixo:
void baixo(void);


// Função que posiciona o cursor na linha e coluna inseridas:
void pos(int linha, int coluna);


// Função que define se o cursor saiu do display:
void fim_de_curso(void);




#endif
