#include "pacman.h"
#include <iostream>

using namespace std;

Pacman::Pacman()
    : Personagem() {}

Pacman::Pacman(int x, int y) 
    : Personagem(x, y){
    status = VIVO;
    pontos = 0;
    sprite = 'C';
}

int Pacman::getPontos(){
    return pontos;
}

int Pacman::getNovoX(char direcao, int borda, int lin, int col){
    int novoX;
    if(direcao == 'a' || direcao == 'd')
        return x;
    else if(direcao == 'w'){
        if(x-1 >= 0)
            novoX = x-1;
        else if(borda)
            novoX = lin-1;
        else
            novoX = x-1;
    }
    else if(direcao == 's'){
        if(x+1 != lin)
            novoX = x+1;
        else if(borda)
            novoX = 0;
        else
            novoX = x+1;
    }
    return novoX;
}

int Pacman::getNovoY(char direcao, int borda, int lin, int col){
    int novoY;
    if(direcao == 'w' || direcao == 's')
        novoY = y;
    else if(direcao == 'a'){
        if(y-1 >= 0)
            novoY = y-1;
        else if(borda)
            novoY = col-1;
        else
            novoY = y-1;
    }
    else if(direcao == 'd'){
        if(y+1 != col)
            novoY = y+1;
        else if(borda)   
            novoY = 0;
        else
            novoY = y+1;
    }
    return novoY;
}

void Pacman::come(){
    pontos++;
}

void Pacman::morre(){
    status = 0;
    cout << "Game Over! Pontos = " << pontos << endl;
}

void Pacman::vence(){
    cout << "Congratulations! Pontos = " << pontos << endl;
}

int Pacman::checaStatus(){
    return status;
}

int Pacman::getX(){
    return x;
}

int Pacman::getY(){
    return y;
}