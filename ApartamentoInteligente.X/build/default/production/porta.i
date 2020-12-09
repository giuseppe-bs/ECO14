# 1 "porta.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.10\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "porta.c" 2
# 1 "./porta.h" 1




char estadoPorta = 0;


char estadoTranca = 0;


int senha = -1;

int pow(int ,int);

int defineSenha(int);

char abreFecha(char);

void tranca();

char destranca(int);

void sair();
# 1 "porta.c" 2
# 12 "porta.c"
int pow(int bas, int exp){
    int resp = 1;
    for (exp; exp>0; exp--)
        resp = resp * bas;
    return resp;
}
# 30 "porta.c"
int defineSenha(int entrada){
    senha = entrada;
    return senha;
}
# 47 "porta.c"
char abreFecha(char comando){

    if(!comando){
        estadoPorta = 0;
        return 1;
    }

    else{


        if(estadoTranca){
            estadoPorta=1;
            return 1;
        }



        return 0;
    }
}
# 78 "porta.c"
void tranca(){
    estadoTranca = 0;
}
# 95 "porta.c"
char destranca(int entrada){



    if(!estadoTranca){



        if(entrada == senha){
            estadoTranca = 1;
            return 1;
        }else



        return 0;
    }


    return 1;
}
