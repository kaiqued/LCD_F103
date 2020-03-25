
#include "LCD_ka.h"

DigitalOut RS(D8);
DigitalOut E(D9);
BusOut dados(D4, D5, D6, D7);

void bate_enable(void){
    E = 1;
    wait(0.002);
    E=0;
    wait(0.002);
}

void Inicia_LCD(void){
    wait(0.15);
    RS = 0;
    E = 0;
    
    dados = 0x2;
    bate_enable();
    dados = 0x8;
    bate_enable();
    
    dados = 0x0;
    bate_enable();
    dados = 0xE;
    bate_enable();
    
    dados = 0x0;
    bate_enable();
    dados = 0x1;
    bate_enable();
}


void disp(char *value){
    
    for (int i = 0; value[i] != '\0';++i){
        RS = 1;
        wait(0.002);
        char txt = value[i];
        dados = txt>>4;
        bate_enable();
        dados = txt;
        bate_enable();
    RS = 0;
    }
}


void clc(void){
    wait(0.002);
    dados = 0x0;
    bate_enable();
    dados = 0x1;
    bate_enable();
}
