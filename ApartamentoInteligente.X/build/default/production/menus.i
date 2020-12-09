# 1 "menus.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "menus.c" 2
# 1 "./menus.h" 1




void menuLuzes();


void menuArCondicionado();


void menuPorta();


void sair();
# 1 "menus.c" 2

# 1 "./lcd.h" 1
# 14 "./lcd.h"
void lcd_init(void);
void lcd_cmd(unsigned char val);
void lcd_dat(unsigned char val);
void lcd_str(const char* str);
# 2 "menus.c" 2

# 1 "./teclado.h" 1







    unsigned char tc_tecla(unsigned int timeout);
# 3 "menus.c" 2

# 1 "./pic18f4520.h" 1
# 4 "menus.c" 2

# 1 "./arCondicionado.h" 1








char estado = 0;


char temperatura = 25;


void ligarDesligar(char);


void aumentarTemp(char);


void diminuirTemp(char);
# 5 "menus.c" 2

# 1 "./ssd.h" 1




static const int num[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};




void printTemp(char);


void printSenha(int,char);
# 6 "menus.c" 2

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
# 7 "menus.c" 2

# 1 "./luzes.h" 1








char estadoLuz = 0x00;


void ligaLuz(unsigned char);


void desligaLuz(unsigned char);


void desligaTodasLuzes();
# 8 "menus.c" 2

# 1 "./delay.h" 1




