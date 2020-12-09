# 1 "main.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "main.c" 2
# 1 "./config.h" 1
# 38 "./config.h"
#pragma config OSC=HS
#pragma config WDT=OFF
#pragma config LVP=OFF
#pragma config DEBUG = OFF
#pragma config WDTPS = 1
# 1 "main.c" 2

# 1 "./pic18f4520.h" 1
# 2 "main.c" 2

# 1 "./menus.h" 1




void menuLuzes();


void menuArCondicionado();


void menuPorta();


void sair();
# 3 "main.c" 2

# 1 "./lcd.h" 1
# 14 "./lcd.h"
void lcd_init(void);
void lcd_cmd(unsigned char val);
void lcd_dat(unsigned char val);
void lcd_str(const char* str);
# 4 "main.c" 2

# 1 "./teclado.h" 1







    unsigned char tc_tecla(unsigned int timeout);
# 5 "main.c" 2




int main(int argc, char** argv) {

    unsigned char tmp;

    (*(volatile __near unsigned char*)0xFC1) = 0x06;
    (*(volatile __near unsigned char*)0xF93) = 0x01;
    (*(volatile __near unsigned char*)0xF95) = 0x00;
    (*(volatile __near unsigned char*)0xF96) = 0x00;
    (*(volatile __near unsigned char*)0xF92) = 0x00;

    lcd_init();

    (*(volatile __near unsigned char*)0xF93) = 0xF8;


    for(;;){
        lcd_cmd(0x01);
        lcd_cmd(0x80);
        lcd_str("1-Luz");
        lcd_cmd(0x80 +9);
        lcd_str("2-Porta");
        lcd_cmd(0xC0);
        lcd_str("3-AC");
        lcd_cmd(0xC0 +10);
        lcd_str("4-Sair");


        (*(volatile __near unsigned char*)0xF95) = 0x0F;
        tmp = tc_tecla(0);
        (*(volatile __near unsigned char*)0xF95) = 0x00;

        lcd_cmd(0x01);
        switch(tmp){
            case 1:
               menuLuzes();
               break;
            case 2:
                menuPorta();
                break;
            case 3:
                menuArCondicionado();
                break;
            case 4:
                sair();
                break;
        }

    }
}
