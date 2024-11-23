#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct valores{
    int valor;
    bool marcado;
}VALORES;

typedef struct cartela{
    VALORES matriz[5][5];
} CARTELA;


cartela cadastrarCartela(int qntd){

    CARTELA vetor_cartela[qntd];
    
    

    for (int i = 0; i < qntd; i++){
          
    }
    

};

int gerarRandNumber(string letra){
    int max, min;
    if (letra == "B"){
        max = 15;
        min = 1;
    }else if (letra == "I"){
        max = 30;
        min = 16;
    }else if (letra == "N"){
        max = 45;
        min = 31;
    }else if (letra == "G"){
        max = 60;
        min = 46;
    }else if (letra == "O"){
        max = 75;
        min = 61;
    }

    int random_number = min + rand() % (max - min + 1);
    return random_number;
};
void marcarNumero();
void visualizarCartela();