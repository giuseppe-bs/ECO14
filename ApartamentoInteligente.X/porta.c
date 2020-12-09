#include "porta.h"

/*Funcao: Pow
 * 
 * parametros: bas, exp
 * retorno: resp
 * 
 * descricao:
 * eleva a base(bas) ao expoente(exp) retornando a potencia resultante
 */

int pow(int bas, int exp){
    int resp = 1;//Definição de variável
    for (exp; exp>0; exp--)//for para realizar a operação exponencial    
        resp = resp * bas;
    return resp;//retorno do resultado
}


/*Funcao: defineSenha
 * 
 * parametros: int entrada
 * retorno: int
 * 
 * descricao:
 * transforma um vetor com os caracteres recebidos para a nova senha em um int
 * amarzenando-o na variavel senha.
 */

int defineSenha(int entrada){
    senha = entrada;//Definição de variáveis
    return senha;//Retorno a senha
}


/*Funcao: abreFecha
 * 
 * parametros: char comando
 * retorno: char
 * 
 * descricao:
 * verifica se é possivel abrir (comando == 1) ou fechar (comando == 0) a porta
 * case possével o faz e retorna verdadeiro (1) senão não executa nada e retorna
 * falso (0) 
 */

char abreFecha(char comando){
    //fechar a porta
    if(!comando){
        estadoPorta = 0;//Porta fechada
        return 1;
    }
    //abrir porta
    else{
        
        //caso destrancado
        if(estadoTranca){            
            estadoPorta=1;  // abre a porta
            return 1;       // executado com sucesso
        }
        
        //caso trancado
        //nao foi possivel executar a acao 
        return 0;  
    }     
}

/*Função: tranca
 *
 * parâmetros:
 * 
 * return : void
 * 
 * desrição:
 * Altera o estado da tranca para trancada
*/

void tranca(){
    estadoTranca = 0;//Estado da tranca vira Trancado
}


/*Função: destranca
 *
 * parâmetros: int entrada
 * 
 * return : char
 * 
 * desrição:
 * Verifica se a porta está destrancada se sim retorna (1),
 *  caso contrário verifica a senha, se el estiver correta
 *  destranca a porta e retorna (1), caso contrário retorna (0).
*/

char destranca(int entrada){

    //caso trancado
    //verifica a senha
    if(!estadoTranca){

        //verifica a senha
        //se estiver correta destranca 
        if(entrada == senha){
            estadoTranca = 1;
            return 1;
        }else            

        //senha inválida
        //não realiza a ação de destrancar
        return 0;            
    }

    //caso destrancado
    return 1;
}