#include "menus.h"
#include "lcd.h"
#include "teclado.h"
#include "pic18f4520.h"
#include "arCondicionado.h"
#include "ssd.h"
#include "porta.h"
#include "luzes.h"
#include "delay.h"


/* funcao menuTranca
 * 
 * parametros: char opcao
 * retorno: void
 * 
 * descricao:
 * realiza a configuração do lcd para a impressão
 * do menu da Tranca
 */
void menuTranca(char opcao){

    //limpa a tela do LCD
    lcd_cmd(L_CLR);

    //definição de variáveis
    unsigned char tmp = 0;
    char digitado = 0;
    int entrada = -1;
    char tentativas = 3;

    //imprime no lcd para inserir a senha
    if(senha != -1){
        lcd_cmd(L_L1+5);
        lcd_str("Insira");
        lcd_cmd(L_L2+5);
        lcd_str("a senha");

    }else{

        //imprime no lcd para criar a senha
        if(opcao == 4){
            lcd_cmd(L_L1+5);
            lcd_str("Insira");
            lcd_cmd(L_L2+2);
            lcd_str("a nova senha");
        }
        else{            

            //imprime no lcd que a porta foi aberta
            if (opcao == 1){
                lcd_cmd(L_L1+1);
                lcd_str("Porta Aberta");
                destranca(entrada);
                abreFecha(1);
                
            } else{

                //imprime no lcd que a porta foi destrancada
                lcd_cmd(L_L1);
                lcd_str("Porta destrancada");
                destranca(entrada);
            }
            lcd_cmd(L_L2+2);
            lcd_str("com sucesso");
            delay_ms(1500);
            return;
        }            
    }
    
    entrada = 0;
    for(;;){
        printSenha(entrada,digitado);

        //realiza a leitura do teclado
        TRISD = 0x0F;
        tmp = tc_tecla(15);
        TRISD = 0x00;
        
        //caso algo seja digitado
        if(tmp != 255){
            digitado++;
            entrada += tmp * pow(10,4-digitado);

            //se tiver os 4 digitos da senha
            if(digitado == 4){

                //se nao for redefinir a senha
                if(opcao != 4){

                    //chama a função de destrancar com o valor da senha digitado
                    //faz a impressão no lcd sobre a abertura e destrancamento da porta
                    if(destranca(entrada)){
                        lcd_cmd(L_CLR);
                         if (opcao == 1){
                            lcd_cmd(L_L1+1);
                            lcd_str("Porta Aberta");
                            abreFecha(1);                        
                        } else{
                            lcd_cmd(L_L1);
                            lcd_str("Porta destrancada");                        
                        }
                        return;
                    }

                    //se a senha estiver incorreta
                    else{
                        
                        //imprime a msg de senha incorreta
                        digitado = 0; 
                        entrada = 0;
                        lcd_cmd(L_L1+5);
                        lcd_str("Senha");
                        lcd_cmd(L_L2+5);
                        lcd_str("Incorreta");

                        //diminui o numero de tentativas para abrir a porta
                        tentativas--;
                        delay_ms(1500);
                        lcd_cmd(L_CLR);//limpa a tela do LCD

                        //verifica se ainda tem tentativas restantes
                        if(!tentativas)
                            return;

                        //se ainda tiver tentativas pede para inserir a senha novamente
                        else{                        
                            lcd_cmd(L_L1+5);
                            lcd_str("Insira");
                            lcd_cmd(L_L2+5);
                            lcd_str("a senha");
                        }
                    }
                }else{
                    defineSenha(entrada);
                    //printSenha(entrada,digitado);
                    lcd_cmd(L_CLR);//limpa a tela do LCD
                    lcd_cmd(L_L1+2);
                    lcd_str("nova senha");
                    lcd_cmd(L_L2+5);
                    lcd_str("definida");
                    //printSenha(entrada,digitado);
                    delay_ms(2000);
                    return;
                }
            }
        }            
    }
}


/* funcao menuPorta
 * 
 * parametros: char tmp
 * retorno: void
 * 
 * descricao:
 * realiza a configuração do lcd para a impressão
 * do menu da Porta
 */
