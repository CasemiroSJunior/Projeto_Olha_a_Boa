#include <stdio.h>
#include <iostream>
#include "Cartela.cpp"

using namespace std;

int main() {
    int qntd;
    cout << "Olá, seja bem vindo ao gerenciador de cartelas." << endl;
    cout << "Para poder começar, responda. " << endl;
    cout << "Quantas cartelas deseja gerenciar?" << endl;
    
    cin >> qntd;
    CARTELA vetor_cartela[qntd];

    for (int i = 0; i < qntd; i++){
        gerarCartela(&vetor_cartela[i]);
    }
    for (int i = 0; i < qntd; i++){
        cout << "Cartela " << i+1 << endl;
        visualizarCartela(&vetor_cartela[i]);
    }

    int lastInput;
    while (lastInput != 0) {
        cout << "Digite o número sorteado ou 0 para sair" << endl;
        cin >> lastInput;
        if (lastInput == 0)
            break;
        for (int i = 0; i < qntd; i++){
            marcarNumero(&vetor_cartela[i], lastInput);
            cout << "Cartela " << i+1 << endl;
            visualizarCartela(&vetor_cartela[i]);
        }
    }
    

    
    


    


    return 0;
}