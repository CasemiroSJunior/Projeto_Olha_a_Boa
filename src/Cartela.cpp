#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct valores{
    int valor;
    bool marcado;
} VALORES;

typedef struct cartela{
    VALORES matriz[5][5];
    // Trocar lugar da variavel para chamador validar se saiu ou n 
    bool linhaOK = false;
    bool colunaOK = false;
    bool boaOK = false;
    bool bingoOK = false;
} CARTELA;

void gerarCartela(CARTELA *cartela);
bool validaRandNumber(CARTELA *cartela, int coluna, int randNumber);
void adicionarFreeSpace(CARTELA *cartela);
void marcarNumero(CARTELA *cartela, int number);
int gerarRandNumber(int coluna);
void avisoBater(CARTELA *cartela);
bool verificaColuna(CARTELA *cartela);
bool verificaLinha(CARTELA *cartela);
bool verificaBoa(CARTELA *cartela);
bool verificaBingo(CARTELA *cartela);
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
    avisoBater(cartela);
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

void avisoBater(CARTELA *cartela){
    if(verificaColuna(cartela)){
        cartela->colunaOK = true;
    }
    if(verificaLinha(cartela)){
        cartela->linhaOK = true;
    }
    if(verificaBoa(cartela)){
        cartela->boaOK = true;
    }
    if(verificaBingo(cartela)){
        cartela->bingoOK = true;
    }
    
};

bool verificaColuna(CARTELA *cartela){
    int coluna,linha, okQntd;
    //Verificar coluna
    if(cartela->colunaOK == true){
        return true;
    }
    for ( coluna = 0; coluna < 5; coluna++){
        for( linha = 0; linha < 5; linha++){
            if(cartela->matriz[coluna][linha].marcado == true){
                okQntd++;
            }
            if(okQntd == 5){
                cout << "----------COLUNA!----------"<< endl;
                return true;
            }
        }
        okQntd = 0;
    }
};

bool verificaLinha(CARTELA *cartela){
    int coluna,linha, okQntd;
    //Verificar coluna
    if (cartela->linhaOK == true){
        return true;
    }
    for ( coluna = 0; coluna < 5; coluna++){
        for( linha = 0; linha < 5; linha++){
            if(cartela->matriz[linha][coluna].marcado == true){
                okQntd++;
            }
            if(okQntd == 5){
                cout << "----------LINHA!----------"<< endl;
                return true;
            }

        }
        okQntd = 0;
    }
};

bool verificaBoa(CARTELA *cartela){
    if (cartela->boaOK == true){
        return true;
    }
    int coluna,linha, okQntd;
    for ( coluna = 0; coluna < 5; coluna++){
        for( linha = 0; linha < 5; linha++){
            if(cartela->matriz[coluna][linha].marcado == true){
                okQntd++;
            }
            if(okQntd == 24){
                cout << "----------OLHA A BOA!----------"<< endl;
                return true;
            }
        }
    }
}

bool verificaBingo(CARTELA *cartela){
    if (cartela->bingoOK == true){
        return true;
    }
    int coluna,linha, okQntd;
    for ( coluna = 0; coluna < 5; coluna++){
        for( linha = 0; linha < 5; linha++){
            if(cartela->matriz[coluna][linha].marcado == true){
                okQntd++;
            }
            if(okQntd == 25){
                cout << "----------BINGO!----------"<< endl;
                return true;
            }
        }
    }
}



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
        printf("\n");
    }
    printf("\n");
}
