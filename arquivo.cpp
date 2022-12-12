#include "arquivo.h"
#include <iostream>
#include <fstream>

using namespace std;

Arquivo::Arquivo(string nomeArquivo){
    string linha;
    ifstream arquivoTab(nomeArquivo);
    if(arquivoTab.is_open()){
        while(arquivoTab.good()){
            getline(arquivoTab, linha);
            lin++;
            if(col == 0)
                col = linha.size();
        }
    }
    arquivoTab.close();

    tabuleiro = new string[lin];

    int i = 0;
    arquivoTab.open(nomeArquivo, ios::in);
    if(arquivoTab.is_open()){
        while(arquivoTab.good()){
            getline(arquivoTab, tabuleiro[i]);
            i++;
        }
    }
    arquivoTab.close();
}

int Arquivo::getLinhas(){
    return lin;
}

int Arquivo::getColunas(){
    return col;
}

char Arquivo::getChar(int x, int y){
    return tabuleiro[x].at(y);
}