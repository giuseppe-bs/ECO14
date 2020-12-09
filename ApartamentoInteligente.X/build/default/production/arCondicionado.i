# 1 "arCondicionado.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "arCondicionado.c" 2
# 1 "./arCondicionado.h" 1








char estado = 0;


char temperatura = 25;


void ligarDesligar(char);


void aumentarTemp(char);


void diminuirTemp(char);
# 1 "arCondicionado.c" 2
# 13 "arCondicionado.c"
void ligarDesligar(char i){
    estado = i;
}
# 27 "arCondicionado.c"
void aumentarTemp(char a){


    if(temperatura + a > 35) temperatura = 35;


    else temperatura += a;
}
# 46 "arCondicionado.c"
void diminuirTemp(char d){


    if(temperatura - d < 15) temperatura = 15;


    else temperatura -= d;
}
