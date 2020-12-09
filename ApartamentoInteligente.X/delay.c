#include "delay.h"


/* funcao delay_ms
 * 
 * parametros: int t
 * retorno: void
 * 
 * descricao:
 * gera um atraso no codigo de aproximadamente t milisegundos 
 */

void delay_ms (int t){
    volatile unsigned char j, k;
    volatile unsigned int i;
    
    for (i = 0; i < (t); i++) {        
        for (j = 0; j < 41; j++) {
            for (k = 0; k < 3; k++);
        }
    }
}