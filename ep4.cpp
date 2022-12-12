#include "arquivo.h"
#include "labirinto.h"
#include "personagem.h"
#include "fantasma.h"
#include "pacman.h"
#include "partida.h"

#include <iostream>
#include <fstream>

#define MAX 1000

using namespace std;

int main(int argc, char ** argv){

    if(argc != 2){
        cerr << "Uso: " << argv[0] << " arquivo do labirinto" << endl;
        return 1;
    }

    string nomeArquivo = argv[1];
    Partida partida(nomeArquivo);

    char jogada;
    while(!partida.perde() && !partida.vence() && !partida.colisao()){
        partida.printaLabirinto();
        partida.andaFantasma();
        if(!partida.colisao()){
            cout << "Direcao (a - esquerda, d - direita, w - cima, s - baixo): ";
            cin >> jogada;
            partida.andaPacman(jogada);
        }
    }

    if(partida.vence()){
        partida.printaLabirinto();
        cout << "Congratulations! Pontos = " << partida.totalPontos() << endl;
    }
    else if(partida.perde()){ 
        partida.printaLabirinto();
        cout << "Game Over! Pontos = " << partida.totalPontos() << endl;
    }
    return 0;
}