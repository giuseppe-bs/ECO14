#ifndef SSD_H
#define	SSD_H

//vetor com os numeros de 0 a 9 em hexadecimal
static const int num[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x67};

//void init();

//impressão da temperatura
void printTemp(char);

//impressão da senha
void printSenha(int,char);

#endif	/* SSD_H */