void menuPorta(){
    
    //definição de variáveis
    unsigned char tmp = 0;
    
    for(;;){

        //imprime a opção de fechar a porta
        lcd_cmd(L_CLR);
        lcd_cmd(L_L1);

        if(estadoPorta)
            lcd_str("1-Fechar");

        //imprime a opção de abrir a porta
        else
            lcd_str("1-Abrir");
        lcd_cmd(L_L1+10);

        //imprime a opção para sair do menu
        lcd_str("3-sair");
        lcd_cmd(L_L2);        

        //imprime a opção para trancar a porta
        if(estadoTranca)
            lcd_str("2-Lock");
        
        //imprime a opção para destrancar a porta
        else
            lcd_str("2-UnLock");

        //imprime a opção para redefinir a senha a porta
        lcd_cmd(L_L2+10);
        lcd_str("4-pswd");
        
        //realiza a leitura do teclado
        TRISD = 0x0F;
        tmp = tc_tecla(0);
        TRISD = 0x00;
        
        switch(tmp){

            //imprime que a porta foi aberta com sucesso
            case 1:
                if(estadoPorta) {
                    abreFecha(0);
                    lcd_cmd(L_CLR);//limpa a tela do LCD
                    lcd_cmd(L_L1+1);
                    lcd_str("Porta Fechada");
                    lcd_cmd(L_L2);                    
                    lcd_str("com sucesso");                    
                    delay_ms(1500);
                    
                }

                //chama o menu com a opção 1
                else
                    menuTranca(1);
                break;
            case 2:

                //imprime que a porta foi trancada com sucesso
                if(estadoTranca) {
                    tranca();
                    lcd_cmd(L_CLR);//limpa a tela do LCD
                    lcd_cmd(L_L1+1);
                    lcd_str("Porta Trancada");
                    lcd_cmd(L_L2+1);                    
                    lcd_str("com sucesso");
                    delay_ms(1500);
                    abreFecha(0);
                }

                //chama o menu com a opção 2
                else 
                    menuTranca(2);
                break;
            case 3:
                lcd_cmd(L_CLR);//limpa a tela do LCD
                return;
                break;

            //chama o menu com a opção 4
            case 4:
                menuTranca(4);
                break;
        }
    }
}

/* funcao menuLuzes
 * 
 * parametros: char opcao
 * retorno: void
 * 
 * descricao:
 * realiza a configuração do lcd para a impressão
 * do menu de ligar e desligar as luzes
 */
void menuManipLuzes(char opcao){
    
    //definição de variáveis
    char i;
    unsigned char tmp;
    lcd_cmd(L_CLR);//limpa a tela do LCD
    
    for(;;){
    
    //imprime as opções de ligar/desligar as luzes e as luzes disponiveis para manipulação    
    lcd_cmd(L_L1);
    if(opcao)lcd_str("ligar");
    else lcd_str("Desligar");
    lcd_cmd(L_L1+11);
    lcd_str("34567");
    lcd_cmd(L_L2);
    lcd_str("1-sair");
    lcd_cmd(L_L2+11);

    for(i = 3; i<8; i++)
        lcd_dat((BitTst(estadoLuz,i)?'I':'O'));
    
    //realiza a leitura do teclado
    TRISD = 0x0F;
    tmp = tc_tecla(0);
    TRISD = 0x00;
    switch(tmp){
        case 1:
            lcd_cmd(L_CLR);//limpa o lcd
            return;
        default:
            //imprime que a luz esta sendo ligada
            if(opcao){
                TRISB=0x00;
                PORTB=estadoLuz;
                lcd_cmd(L_CLR);
                lcd_cmd(L_L1+5);
                lcd_str("ligando");
                lcd_cmd(L_L2+4);
                lcd_str("a luz ");
                lcd_dat(tmp);
                delay_ms(1000);
                ligaLuz(tmp);
                delay_ms(1000);
                lcd_cmd(L_CLR);
                TRISB=0x78;
            }
            else{

                //imprime que a luz esta desligada
                TRISB=0x00;
                PORTB=estadoLuz;
                lcd_cmd(L_CLR);//limpa a tela do LCD
                lcd_cmd(L_L1+4);
                lcd_str("desligando");
                lcd_cmd(L_L2+4);
                lcd_str("a luz ");
                lcd_dat(tmp);
                delay_ms(1000);
                desligaLuz(tmp);
                delay_ms(1000);
                lcd_cmd(L_CLR);//limpa a tela do LCD
                TRISB=0x78;
            }
        }
    }
        
}


/* funcao menuLuzes
 * 
 * parametros:
 * retorno: void
 * 
 * descricao:
 * realiza a configuração do lcd para a impressão
 * do menu de geral das luzes
 */
void menuLuzes(){

    //definição de variáveis
    unsigned char tmp;
    
    for(;;){

        //imprime no lcd a opção de ligar as luzes
        lcd_cmd(L_L1);
        lcd_str("1-ligar");

        //imprime no lcd a opção de sair do menu
        lcd_cmd(L_L1+10);
        lcd_str("3-sair");

        //imprime no lcd a opção de desligar as luzes
        lcd_cmd(L_L2);
        lcd_str("2-desligar");
        
        //realiza a leitura do teclado
        TRISD = 0x0F;
        tmp = tc_tecla(0);
        TRISD = 0x00;
        
        switch(tmp){

            //chama o menu de manipulação com  opção 1
            case 1:
                menuManipLuzes(1);
                break;

            //chama o menu de manipulação com  opção 0
            case 2:
                menuManipLuzes(0);
                break;

            //limpa a tela do lcd e sai do menu
            case 3:
                lcd_cmd(L_CLR);//limpa a tela do LCD
                return;
                break;            
        }
    }
}


/* funcao menuAumentaDiminuiAC
 * 
 * parametros:
 * retorno: void
 * 
 * descricao:
 * realiza a configuração do lcd para a impressão do
 * menu de controle de temperatura do ar condicionado
 */
