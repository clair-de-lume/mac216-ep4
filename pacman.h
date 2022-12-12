#ifndef PACMAN_H
#define PACMAN_H

#define VIVO 1
#define MORTO 0

#include "personagem.h"

/**
 * @class Pacman
 * @brief A classe Pacman lida com as ações que podem ser feitas pelo Pacman no labirinto.
 * A classe Pacman é uma subclasse da superclasse Personagem.
 * 
 */

class Pacman: public Personagem {
    protected:
        /**
         * @brief O status do Pacman.
         * "VIVO" (1) se está vivo e "MORTO" (0) se está morto.
         * 
         */
        int status;
        /**
         * @brief O total de pacdots que o Pacman já comeu.
         * 
         */
        int pontos;

    public:
        /**
         * @brief Um construtor padrão para um objeto do tipo Pacman.
         * Esse construtor invoca o construtor da superclasse Personagem.
         * 
         */
        Pacman();

        /**
         * @brief Um construtor parametrizado para um objeto do tipo Pacman.
         * Esse construtor invoca o construtor da superclasse Personagem.
         * 
         * @param x (int) A linha do labirinto em que o Pacman está.
         * @param y (int) A coluna do labirinto em que o Pacman está.
         */
        Pacman(int x, int y);

        /**
         * @brief Função: come
         * Incrementa o número de pontos do Pacman.
         * 
         */
        void come();

        /**
         * @brief Função: morre
         * Muda o status do Pacman para "MORTO".
         * 
         */
        void morre();

        /**
         * @brief Função: checaStatus
         * Retorna o status do Pacman.
         * 
         * @return (int) O status do Pacman. 
         */
        int checaStatus();

        /**
         * @brief Função: getPontos
         * Retorna o total de pontos acumulados pelo Pacman.
         * 
         * @return (int) O total de pontos acumulados pelo Pacman.
         */
        int getPontos();

        /**
         * @brief Função: getX
         * Retorna a linha em que o Pacman está.
         * 
         * @return (int) A linha em que o Pacman está.
         */
        int getX();

        /**
         * @brief Função: getY
         * Retorna a coluna em que o Pacman está.
         * 
         * @return (int) A coluna em que o Pacman está.
         */
        int getY();

        /**
         * @brief Função: getNovoX
         * Retorna a nova linha do Pacman de acordo com a entrada do jogador.
         * 
         * @param direcao (char) Uma direção escolhida pelo jogador de acordo com as teclas WASD.
         * @param borda (int) 1 se o Pacman está em uma borda do tabuleiro ou 0 caso contrário.
         * @param lin (int) A linha do tabuleiro onde o Pacman está.
         * @param col (int) A coluna do tabuleiroonde o Pacman está
         * @return (int) A nova linha do Pacman.
         */
        int getNovoX(char direcao, int borda, int lin, int col);

        /**
         * @brief Função: getNovoY
         * Retorna a nova coluna do Pacman de acordo com a entrada do jogador.
         * 
         * @param direcao (char) Uma direção escolhida pelo jogador de acordo com as teclas WASD.
         * @param borda (int) 1 se o Pacman está em uma borda do tabuleiro ou 0 caso contrário.
         * @param lin (int) A linha do tabuleiro onde o Pacman está.
         * @param col (int) A coluna do tabuleiroonde o Pacman está
         * @return (int) A nova coluna do Pacman.
         */
        int getNovoY(char direcao, int borda, int lin, int col);
		
		/**
         * @brief Função: getSprite
         * Retorna o caractere que representa o sprite do Pacman.
         * 
         * @return (char) O caractere que representa o sprite do Pacman.
         */
		char getSprite();
};

#endif