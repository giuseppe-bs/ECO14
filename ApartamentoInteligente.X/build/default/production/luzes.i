# 1 "luzes.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "luzes.c" 2
# 1 "./luzes.h" 1








char estadoLuz = 0x00;


void ligaLuz(unsigned char);


void desligaLuz(unsigned char);


void desligaTodasLuzes();
# 1 "luzes.c" 2

# 1 "./pic18f4520.h" 1
# 2 "luzes.c" 2
# 14 "luzes.c"
void ligaLuz(unsigned char luz){


    if(luz >= 3 && luz <= 7)
        ((estadoLuz) |= (1<<luz));


    (*(volatile __near unsigned char*)0xF81) = estadoLuz;
}
# 34 "luzes.c"
void desligaLuz(unsigned char luz){


    if(luz >= 3 && luz <= 7)
        ((estadoLuz) &= ~(1<<luz));


    (*(volatile __near unsigned char*)0xF81) = estadoLuz;
}
# 53 "luzes.c"
void desligaTodasLuzes(){
    (*(volatile __near unsigned char*)0xF81) = estadoLuz = 0x00;
}
