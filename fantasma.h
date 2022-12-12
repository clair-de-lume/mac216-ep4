#define VIVO 1
#define MORTO 0

#include "personagem.h"
#ifndef FANTASMA_H
#define FANTASMA_H

class Fantasma: public Personagem {
    private:
        int emCimaDot = 0;
        
    public:
        Fantasma();
        Fantasma(int x, int y);
        void anda(int direcao);
        int getX();
        int getY();
        int getNovoX(int direcao, int borda, int lin, int col);
        int getNovoY(int direcao, int borda, int lin, int col);
        int getEmCimaDot();
        void estaEmCimaDeDot();
        void NaoEstaEmCimaDeDot();
};

#endif