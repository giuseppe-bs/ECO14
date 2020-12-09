#include "ssd.h"
#include "pic18f4520.h"
#include "delay.h"
#include "porta.h"


/*Funcao: printTemp
 * 
 * parametros: char temp
 * retorno: void
 * 
 * descrição:
 * configura os displays para a impressão da temperatura
 */

void printTemp(char temp){
    
    PORTA = 0x00;//desliga os displays
    PORTD = 0x00;//desliga a porta D
                
    PORTD = num[temp/10];//define o que sera impresso 
    BitSet(PORTA,2);
    
    delay_ms(15);
    
    PORTA = 0x00;//desliga os displays
    PORTD = 0x00;//desliga a porta D
                
    PORTD = num[temp % 10];//define o que sera impresso 
    BitSet(PORTA,3);
    
    delay_ms(15);
    
    PORTA = 0x00;//desliga os displays
    PORTD = 0x00;//desliga a porta D
                
    PORTD = 0x63;//define o que sera impresso 
    BitSet(PORTA,4);
    
    delay_ms(15);
    
    PORTA = 0x00;//desliga os displays
    PORTD = 0x00;//desliga a porta D
                
    PORTD = 0x39;//define o que sera impresso 
    BitSet(PORTA,5);
    
    delay_ms(15);
    
    PORTA = 0x00;//desliga os displays
    PORTD = 0x00;//desliga a porta D
}


/*Funcao: printSenha
 * 
 * parametros: int s, char digitado
 * retorno: void
 * 
 * descrição:
 * configura os lcd para fazer a impressão da 
 * senha que está sendo definida
 */

void printSenha(int s, char digitado){
    char i,j;//definição das variáveis
    for(i = 0; i < digitado; i++){
        PORTA = 0x00;//desliga os displays
        PORTD = 0x00;//desliga a porta D
                
        PORTD = num[(s%pow(10,4-i))/pow(10,3-i)];//define o que sera impresso 
        BitSet(PORTA,(i+2));
    
        delay_ms(15);
    } 
    for(j = i; j < 4;j++){
        PORTA = 0x00;//desliga os displays
        PORTD = 0x00;//desliga a porta D
                
        PORTD = 0x40;//define o que sera impresso 
        BitSet(PORTA,(j+2));
    
        delay_ms(15);
    }
    PORTA = 0x00;//desliga os displays
    PORTD = 0x00;//desliga porta D
}