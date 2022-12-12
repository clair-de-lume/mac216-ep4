#ifndef PARTIDA_H
#define PARTIDA_H

#include "labirinto.h"
#include "personagem.h"
#include "fantasma.h"
#include "pacman.h"

/**
 * @class Partida
 * @brief A classe Partida lida com as ações que podem ser feitas em uma partida do jogo Pacman.
 * A classe Partida é uma subclasse da superclasse Labirinto.
 * 
 */

class Partida : public Labirinto {
    private:
        /**
         * @brief Um array de objetos do tipo Fantasma.
         * 
         */
        Fantasma * fantasmas;
        /**
         * @brief Um objeto do tipo Pacman.
         * 
         */
        Pacman pacman;

    public:
        /**
         * @brief Um construtor parametrizado para um objeto do tipo Partida.
         * Esse construtor invoca o construtor da superclasse Labirinto.
         * 
         * @param nomeArquivo (string) O nome do arquivo que contém o labirinto.
         */
        Partida(string nomeArquivo);

        /**
         * @brief Função: getFantasmas
         * Percorre o labirinto e copia o conteúdo de cada fantasma presente no labirinto para o array de fantasmas.
         * 
         */
        void getFantasmas();

        /**
         * @brief Função: posicaoAleatoria
         * Retorna um número aleatório entre 0 e 3 que indica a direção para a qual o fantasma se movimentará.
         * 
         * @return (int) Um número entre 0 e 3. 
         */
        int posicaoAleatoria();

        /**
         * @brief Função: colisao
         * Verifica se houve uma colisão entre o Pacman e os fantasmas.
         * 
         * @return (int) 1 se houve colisão e 0 caso contrário.
         */
        int colisao();

        /**
         * @brief Função: andaFantasma
         * Avança 1 casa com cada um dos fantasmas.
         * 
         */
        void andaFantasma();

        /**
         * @brief Função: andaPacman
         * Avança 1 casa com o Pacman.
         * 
         * @param dir 
         */
        void andaPacman(char dir);

        /**
         * @brief Função: vence
         * Verifica se o número de pontos acumulados pelo Pacman é igual ao número de pacdots no labirinto.
         * 
         * @return (int) 1 se o número de pontos acumulados pelo Pacman é igual ao número de pacdots no labirinto ou 0 caso contrário.
         */
        int vence();

        /**
         * @brief Função: perde
         * Verifica se o Pacman está morto.
         * 
         * @return (int) 1 se o Pacman está morto ou 0 caso contrário.
         */
        int perde();

        /**
         * @brief Função: totalPontos
         * Retorna o total de pontos acumulados pelo Pacman.
         * 
         * @return (int) O total de pontos acumulados pelo Pacman.
         */
        int totalPontos();
        
};

#endif