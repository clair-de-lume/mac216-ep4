#include "personagem.h"

Personagem::Personagem() {}

Personagem::Personagem(int x, int y){
    setPosicao(x, y);
}

void Personagem::setPosicao(int x, int y){
    this->x = x;
    this->y = y;
}

int Personagem::getX(){
    return x;
}

int Personagem::getY(){
    return y;
}