#include "arCondicionado.h"


/*Funcao: ligarDesligar
 * 
 * parametros: char i
 * retorno: void
 * 
 * descricao:
 * altera o estado do ar condicinado de acordo
 * com o valor de i desligado(0) ou  ligado(1)
 */
void ligarDesligar(char i){
    estado = i;//altera o estado do arr condicionado
}


/*Funcao: aumentarTemp
 * 
 * parametros: char a
 * retorno: void
 * 
 * descricao:
 * aumenta o valor da temperatura de acordo
 * com a, até o valor máximo
 */
void aumentarTemp(char a){    

    //Se a temperatura+a for maior que o maximo, a temperatura será o valor máximo
    if(temperatura + a > maxTemp) temperatura = maxTemp;

    //caso contrário será temperatura + a
    else temperatura += a;
}


/*Funcao: diminuirTemp
 * 
 * parametros: char d
 * retorno: void
 * 
 * descricao:
 * diminui o valor da temperatura de acordo
 * com d, até o valor mínimo
 */
void diminuirTemp(char d){    

    //Se a temperatura-d for menor que o minimo, a temperatura será o valor mínimo
    if(temperatura - d < minTemp) temperatura = minTemp;

    //caso contrário será temperatura - d
    else temperatura -= d;
}


