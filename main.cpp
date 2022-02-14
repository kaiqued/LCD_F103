#include "mbed.h"
#include "LCD_ka.h"
LCD lcd (D8, D9, D4, D5, D6, D7);
AnalogIn Buts(A0);
AnalogIn Ya(A1);
AnalogIn Xa(A2);

int main(){
    lcd.pos(2,2);
    lcd.printf("aaa");
}
