#ifndef ARCONDICIONADO_H
#define	ARCONDICIONADO_H

//definição dos valores máximo e minimo da temperatura
#define maxTemp 35
#define minTemp 15

//estado do ar condicionado desligado(0) e ligado(1)
char estado = 0;

//define a temperatura inicial
char temperatura = 25;

//altera o estado do ar condicionado
void ligarDesligar(char);

//aumenta a temperatura 
void aumentarTemp(char);

//diminui a temperatura
void diminuirTemp(char);

#endif	/* ARCONDICIONADO_H */

