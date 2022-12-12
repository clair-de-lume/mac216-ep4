#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
#include <fstream>

using namespace std;

#define MAX 1000

class Arquivo{
    protected:
        string * tabuleiro;
        int lin = 0;
        int col = 0;

    public:
        Arquivo();
        Arquivo(string nomeArquivo);
        int getLinhas();
        int getColunas();
        char getChar(int x, int y);
};

#endif