void menuAumentaDiminuiAC(){
    
    //definição de variáveis
    unsigned char tmp;
    
    lcd_cmd(L_CLR);//limpa a tela do LCD
    lcd_cmd(L_L1);
    lcd_str("1-Aumentar");//aumenta a temperatura em 1°C
    lcd_cmd(L_L2);
    lcd_str("2-Diminuir");//diminui a temperatura em 1°C
    lcd_cmd(L_L2+11);
    lcd_str("3-EXT");//volta ao menu principal
    
    for(;;){
        
        //imprime o valor da temperatura no ssd
        printTemp(temperatura);

        //realiza a leitura do teclado
        TRISD = 0x0F;
        tmp = tc_tecla(15);
        TRISD = 0x00;
        
        
        switch(tmp){
           
           //chama  a função de aumento de temperatura com valor 1
            case 1:
                aumentarTemp(1);
                break;

            //chama  a função de diminuição de temperatura com valor 1
            case 2:
                diminuirTemp(1);
                break;

            //limpa o lcd e volta ao menu anterior
            case 3:
                lcd_cmd(L_CLR);//limpa a tela do LCD
                return;
                break;
        }
    }
    
}


/* funcao menuArCondicionado
 * 
 * parametros:
 * retorno: void
 * 
 * descricao:
 * realiza a configuração do lcd para a impressão
 * do menu de geral do ar condicionado
 */
void menuArCondicionado(){

    //definição de variáveis
    unsigned char tmp;
    
    for(;;){

        //se o AC estiver desligado
        if(estado == 0){

            //imprime as opções de ligar o AC e de voltar ao menu anterior
            lcd_cmd(L_L1);
            lcd_str("1-ligar AC");
            lcd_cmd(L_L2);
            lcd_str("2-voltar");
            
            //leitura do teclado
            TRISD = 0x0F;
            tmp = tc_tecla(0);
            TRISD = 0x00;
            
            switch(tmp){

                //chama a função para ligar o AC
                case 1:
                    ligarDesligar(1);
                    lcd_cmd(L_CLR);//limpa a tela do LCD
                    break;

                //retorna ao menu anterior
                case 2:
                    lcd_cmd(L_CLR);//limpa a tela do LCD
                    return;
                    break;
            }            

        //se o AC estiver ligado
        }else{

            //imprime as opções de controle de temperatura, desligar e sair
            lcd_cmd(L_L1);
            lcd_str("1-Mudar Temp");//aumenta a temperatura em 1?C
            lcd_cmd(L_L2);
            lcd_str("2-Desligar");//diminui a temperatura em 1?C
            lcd_cmd(L_L2+10);
            lcd_str("3-sair");//volta ao menu principal
            
            //leitura do teclado
            TRISD = 0x0F;
            tmp = tc_tecla(0);
            TRISD = 0x00;


            switch(tmp){

                //chama o menu de controle de temperatura
                case 1:
                    menuAumentaDiminuiAC();
                    tmp = 0;
                    break;

                //chama a função para desligar o AC
                case 2:
                    ligarDesligar(0);
                    lcd_cmd(L_CLR);//limpa a tela do LCD
                    break;

                //volta ao menu anterior
                case 3:
                    lcd_cmd(L_CLR);//limpa a tela do LCD
                    return;
                    break;
            }  
        }    
    }
}


/* funcao sair
 * 
 * parametros:
 * retorno: void
 * 
 * descricao:
 * realiza o desligamento de todas as funções do
 * apartamento e tranca a porta
 */
void sair(){

    TRISB = 0x00;
    PORTB=estadoLuz;

    //desligar ar condicionado
    lcd_cmd(L_CLR);//limpa a tela do LCD
    lcd_cmd(L_L1+4);
    lcd_str("Desligando");
    lcd_cmd(L_L2+2);
    lcd_str("Ar Condicionado");
    
    ligarDesligar(0);
    
    delay_ms(2000);
    

    // deligar luzes
    lcd_cmd(L_CLR);//limpa a tela do LCD
    lcd_cmd(L_L1+4);
    lcd_str("Desligando");
    lcd_cmd(L_L2+5);
    lcd_str("As luzes");
    
    desligaTodasLuzes();
    delay_ms(2000);


    //trancar porta    
    lcd_cmd(L_CLR);
    lcd_cmd(L_L1+4);
    lcd_str("Trancando");
    lcd_cmd(L_L2+2);
    lcd_str("a porta");
    
    tranca();
    abreFecha(0);
    
    delay_ms(2000);
    
    TRISB = 0x78;
    
    //imprime no lcd a opção de entrar no apartamento
    lcd_cmd(L_CLR);//limpa a tela do LCD
    lcd_cmd(L_L1+4);
    lcd_str("1-entrar");
    
    unsigned char tmp = 0;
    for(;;){
        //realiza a leitura do teclado
        TRISD = 0x0F;
        tmp = tc_tecla(0);
        TRISD = 0x00;
        
        //pede a senha se existir, para entrar no apartamento        
        if(tmp == 1){
            if(senha != -1){
                menuTranca(1);
            }
            abreFecha(1);
            return;
        }            
    }
}