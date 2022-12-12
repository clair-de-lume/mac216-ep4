#ifndef PACMAN_H
#define PACMAN_H

#define VIVO 1
#define MORTO 0

#include "personagem.h"

class Pacman: public Personagem {
    protected:
        int status;
        int pontos;
        //char sprite;

    public:
        Pacman();
        Pacman(int x, int y);
        //void anda(char direcao);
        void come();
        void morre();
        void vence();
        int checaStatus();
        int getPontos();
        int getX();
        int getY();
        int getNovoX(char direcao, int borda, int lin, int col);
        int getNovoY(char direcao, int borda, int lin, int col);
};

#endif