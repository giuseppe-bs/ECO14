// -----------------------------------------------------------------------
//   Copyright (C) Rodrigo Almeida 2014
// -----------------------------------------------------------------------
//   Arquivo: config.h
//            Header com defini??es dos microcontroladores PIC18F4550 e
//            PIC18F4520 para o compilador SDCC 3.3.0
//   Autor:   Rodrigo Maximiano Antunes de Almeida
//            rodrigomax at unifei.edu.br
//   Licen?a: GNU GPL 2
//   Altera??o 1: Defini??es para 4550 e 4520. (Mariana Rodrigues 2014)
// -----------------------------------------------------------------------
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; version 2 of the License.
// 
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
// -----------------------------------------------------------------------


#ifndef CONFIG_H
#define CONFIG_H

//#define PIC18F4550
#define PIC18F4520

#ifdef PIC18F4550
//configura??es do microcontrolador
#pragma config MCLRE=ON                // Master Clear desabilitado
#pragma config FOSC=HS                 // Oscilador c/ cristal externo HS
#pragma config WDT=OFF                 // Watchdog controlado por software
#pragma config LVP=OFF                 // Sem programa??o em baixa tens?o
#endif

#ifdef PIC18F4520
    #pragma config OSC=HS                  // Oscilador c/ cristal externo HS
    #pragma config WDT=OFF                 // Watchdog controlado por software
    #pragma config LVP=OFF                 // Sem programa??o em baixa tens?o
    #pragma config DEBUG = OFF             // Desabilita debug
    #pragma config WDTPS = 1               // Configura prescaler do watchdog
#endif

#endif