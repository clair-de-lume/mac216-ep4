
#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
#include <fstream>

using namespace std;

#define MAX 1000

/**
* @class Arquivo
* @brief A classe Arquivo lida com arquivos .txt contendo tabuleiros para um jogo de Pacman.
*/
class Arquivo{
    protected:
        /**
         * @brief Uma string que irá guardar o tabuleiro lido do arquivo.
         * 
         */
        string * tabuleiro;
        
        /**
         * @brief O número de linhas do arquivo.
         *
         */
        int lin = 0;

        /**
         * @brief O número de colunas do arquivo.
         * (O arquivo deve ter o mesmo número de colunas em toda linha.)
         */
        int col = 0;

    public:
        /**
         * @brief Um construtor padrão para um objeto do tipo Arquivo.
         * 
         */
        Arquivo();

        /**
         * @brief Um construtor parametrizado para um objeto do tipo Arquivo.
         * 
         * @param nomeArquivo (string) O nome do arquivo .txt a ser lido.
         */
        Arquivo(string nomeArquivo);

        /**
         * @brief Função: getLinhas
         * Retorna o número de linhas do arquivo.
         * 
         * @return (int) o número de linhas do arquivo. 
         */
        int getLinhas();

        /**
         * @brief Função: getColunas
         * Retorna o número de colunas do arquivo.
         * 
         * @return (int) o número de colunas do arquivo. 
         */
        int getColunas();

        /**
         * @brief Função: getChar
         * Retorna o caractere que está na posição (x, y) da string tabuleiro. 
         * 
         * @param x (int) a linha da string tabuleiro.
         * @param y (int) a coluna da string tabuleiro.
         * @return (char) o caractere na posição (x, y) da string tabuleiro. 
         */
        char getChar(int x, int y);
};

#endif