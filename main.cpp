#include "mbed.h"
#include "LCD_ka.h"
AnalogIn Ya(A1);
AnalogIn Xa(A2);
DigitalIn botao(D3);

int main(){
    Inicia_LCD();
    int y = Ya.read()*1000;
    int x = Xa.read()*1000;
    disp("Josueb6$#@!");
    
    while(1){
        int y = Ya.read()*1000;
        int x = Xa.read()*1000;
        wait(0.00002);
        if (botao == 0){
            apaga();
            wait(0.3);
        }
        if((x < 400)||(x > 600)||(y < 400)||(y > 600)){
            int y = Ya.read()*1000;
            int x = Xa.read()*1000;
            
            if (x > 900){
                direita();
                wait(0.2);
            }
            if (y > 900){
                baixo();
                wait(0.2);
            }
            if (x < 100){
                esquerda();
                wait(0.2);
            }
            if (y < 100){
                cima();
                wait(0.2);
            }    
        }
    }
}
