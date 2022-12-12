#include "partida.h"
#include "labirinto.h"
#include "personagem.h"
#include "fantasma.h"
#include "pacman.h"

Partida::Partida(string nomeArquivo) 
    : Labirinto(nomeArquivo) {
        pacman = Pacman((lin/2), (col/2));
        labirinto[lin/2][col/2] = 'C';
        if(nFantasmas > 0){
            fantasmas = new Fantasma[nFantasmas];
            getFantasmas();
        }         
}

void Partida::getFantasmas(){
    int k = 0;
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            if(labirinto[i][j] == 'F'){
                fantasmas[k].setPosicao(i, j);
                k++;
            }
        }
    }
}

int Partida::colisao(){
    for(int i=0; i < nFantasmas; i++){
        if(fantasmas[i].getX() == pacman.getX() && fantasmas[i].getY() == pacman.getY()){
            labirinto[pacman.getX()][pacman.getY()] = 'X';
            pacman.morre();
            return 1;
        }
    }
    return 0;
}

int Partida::posicaoAleatoria(){
    return ((rand() % (3 - 0 + 1)) + 0);
}

void Partida::andaFantasma(){
    int dir, x, y, novoX, novoY, ok;
    if(nFantasmas > 0){
        for(int i=0; i < nFantasmas; i++){
            ok = 0;
            x = fantasmas[i].getX();
            y = fantasmas[i].getY();
            while(!ok){        
                dir = posicaoAleatoria();
                novoX = fantasmas[i].getNovoX(dir, ehBorda(x, y), lin, col);
                novoY = fantasmas[i].getNovoY(dir, ehBorda(x, y), lin, col);

                if(!ehParede(novoX, novoY)){
                    if(fantasmas[i].getEmCimaDot())         // se fantasma esta em cima de um dot
                        labirinto[x][y] = '.';              // restauramos o dot no tabuleiro
                    else
                        labirinto[x][y] = ' ';

                    fantasmas[i].setPosicao(novoX, novoY);  // anda com o fantasma

                    if(labirinto[novoX][novoY] == '.')      // se ha um dot na posicao nova, atualizamos a flag
                        fantasmas[i].estaEmCimaDeDot();
                    else
                        fantasmas[i].NaoEstaEmCimaDeDot();
                        
                    labirinto[novoX][novoY] = 'F';
                    ok = 1;
                }
            }
        }
    }
}

void Partida::andaPacman(char dir){
    int x, y, novoX, novoY;
    x = pacman.getX();
    y = pacman.getY();
    novoX = pacman.getNovoX(dir, ehBorda(x, y), lin, col);
    novoY = pacman.getNovoY(dir, ehBorda(x, y), lin, col);

    if(!ehParede(novoX, novoY)){
        labirinto[x][y] = ' ';

        if(labirinto[novoX][novoY] == '.'){ // se nova posicao conter um pacdot
            pacman.come();                  // aumenta numero de pontos do pacman
            labirinto[novoX][novoY] = ' ';  // e retira o dot do labirinto
        }
        pacman.setPosicao(novoX, novoY);    // anda com o pacman
        labirinto[novoX][novoY] = 'C';
    }
}

int Partida::vence(){
    if(pacman.getPontos() == getDots())
        return 1;
    return 0;
}

int Partida::perde(){
    return (pacman.checaStatus() == 0);
}

int Partida::totalPontos(){
    return pacman.getPontos();
}