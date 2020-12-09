# 1 "ssd.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "ssd.c" 2
# 1 "./ssd.h" 1




static const int num[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};




void printTemp(char);


void printSenha(int,char);
# 1 "ssd.c" 2

# 1 "./pic18f4520.h" 1
# 2 "ssd.c" 2

# 1 "./delay.h" 1




void delay_ms(int);
# 3 "ssd.c" 2

# 1 "./porta.h" 1




char estadoPorta = 0;


char estadoTranca = 0;


int senha = -1;

int pow(int ,int);

int defineSenha(int);

char abreFecha(char);

void tranca();

char destranca(int);

void sair();
# 4 "ssd.c" 2
# 16 "ssd.c"
void printTemp(char temp){

    (*(volatile __near unsigned char*)0xF80) = 0x00;
    (*(volatile __near unsigned char*)0xF83) = 0x00;

    (*(volatile __near unsigned char*)0xF83) = num[temp/10];
    (((*(volatile __near unsigned char*)0xF80)) |= (1<<2));

    delay_ms(15);

    (*(volatile __near unsigned char*)0xF80) = 0x00;
    (*(volatile __near unsigned char*)0xF83) = 0x00;

    (*(volatile __near unsigned char*)0xF83) = num[temp % 10];
    (((*(volatile __near unsigned char*)0xF80)) |= (1<<3));

    delay_ms(15);

    (*(volatile __near unsigned char*)0xF80) = 0x00;
    (*(volatile __near unsigned char*)0xF83) = 0x00;

    (*(volatile __near unsigned char*)0xF83) = 0x63;
    (((*(volatile __near unsigned char*)0xF80)) |= (1<<4));

    delay_ms(15);

    (*(volatile __near unsigned char*)0xF80) = 0x00;
    (*(volatile __near unsigned char*)0xF83) = 0x00;

    (*(volatile __near unsigned char*)0xF83) = 0x39;
    (((*(volatile __near unsigned char*)0xF80)) |= (1<<5));

    delay_ms(15);

    (*(volatile __near unsigned char*)0xF80) = 0x00;
    (*(volatile __near unsigned char*)0xF83) = 0x00;
}
# 65 "ssd.c"
void printSenha(int s, char digitado){
    char i,j;
    for(i = 0; i < digitado; i++){
        (*(volatile __near unsigned char*)0xF80) = 0x00;
        (*(volatile __near unsigned char*)0xF83) = 0x00;

        (*(volatile __near unsigned char*)0xF83) = num[(s%pow(10,4-i))/pow(10,3-i)];
        (((*(volatile __near unsigned char*)0xF80)) |= (1<<(i+2)));

        delay_ms(15);
    }
    for(j = i; j < 4;j++){
        (*(volatile __near unsigned char*)0xF80) = 0x00;
        (*(volatile __near unsigned char*)0xF83) = 0x00;

        (*(volatile __near unsigned char*)0xF83) = 0x40;
        (((*(volatile __near unsigned char*)0xF80)) |= (1<<(j+2)));

        delay_ms(15);
    }
    (*(volatile __near unsigned char*)0xF80) = 0x00;
    (*(volatile __near unsigned char*)0xF83) = 0x00;
}
