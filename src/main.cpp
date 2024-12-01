#include <stdio.h>
#include <iostream>
#include "Cartela.cpp"

using namespace std;

int main() {
    int qntd = 0;
    cout << "Olá, seja bem vindo ao gerenciador de cartelas." << endl;
    cout << "Para poder começar, responda. " << endl;
    cout << "Quantas cartelas deseja gerenciar?" << endl;
    
    cin >> qntd;
    CARTELA vetor_cartela[qntd];

     for (int i = 0; i < qntd; i++){
        gerarCartela(&vetor_cartela[i]);
    }

    //Menu de seleção:
    int menuOption;
    while (menuOption != 1)
    {
        cout << "Escollha uma opcao: " << endl;
        cout << "1 - Iniciar bingo" << endl;
        cout << "2 - Visualizar cartelas" << endl;
        cout << "3 - Baixar uma cartela" << endl;
        cout << "4 - Baixar todas as cartelas" << endl;
        cout << "5 - Sair" << endl;

        cin >> menuOption;
        switch (menuOption){
            case 1:
                cout << "Bingo iniciado" << endl;
                {
                    for (int i = 0; i < qntd; i++){
                        cout << "Cartela " << i+1 << endl;
                        visualizarCartela(&vetor_cartela[i]);
                    }

                    int lastInput;
                    while (lastInput != 0) {
                        cout << "Digite o numero sorteado ou 0 para sair" << endl;
                        cin >> lastInput;
                        if (lastInput == 0)
                            break;
                        for (int i = 0; i < qntd; i++){
                            marcarNumero(&vetor_cartela[i], lastInput);
                            cout << "Cartela " << i+1 << endl;
                            visualizarCartela(&vetor_cartela[i]);
                        }
                    }
                }
                break;
            case 2:
                cout << "---------------------------------------------" << endl;
                for (int i = 0; i < qntd; i++){
                    cout << "Cartela " << i+1 << endl;
                    visualizarCartela(&vetor_cartela[i]);
                }
                cout << "---------------------------------------------" << endl;
                break;
            case 3:
                int cartelaBaixar;
                cout << "Qual cartela deseja baixar?" << endl;
                cin >> cartelaBaixar;
                cout << "Cartela " << cartelaBaixar << " baixada" << endl;
                break;
            case 4:
                cout << "Todas as cartelas foram baixadas" << endl;
                break;
            case 5:
                return 0;
                break;
            default:
                cout << "Opção inválida" << endl;
                break;
        }
    }

    return 0;
}