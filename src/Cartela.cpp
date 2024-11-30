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

void gerarCartela(CARTELA *cartela);
bool validaRandNumber(CARTELA *cartela, int coluna, int randNumber);
void adicionarFreeSpace(CARTELA *cartela);
void marcarNumero(CARTELA *cartela, int number);
int gerarRandNumber(int coluna);
void visualizarCartela(CARTELA *cartela);


void gerarCartela(CARTELA *cartela){
    int i, j;
    for (i = 0; i < 5; i++){
        for (j = 0; j < 5; j++){
            int temp = gerarRandNumber(i);
            while (validaRandNumber(cartela, i, temp))
            {
                temp = gerarRandNumber(i);
            }
            
            cartela->matriz[i][j].valor = temp;
            cartela->matriz[i][j].marcado = false;
        }
    }
    adicionarFreeSpace(cartela);
};

bool validaRandNumber(CARTELA *cartela, int coluna, int randNumber){
    bool existe = false;
    for (int i = 0; i < 5; i++){
        if(cartela->matriz[coluna][i].valor == randNumber)
            existe = true;
    }
    return existe;
}

void adicionarFreeSpace(CARTELA *cartela){
    cartela->matriz[2][2].valor = 0;
    cartela->matriz[2][2].valor = true;
}

void marcarNumero(CARTELA *cartela, int number){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if(cartela->matriz[i][j].valor == number)
                cartela->matriz[i][j].marcado = true;
        }
    }
};

int gerarRandNumber(int coluna){
    int max, min;
    switch (coluna){}
    if (coluna == 0){
        max = 15;
        min = 1;
    }else if (coluna == 1){
        max = 30;
        min = 16;
    }else if (coluna == 2){
        max = 45;
        min = 31;
    }else if (coluna == 3){
        max = 60;
        min = 46;
    }else if (coluna == 4){
        max = 75;
        min = 61;
    }

    int random_number = min + rand() % (max - min + 1);
    return random_number;
};

void visualizarCartela(CARTELA *cartela){

    printf(" B   I   N   G   O \n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                printf("XX  ");  
            }
            else {
                if (cartela->matriz[j][i].marcado) {
                    printf("XX  ");
                } else {

                    printf("%02d  ", cartela->matriz[j][i].valor);
                }
            }
        }
        printf("\n");  // Pula para a próxima linha
    }
    printf("\n");
}
