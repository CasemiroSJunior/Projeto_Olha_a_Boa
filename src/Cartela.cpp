#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

typedef struct valores{
    int valor;
    bool marcado;
} VALORES;

typedef struct cartela{
    VALORES matriz[5][5];
    // Trocar lugar da variavel para chamador validar se saiu ou n 
    bool boaOK = false;
} CARTELA;

void gerarCartela(CARTELA *cartela);
bool validaRandNumber(CARTELA *cartela, int coluna, int randNumber);
void adicionarFreeSpace(CARTELA *cartela);
void marcarNumero(CARTELA *cartela, int number);
int gerarRandNumber(int coluna);
void avisoBater(CARTELA *cartela);
bool verificaColuna(CARTELA *cartela, bool verificaColuna);
bool verificaLinha(CARTELA *cartela, bool verificaLinha);
bool verificaBoa(CARTELA *cartela);
bool verificaBingo(CARTELA *cartela);
void visualizarCartela(CARTELA *cartela);
void converteCartelaTXT(CARTELA *cartela, int index);

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

void converteCartelaTXT(CARTELA *cartela, int index){
    
    string archiveName = "Cartela" + to_string(index)+".txt";
    ofstream outFile(archiveName);
    if (!outFile.is_open()){
        cout << "Erro ao abrir arquivo" << endl;
        return ;
    }
    
    outFile << " B   I   N   G   O \n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                outFile << "XX  ";  
            }else {
                outFile << cartela->matriz[j][i].valor << "  ";
            }
        }
        outFile << "\n";
        
    }
    outFile.close();
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
    cartela->matriz[2][2].marcado = true;
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
    switch (coluna){
        case 0:
            min = 1;
            max = 15;
            break;
        case 1:
            min = 16;
            max = 30;
            break;
        case 2:
            min = 31;
            max = 45;
            break;
        case 3:
            min = 46;
            max = 60;
            break;
        case 4:
            min = 61;
            max = 75;
            break;
    }

    int random_number = min + rand() % (max - min + 1);
    return random_number;
};

void avisoBater(CARTELA *cartela){
    if(verificaBoa(cartela)){
        cartela->boaOK = true;
    }
};

bool verificaColuna(CARTELA *cartela, bool verificaColuna){
    int coluna,linha, okQntd= 0 ;
    //Verificar coluna
    if (verificaColuna == true){
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

bool verificaLinha(CARTELA *cartela, bool verificaLinha){
    int coluna,linha, okQntd= 0;
    //Verificar linha
    if (verificaLinha == true){
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
    int coluna,linha, okQntd= 0;
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

bool verificaBingo(CARTELA *cartela) {
    int okQntd = 0;

    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            if (cartela->matriz[linha][coluna].marcado) {
                okQntd++;
            }
        }
    }
    // Verificar se todos os 25 espaços estão marcados
    if (okQntd == 25) {
        cout << "----------BINGO!----------" << endl;
        return true;
    }

    return false;
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
