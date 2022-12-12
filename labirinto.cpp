#include "arquivo.h"
#include "labirinto.h"

using namespace std;

Labirinto::Labirinto(string nomeArquivo) 
    : Arquivo(nomeArquivo){
    labirinto = (char **) malloc(lin * sizeof(char *));
    for(int i=0; i<lin; i++)
        labirinto[i] = (char *) malloc (col * sizeof(char));
    copiaLabirinto();
}

void Labirinto::copiaLabirinto(){
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            labirinto[i][j] = getChar(i, j);
            if(labirinto[i][j] == '.')
                pacdots++;
            if(labirinto[i][j] == 'F')
                nFantasmas++;
        }
    }
}

void Labirinto::printaLabirinto(){
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            cout << labirinto[i][j];
        }
        cout << endl;
    }
}

char ** Labirinto::getLabirinto(){
    return labirinto;
}

int Labirinto::getFantasmas(){
    return nFantasmas;
}

int Labirinto::getDots(){
    return pacdots;
}

int Labirinto::ehParede(int i, int j){
    if(labirinto[i][j] == '*')
        return 1;
    return 0; 
}

int Labirinto::ehBorda(int i, int j){
    if(i == 0 || i == lin-1 || j == 0 || j == col-1)
        return 1;
    return 0;
}