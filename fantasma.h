#define VIVO 1
#define MORTO 0

#include "personagem.h"
#ifndef FANTASMA_H
#define FANTASMA_H

/**
 * @class Fantasma
 * @brief A classe Fantasma lida com as ações que podem ser feitas pelos fantasmas no labirinto.
 * A classe Fantasma é uma subclasse da superclasse Personagem.
 * 
 */

class Fantasma: public Personagem {
    private:
        /**
         * @brief Uma flag que sinaliza se o fantasma está em cima de um pacdot.
         * 
         */
        int emCimaDot = 0;
        
    public:
        /**
         * @brief Um construtor padrão para um objeto do tipo Fantasma.
         * Esse construtor invoca o construtor da superclasse Personagem.
         * 
         */
        Fantasma();

        /**
         * @brief Um construtor parametrizado para um objeto do tipo Fantasma.
         * Esse construtor invoca o construtor da superclasse Personagem.
         * 
         * @param x (int) A linha do labirinto em que o fantasma está.
         * @param y (int) A coluna do labirinto em que o fantasma está.
         */
        Fantasma(int x, int y);

        /**
         * @brief Função: getX
         * Retorna a linha em que o fantasma está.
         * 
         * @return (int) A linha em que o fantasma está.
         */
        int getX();

        /**
         * @brief Função: getY
         * Retorna a coluna em que o fantasma está.
         * 
         * @return (int) A coluna em que o fantasma está.
         */
        int getY();

        /**
         * @brief Função: getNovoX
         * Retorna a nova linha do fantasma de acordo com a direção escolhida.
         * 
         * @param direcao (int) Uma direção escolhida aleatoriamente pelo jogo.
         * @param borda (int) 1 se o fantasma está em uma borda do tabuleiro ou 0 caso contrário.
         * @param lin (int) A linha do tabuleiro onde o fantasma está.
         * @param col (int) A coluna do tabuleiroonde o fantasma está
         * @return (int) A nova linha do fantasma.
         */
        int getNovoX(int direcao, int borda, int lin, int col);

        /**
         * @brief Função: getNovoY
         * Retorna a nova coluna do fantasma de acordo com a direção escolhida.
         * 
         * @param direcao (char) Uma direção escolhida aleatoriamente pelo jogo.
         * @param borda (int) 1 se o fantasma está em uma borda do tabuleiro ou 0 caso contrário.
         * @param lin (int) A linha do tabuleiro onde o fantasma está.
         * @param col (int) A coluna do tabuleiroonde o fantasma está
         * @return (int) A nova coluna do fantasma.
         */
        int getNovoY(int direcao, int borda, int lin, int col);

        /**
         * @brief Função: getEmCimaDot
         * Verifica se o fantasma está em cima de um pacdot.
         * 
         * @return (int) 1 se o fantasma está em cima de um pacdot e 0 caso contrário. 
         */
        int getEmCimaDot();

        /**
         * @brief Função: estaEmCimaDeDot
         * Muda a flag emCimaDot para 1.
         * 
         */
        void estaEmCimaDeDot();

        /**
         * @brief Função: NaoEstaEmCimaDeDot
         * Muda a flag emCimaDot para 0.
         * 
         */
        void NaoEstaEmCimaDeDot();
};

#endif