void delay_ms(int);
# 9 "menus.c" 2
# 21 "menus.c"
void menuTranca(char opcao){


    lcd_cmd(0x01);


    unsigned char tmp = 0;
    char digitado = 0;
    int entrada = -1;
    char tentativas = 3;


    if(senha != -1){
        lcd_cmd(0x80 +5);
        lcd_str("Insira");
        lcd_cmd(0xC0 +5);
        lcd_str("a senha");

    }else{


        if(opcao == 4){
            lcd_cmd(0x80 +5);
            lcd_str("Insira");
            lcd_cmd(0xC0 +2);
            lcd_str("a nova senha");
        }
        else{


            if (opcao == 1){
                lcd_cmd(0x80 +1);
                lcd_str("Porta Aberta");
                destranca(entrada);
                abreFecha(1);

            } else{


                lcd_cmd(0x80);
                lcd_str("Porta destrancada");
                destranca(entrada);
            }
            lcd_cmd(0xC0 +2);
            lcd_str("com sucesso");
            delay_ms(1500);
            return;
        }
    }

    entrada = 0;
    for(;;){
        printSenha(entrada,digitado);


        (*(volatile __near unsigned char*)0xF95) = 0x0F;
        tmp = tc_tecla(15);
        (*(volatile __near unsigned char*)0xF95) = 0x00;


        if(tmp != 255){
            digitado++;
            entrada += tmp * pow(10,4-digitado);


            if(digitado == 4){


                if(opcao != 4){



                    if(destranca(entrada)){
                        lcd_cmd(0x01);
                         if (opcao == 1){
                            lcd_cmd(0x80 +1);
                            lcd_str("Porta Aberta");
                            abreFecha(1);
                        } else{
                            lcd_cmd(0x80);
                            lcd_str("Porta destrancada");
                        }
                        return;
                    }


                    else{


                        digitado = 0;
                        entrada = 0;
                        lcd_cmd(0x80 +5);
                        lcd_str("Senha");
                        lcd_cmd(0xC0 +5);
                        lcd_str("Incorreta");


                        tentativas--;
                        delay_ms(1500);
                        lcd_cmd(0x01);


                        if(!tentativas)
                            return;


                        else{
                            lcd_cmd(0x80 +5);
                            lcd_str("Insira");
                            lcd_cmd(0xC0 +5);
                            lcd_str("a senha");
                        }
                    }
                }else{
                    defineSenha(entrada);

                    lcd_cmd(0x01);
                    lcd_cmd(0x80 +2);
                    lcd_str("nova senha");
                    lcd_cmd(0xC0 +5);
                    lcd_str("definida");

                    delay_ms(2000);
                    return;
                }
            }
        }
    }
}
# 161 "menus.c"
void menuPorta(){


    unsigned char tmp = 0;

    for(;;){


        lcd_cmd(0x01);
        lcd_cmd(0x80);

        if(estadoPorta)
            lcd_str("1-Fechar");


        else
            lcd_str("1-Abrir");
        lcd_cmd(0x80 +10);


        lcd_str("3-sair");
        lcd_cmd(0xC0);


        if(estadoTranca)
            lcd_str("2-Lock");


        else
            lcd_str("2-UnLock");


        lcd_cmd(0xC0 +10);
        lcd_str("4-pswd");


        (*(volatile __near unsigned char*)0xF95) = 0x0F;
        tmp = tc_tecla(0);
        (*(volatile __near unsigned char*)0xF95) = 0x00;

        switch(tmp){


            case 1:
                if(estadoPorta) {
                    abreFecha(0);
                    lcd_cmd(0x01);
                    lcd_cmd(0x80 +1);
                    lcd_str("Porta Fechada");
                    lcd_cmd(0xC0);
                    lcd_str("com sucesso");
                    delay_ms(1500);

                }


                else
                    menuTranca(1);
                break;
            case 2:


                if(estadoTranca) {
                    tranca();
                    lcd_cmd(0x01);
                    lcd_cmd(0x80 +1);
                    lcd_str("Porta Trancada");
                    lcd_cmd(0xC0 +1);
                    lcd_str("com sucesso");
                    delay_ms(1500);
                    abreFecha(0);
                }


                else
                    menuTranca(2);
                break;
            case 3:
                lcd_cmd(0x01);
                return;
                break;


            case 4:
                menuTranca(4);
                break;
        }
    }
}
# 260 "menus.c"
void menuManipLuzes(char opcao){


    char i;
    unsigned char tmp;
    lcd_cmd(0x01);

    for(;;){


    lcd_cmd(0x80);
    if(opcao)lcd_str("ligar");
    else lcd_str("Desligar");
    lcd_cmd(0x80 +11);
    lcd_str("34567");
    lcd_cmd(0xC0);
    lcd_str("1-sair");
    lcd_cmd(0xC0 +11);

    for(i = 3; i<8; i++)
        lcd_dat((((estadoLuz) & (1<<i))?'I':'O'));


    (*(volatile __near unsigned char*)0xF95) = 0x0F;
    tmp = tc_tecla(0);
    (*(volatile __near unsigned char*)0xF95) = 0x00;
    switch(tmp){
        case 1:
            lcd_cmd(0x01);
            return;
        default:

            if(opcao){
                (*(volatile __near unsigned char*)0xF93)=0x00;
                (*(volatile __near unsigned char*)0xF81)=estadoLuz;
                lcd_cmd(0x01);
                lcd_cmd(0x80 +5);
                lcd_str("ligando");
                lcd_cmd(0xC0 +4);
                lcd_str("a luz ");
                lcd_dat(tmp);
                delay_ms(1000);
                ligaLuz(tmp);
                delay_ms(1000);
                lcd_cmd(0x01);
                (*(volatile __near unsigned char*)0xF93)=0x78;
            }
            else{


                (*(volatile __near unsigned char*)0xF93)=0x00;
                (*(volatile __near unsigned char*)0xF81)=estadoLuz;
                lcd_cmd(0x01);
                lcd_cmd(0x80 +4);
                lcd_str("desligando");
                lcd_cmd(0xC0 +4);
                lcd_str("a luz ");
                lcd_dat(tmp);
                delay_ms(1000);
                desligaLuz(tmp);
                delay_ms(1000);
                lcd_cmd(0x01);
                (*(volatile __near unsigned char*)0xF93)=0x78;
            }
        }
    }

}
# 339 "menus.c"
void menuLuzes(){


    unsigned char tmp;

    for(;;){


        lcd_cmd(0x80);
        lcd_str("1-ligar");


        lcd_cmd(0x80 +10);
        lcd_str("3-sair");


        lcd_cmd(0xC0);
        lcd_str("2-desligar");


        (*(volatile __near unsigned char*)0xF95) = 0x0F;
        tmp = tc_tecla(0);
        (*(volatile __near unsigned char*)0xF95) = 0x00;

        switch(tmp){


            case 1:
                menuManipLuzes(1);
                break;


            case 2:
                menuManipLuzes(0);
                break;


            case 3:
                lcd_cmd(0x01);
                return;
                break;
        }
    }
}
# 394 "menus.c"
void menuAumentaDiminuiAC(){


    unsigned char tmp;

    lcd_cmd(0x01);
    lcd_cmd(0x80);
    lcd_str("1-Aumentar");
    lcd_cmd(0xC0);
    lcd_str("2-Diminuir");
    lcd_cmd(0xC0 +11);
    lcd_str("3-EXT");

    for(;;){


        printTemp(temperatura);


        (*(volatile __near unsigned char*)0xF95) = 0x0F;
        tmp = tc_tecla(15);
        (*(volatile __near unsigned char*)0xF95) = 0x00;


        switch(tmp){


            case 1:
                aumentarTemp(1);
                break;


            case 2:
                diminuirTemp(1);
                break;


            case 3:
                lcd_cmd(0x01);
                return;
                break;
        }
    }

}
# 450 "menus.c"
void menuArCondicionado(){


    unsigned char tmp;

    for(;;){


        if(estado == 0){


            lcd_cmd(0x80);
            lcd_str("1-ligar AC");
            lcd_cmd(0xC0);
            lcd_str("2-voltar");


            (*(volatile __near unsigned char*)0xF95) = 0x0F;
            tmp = tc_tecla(0);
            (*(volatile __near unsigned char*)0xF95) = 0x00;

            switch(tmp){


                case 1:
                    ligarDesligar(1);
                    lcd_cmd(0x01);
                    break;


                case 2:
                    lcd_cmd(0x01);
                    return;
                    break;
            }


        }else{


            lcd_cmd(0x80);
            lcd_str("1-Mudar Temp");
            lcd_cmd(0xC0);
            lcd_str("2-Desligar");
            lcd_cmd(0xC0 +10);
            lcd_str("3-sair");


            (*(volatile __near unsigned char*)0xF95) = 0x0F;
            tmp = tc_tecla(0);
            (*(volatile __near unsigned char*)0xF95) = 0x00;


            switch(tmp){


                case 1:
                    menuAumentaDiminuiAC();
                    tmp = 0;
                    break;


                case 2:
                    ligarDesligar(0);
                    lcd_cmd(0x01);
                    break;


                case 3:
                    lcd_cmd(0x01);
                    return;
                    break;
            }
        }
    }
}
# 537 "menus.c"
void sair(){

    (*(volatile __near unsigned char*)0xF93) = 0x00;
    (*(volatile __near unsigned char*)0xF81)=estadoLuz;


    lcd_cmd(0x01);
    lcd_cmd(0x80 +4);
    lcd_str("Desligando");
    lcd_cmd(0xC0 +2);
    lcd_str("Ar Condicionado");

    ligarDesligar(0);

    delay_ms(2000);



    lcd_cmd(0x01);
    lcd_cmd(0x80 +4);
    lcd_str("Desligando");
    lcd_cmd(0xC0 +5);
    lcd_str("As luzes");

    desligaTodasLuzes();
    delay_ms(2000);



    lcd_cmd(0x01);
    lcd_cmd(0x80 +4);
    lcd_str("Trancando");
    lcd_cmd(0xC0 +2);
    lcd_str("a porta");

    tranca();
    abreFecha(0);

    delay_ms(2000);

    (*(volatile __near unsigned char*)0xF93) = 0x78;


    lcd_cmd(0x01);
    lcd_cmd(0x80 +4);
    lcd_str("1-entrar");

    unsigned char tmp = 0;
    for(;;){

        (*(volatile __near unsigned char*)0xF95) = 0x0F;
        tmp = tc_tecla(0);
        (*(volatile __near unsigned char*)0xF95) = 0x00;


        if(tmp == 1){
            if(senha != -1){
                menuTranca(1);
            }
            abreFecha(1);
            return;
        }
    }
}
