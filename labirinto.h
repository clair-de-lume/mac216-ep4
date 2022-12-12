#include <iostream>
#include <fstream>
#include "arquivo.h"

#ifndef LABIRINTO_H
#define LABIRINTO_H

#define MAX 1000

class Labirinto: public Arquivo {
    protected:
        char ** labirinto;
        int pacdots = 0;
        int nFantasmas = 0;

    public:
        Labirinto(string nomeArquivo);
        void printaLabirinto();
        void copiaLabirinto();
        char ** getLabirinto();
        int getFantasmas();
        int getDots();
        int ehParede(int i, int j);
        int ehBorda(int i, int j);

};

#endif