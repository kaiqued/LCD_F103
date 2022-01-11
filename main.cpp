#include "mbed.h"
#include "LCD_ka.h"
LCD lcd (D8, D9, D4, D5, D6, D7);
AnalogIn Buts(A0);
AnalogIn Ya(A1);
AnalogIn Xa(A2);

int main(){
    lcd.pos(2,2);
    lcd.printf("aaa");
//  int y = Ya.read()*1000;
//    int x = Xa.read()*1000;
//    while(1){    
//        y = Ya.read()*1000;
//        x = Xa.read()*1000;
//        
//        if ((Buts.read()*1000 > 750) && (Buts.read()*1000 < 850)){
//            lcd.printf("select");
//            wait(0.5);
//        }
//        if ((Buts.read()*1000 > 400) && (Buts.read()*1000 < 500)){
//            lcd.printf("left");
//            wait(0.5);
//        }
//        if ((Buts.read()*1000 > 200) && (Buts.read()*1000 < 300)){
//            lcd.printf("down");
//            wait(0.5);
//        }
//        if ((Buts.read()*1000 > 60) && (Buts.read()*1000 < 150)){
//            lcd.printf("up");
//            wait(0.5);
//        }
//        if ((Buts.read()*1000 > 0) && (Buts.read()*1000 < 50)){
//            lcd.printf("right");
//            wait(0.5);
//        }
//        
//        if((x < 400)||(x > 600)||(y < 400)||(y > 600)){
//            y = Ya.read()*1000;
//            x = Xa.read()*1000;
//            
//            if (x > 900){
//                lcd.direita();
//                wait(0.2);
//            }
//            
//            if (x < 100){
//                lcd.esquerda();
//                wait(0.2);
//            }
//            if (y > 900){
//                lcd.baixo();
//                wait(0.2);
//            }
//            if (y < 100){
//                lcd.cima();
//                wait(0.2);
//            }    
//        }
//            
//        
//    }
}
