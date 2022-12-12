#include <iostream>
#include <fstream>
#include "arquivo.h"

#ifndef LABIRINTO_H
#define LABIRINTO_H

#define MAX 1000

/**
 * @class Labirinto
 * @brief A classe Labirinto lida com o labirinto para um jogo de Pacman.
 * A classe labirinto é uma subclasse da superclasse Arquivo.
 * 
 */

class Labirinto: public Arquivo {
    protected:
        /**
         * @brief Uma matriz de caracteres contendo um labirinto.
         * 
         */
        char ** labirinto;

        /**
         * @brief O número de pacdots no labirinto.
         * 
         */
        int pacdots = 0;

        /**
         * @brief O número de fantasmas no labirinto.
         * 
         */
        int nFantasmas = 0;

    public:
        /**
         * @brief Um construtor parametrizado para um objeto do tipo Labirinto.
         * Esse construtor invoca o construtor da superclasse Arquivo.
         * 
         * @param nomeArquivo (string) O nome do arquivo .txt que contém o labirinto.
         */
        Labirinto(string nomeArquivo);

        /**
         * @brief Função: printaLabirinto
         * Imprime o labirinto.
         * 
         */
        void printaLabirinto();

        /**
         * @brief Função: copiaLabirinto
         * Copia o conteúdo da string tabuleiro (presente na superclasse Arquivo) para a matriz labirinto.
         * 
         */
        void copiaLabirinto();

        /**
         * @brief Função: getLabirinto
         * Retorna a matriz que contém o labirinto.
         * 
         * @return (char**) Uma matriz de caracteres contendo o labirinto. 
         */
        char ** getLabirinto();

        /**
         * @brief Função: getFantasmas
         * Retorna o número de fantasmas presentes no labirinto.
         * 
         * @return (int) O número de fantasmas presentes no labirinto.
         */
        int getFantasmas();

        /**
         * @brief Função: getDots
         * Retorna o número de pacdots presentes no labirinto.
         * 
         * @return (int) O número de pacdots presentes no labirinto.
         */
        int getDots();

        /**
         * @brief Função: ehParede
         * Verifica se a posição (i, j) contém um caractere "*".
         * 
         * @param i (int) A linha do labirinto.
         * @param j (int) A coluna do labirinto.
         * @return (int) 1 se for parede e 0 caso contrário.
         */
        int ehParede(int i, int j);

        /**
         * @brief Função: ehBorda
         * Verifica se a posição (i, j) é uma borda do labirinto.
         * 
         * @param i (int) A linha do labirinto.
         * @param j (int) A coluna do labirinto.
         * @return (int) 1 se for borda e 0 caso contrário. 
         */
        int ehBorda(int i, int j);

};

#endif