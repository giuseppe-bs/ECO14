#ifndef PORTA_H
#define	PORTA_H

// 0 = fechado 1 = aberto
char estadoPorta = 0;

//0 = trancado 1 = destrancado
char estadoTranca = 0;

//armazena a senha da porta
int senha = -1;

int pow(int ,int);

int defineSenha(int);

char abreFecha(char);

void tranca();

char destranca(int);

void sair();

#endif	/* PORTA_H */

