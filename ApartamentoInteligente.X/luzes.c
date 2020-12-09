#include "luzes.h"
#include "pic18f4520.h"


/* funcao ligaLuz
 * 
 * parametros: unsigned char luz
 * retorno: void
 * 
 * descricao:
 * liga o led da posi��o espec�fica de acordo
 * com a vari�vel luz
 */
void ligaLuz(unsigned char luz){
    
    //se luz estiver de acordo com os indices liga o led
    if(luz >= indiceMin && luz <= indiceMax)
        BitSet(estadoLuz,luz);

    //a porta B recebe o estado do led
    PORTB = estadoLuz;
}


/* funcao desligaLuz
 * 
 * parametros: unsigned char luz
 * retorno: void
 * 
 * descricao:
 * desliga o led da posi��o espec�fica de acordo
 * com a vari�vel luz
 */
void desligaLuz(unsigned char luz){

    //se luz estiver de acordo com os indices desliga o led
    if(luz >= indiceMin && luz <= indiceMax)
        BitClr(estadoLuz,luz);
    
    //a porta B recebe o estado do led
    PORTB = estadoLuz;    
}


/* funcao desligaTodasLuzes
 * 
 * parametros: 
 * retorno: void
 * 
 * descricao:
 * desliga todos os leds da porta B
 */
void desligaTodasLuzes(){
    PORTB = estadoLuz = 0x00;
}