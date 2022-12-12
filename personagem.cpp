#include "personagem.h"

Personagem::Personagem() {}

Personagem::Personagem(int x, int y){
    setPosicao(x, y);
    //status = VIVO;
}

void Personagem::setPosicao(int x, int y){
    this->x = x;
    this->y = y;
}

// int Personagem::getX(){
//     return x;
// }

// int Personagem::getY(){
//     return y;
// }

// int Personagem::posicaoPossivel(char ** labirinto, int i, int j){
//     if(labirinto[i][j] != '*')
//         return 1;
//     return 0; 
// }