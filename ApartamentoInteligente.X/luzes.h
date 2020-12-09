#ifndef LUZES_H
#define	LUZES_H

//define os indices minimo e maximo dos leds
#define indiceMin 3
#define indiceMax 7

//inicializa o estado inicial da luz como 0x00
char estadoLuz = 0x00;

//liga um led
void ligaLuz(unsigned char);

//desliga um le
void desligaLuz(unsigned char);

//desliga todos os leds
void desligaTodasLuzes();

#endif	/* LUZES_H */

