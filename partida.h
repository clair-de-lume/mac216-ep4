#ifndef PARTIDA_H
#define PARTIDA_H

#include "labirinto.h"
#include "personagem.h"
#include "fantasma.h"
#include "pacman.h"

class Partida : public Labirinto {
    private:
        Fantasma * fantasmas;
        Pacman pacman;

    public:
        Partida(string nomeArquivo);
        void getFantasmas();
        void printaFantasmas();
        void printaPacman();
        int posicaoAleatoria();
        int colisao();
        void andaFantasma();
        void andaPacman(char dir);
        int vence();
        int perde();
        int totalPontos();
        
};

#endif