#ifndef LCD_H
#define LCD_H
#include "mbed.h"
#include <string>
#include <stdio.h>
class LCD : public Stream {
public:
    LCD(PinName rs, PinName e, PinName d4, PinName d5, PinName d6, PinName d7);
    
    string Lepos(void);
    
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

//**** Variáveis que o código utiliza para funções internas: ****    
    DigitalOut RS, E;
    BusOut dados;
    int _coluna;
    int _linha;
    char _chars[2][16];

// Stream implementation functions
    virtual int _putc(int value);
    virtual int _getc();
};
  
#endif
