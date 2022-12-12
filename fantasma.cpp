#include "fantasma.h"
#include <iostream>
#include <random>

using namespace std;

Fantasma::Fantasma() 
    : Personagem() {}

Fantasma::Fantasma(int x, int y) 
    : Personagem(x, y){
    sprite='F';
}

int Fantasma::getNovoX(int direcao, int borda, int lin, int col){
    int novoX;
    if(direcao == 0 || direcao == 1)
        novoX = x;
    else if(direcao == 2){
        if(x-1 >= 0)
            novoX = x-1;
        else if(borda)
            novoX = lin-1;
        else
            novoX = x-1;
    }
    else if(direcao == 3){
        if(x+1 != lin)
            novoX = x+1;
        else if(borda)
            novoX = 0;
        else
            novoX = x+1;
    }
    return novoX;
}

int Fantasma::getNovoY(int direcao, int borda, int lin, int col){
    int novoY;
    if(direcao == 2 || direcao == 3)
        novoY = y;
    else if(direcao == 0){
        if(y-1 >= 0)
            novoY = y-1;
        else if(borda)
            novoY = col-1;
        else
            novoY = y-1;
    }
    else if(direcao == 1){
        if(y+1 != col)
            novoY = y+1;
        else if(borda)   
            novoY = 0;
        else
            novoY = y+1;
    }
    return novoY;
}

void Fantasma::anda(int direcao){
    switch(direcao){
        case 0: // esquerda
            setPosicao(x, y-1);
            break;
        case 1: // direita
            setPosicao(x, y+1);
            break;
        case 2: // cima
            setPosicao(x+1, y);
            break;
        case 3: // baixo
            setPosicao(x-1, y);
            break;
        default:
            cout << "Direção inválida!" << endl;
            break;
    }
}

int Fantasma::getX(){
    return x;
}

int Fantasma::getY(){
    return y;
}

int Fantasma::getEmCimaDot(){
    return emCimaDot;
}

void Fantasma::estaEmCimaDeDot(){
    emCimaDot = 1;
}

void Fantasma::NaoEstaEmCimaDeDot(){
    emCimaDot = 0;
}