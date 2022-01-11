#include "LCD_ka.h"

//**** Define as portas que o LCD lê: ****
LCD::LCD(PinName rs, PinName e, PinName d4, PinName d5, PinName d6, PinName d7) : RS(rs), E(e), dados(d4,d5,d6,d7){
    Inicia_LCD();
}


int _coluna = 1;
int _linha = 1;

string LCD::Lepos(void){
    string buffer;
    char li[6];
    sprintf(li,"(%d,%d)", _linha, _coluna);
    buffer.append(li);
    return buffer;
    
}

//**** Comando que indica para o LCD que metade dos bits foram enviados: ****
void LCD::bate_enable(void){
    E = 1;
    wait(0.000040f);
    E=0;
    wait(0.000040f);
}


//**** Função de inicialização do LCD: ****
void LCD::Inicia_LCD(void){
    RS = 0;
    E = 0;
    dados = 0x0;
        
    wait(0.05);
    for (int i=0; i<3; i++){
        // Define como 4 bits
       dados = 0x2;
       bate_enable(); 
       
       wait(0.01);
        
        // Define 0 0 1 DL - N F _ _ 
        //(DL = Data Lengh: 0 --> 4 Bits
        //                  1 --> 8 Bits)
        //(N = n° de linhas:0 --> 1 linha
        //                  1 --> 2 linhas)
        //(F = n° de pontos:0 --> 5 x 8 pontos
        //                  1 --> 5 x 10 pontos)
        dados = 0x2;
        bate_enable();
        dados = 0x8; 
        bate_enable();
        
        wait(0.02);
        
        // Define 0 0 0 0 - 1 D C B 
        //(D = Display on/off: 0 --> off
        //                     1 --> on)
        //(C = Cursor on/off : 0 --> off
        //                     1 --> on)
        //(B = Blink on/off  : 0 --> off
        //                     1 --> on)
        dados = 0x0;
        bate_enable();
        dados = 0xE;
        bate_enable();
        
        wait(0.02);
        
        // Define 0 0 0 0 - 0 1 I/D S
        //(I/D = Direção de escrita: 0 --> Direita
        //                           1 --> Esquerda)
        //(S = Display shift :       0 --> Não
        //                           1 --> Sim)
        dados = 0x0;
        bate_enable();
        dados = 0x6;
        bate_enable();
        }
        
        // Limpa o diplay
        clc(); 
}



//**** Função que limpa o display e volta o cursor para (1,1): ****
void LCD::clc(void){
    wait(0.02);
    
    dados = 0x0;
    bate_enable();
    dados = 0x1;
    bate_enable();
    
    wait(0.02);
    
    _coluna = 1;
    _linha = 1;
}


//**** Função que volta o cursor para (1,1): ****
void LCD::home(void){
    wait(0.002);
    
    dados = 0x0;
    bate_enable();
    dados = 0x2;
    bate_enable();
    
    wait(0.002);
    
    _coluna = 1;
    _linha = 1;
}


//**** Função que manda o cursor para a direita: ****
void LCD::direita(void){
    wait(0.0002);
    
    dados = 0x1;
    bate_enable();
    dados = 0x4;
    bate_enable();
    
    wait(0.0002);
    
    _coluna = _coluna+1;
    
    fim_de_curso(); 
}


//**** Função quem manda o cursor para a esquerda: ****
void LCD::esquerda(void){
    wait(0.0002);
    
    dados = 0x1;
    bate_enable();
    dados = 0x0;
    bate_enable();
    
    wait(0.0002);
    
    _coluna = _coluna - 1;
    
    fim_de_curso();
}


//**** Função que apaga o que está no cursor: ****
void LCD::apaga(void){
    RS = 1;
    
    wait(0.002);
    
    dados = 0x2;
    bate_enable();
    dados = 0x0;
    bate_enable();
    
    RS = 0;
    
    pos(_linha,_coluna);
}


//**** Função que manda o display para linha de cima: ****
void LCD::cima(void){
    pos(1,_coluna);

    _linha = 1;
}


//**** Função que manda o display para linha de baixo: ****
void LCD::baixo(void){
    pos(2,_coluna);
    
    _linha = 2;
}


//**** Função que posiciona o cursor na linha e coluna inseridas: ****
void LCD::pos(int li, int co){
    int POSI = 0x80 + ((li-1) * 0x40) + (co-1);
    
    dados = POSI>>4;
    bate_enable();
    dados = POSI;
    bate_enable();
    
    _coluna = co;
    _linha = li;
}   


//**** Função que define se o cursor saiu do display: ****
void LCD::fim_de_curso (void){
    switch (_coluna)
    {
        case 17 : 
        switch (_linha){
            case 1 : pos(2,1); break;
            case 2 : home(); break;
        }
        break;
        case 0 :
        switch (_linha){
            case 1 : pos(2,16); break;
            case 2 : pos(1,16); break;
        }
        break;
    }
}
    
    
 
 
 
int LCD::_putc(int value) {
    if (value == '\n') {
        baixo();
    }else{
        RS = 1;
        dados = value>>4;
        bate_enable();
        dados = value;
        bate_enable();
        RS = 0;
    }
    _chars[_linha-1][_coluna-1] = value;
    _coluna++;
    fim_de_curso();
    
    return value;
}

int LCD::_getc() {
    return -1;
}