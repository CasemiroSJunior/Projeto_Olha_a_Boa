#include <stdio.h>
#include <fstream>
#include <iostream>
#include "Cartela.cpp"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); 
    // Precisa ser chamado para gerar números aleatórios diferentes, caso contrário, os números serão sempre os mesmos.
    // isso acontece pois o rand() gera números aleatórios baseados no tempo atual, e se o tempo não mudar, o número gerado também não mudará.

    bool bingo = false;
    bool coluna = false;
    bool linha = false;

    int qntd = 0;
    cout << "Ola, seja bem vindo ao gerenciador de cartelas." << endl;
    cout << "Para poder comecar, responda. " << endl;
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
                            if (verificaColuna(&vetor_cartela[i], coluna) && !coluna){
                                coluna = true;
                            }
                            if (verificaLinha(&vetor_cartela[i], linha) && !linha){
                                linha = true;
                            }
                            if (verificaBingo(&vetor_cartela[i]) && bingo == false){
                                bingo = true;
                            }
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
                    cout << "---------------------------------------------" << endl;
                }
                break;
            case 3:
                int cartelaBaixar;
                cout << "Qual cartela deseja baixar?" << endl;
                cin >> cartelaBaixar;
                if (cartelaBaixar > qntd || cartelaBaixar < 1){
                    cout << "Cartela inexistente" << endl;
                    break;
                }else{
                    converteCartelaTXT(&vetor_cartela[cartelaBaixar-1], cartelaBaixar);
                }
                cout << "Cartela " << cartelaBaixar << " baixada" << endl;
                break;
            case 4:
                for (int i = 0; i < qntd; i++){
                    converteCartelaTXT(&vetor_cartela[i], i+1);
                }
                cout << "Todas as cartelas foram baixadas" << endl;
                break;
            case 5:
                delete[] vetor_cartela;
                return 0;
                break;
            default:
                cout << "Opção inválida" << endl;
                break;
        }
    }

    return 0;
}