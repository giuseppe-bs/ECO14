#include "config.h"
#include "pic18f4520.h"
#include "menus.h"//Biblioteca para os menus
#include "lcd.h"//Biblioteca para o funcionamento do lcd
#include "teclado.h"//Biblioteca para o funcionamento do teclado



int main(int argc, char** argv) {//Fun��o main
    
    unsigned char tmp;//Defini��o das vari�veis
    
    ADCON1 = 0x06;
    TRISB = 0x01;//Inicializa porta B 
    TRISD = 0x00;//Inicializa porta D
    TRISE = 0x00;//Inicializa porta E
    TRISA = 0x00;//Inicializa porta A

    lcd_init(); 
   
    TRISB = 0xF8;//Inicializa porta B
   
    
    for(;;){//Looping infinito que garante a impress�o continua das informa��es na tela
        lcd_cmd(L_CLR);//Limpa a tela do LCD
        lcd_cmd(L_L1);//Imprime na primeira linha do LCD
        lcd_str("1-Luz");//Imprime a op��o 1 para controlar as luzes no LCD
        lcd_cmd(L_L1+9);//Imprime na posi��o 9 da primeira linha
        lcd_str("2-Porta");//Imprime a op��o 2 para controlar a tranca da porta no LCD
        lcd_cmd(L_L2);//Imprime na segunda linha
        lcd_str("3-AC");//Imprime a op��o 3 para controlar o ar condicionado no LCD
        lcd_cmd(L_L2+10);//Imprime na posi��o 10 da segunda linha
        lcd_str("4-Sair");//Imprime a op��o 4 para sair no LCD
        
        
        TRISD = 0x0F;//Inicializa porta D para a leitura
        tmp = tc_tecla(0);//tmp recebe o valor digitado no teclado
        TRISD = 0x00;//Fim da leitura
        
        lcd_cmd(L_CLR);//Limpa a tela do LCD
        switch(tmp){//Realiza a fun��o de acordo com o valor de tmp
            case 1://Se o valor for 1
               menuLuzes();//Chama a fun��o menuLuzes
               break;//Sai do caso
            case 2://Se o valor for 2
                menuPorta();//Chama a fun��o menuPorta
                break;//Sai do caso
            case 3://Se o valor for 3
                menuArCondicionado();
                break;//Sai do caso
            case 4://Se o valor for 4
                sair();//Chama a fun��o sair
                break;//Sai do caso
        }//Fim da switch
        
    }//Fim do looping inifinito   
}//Fim da main

