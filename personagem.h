#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#define MORTO 0
#define VIVO 1

/**
 * @class Personagem
 * @brief A classe Personagem lida com personagens do jogo Pacman.
 * 
 */

class Personagem{
    protected:
        /**
         * @brief A posição (x, y) do personagem no labirinto.
         * 
         */
        int x, y;

        /**
         * @brief O sprite do personagem no labirinto.
         * 
         */
        char sprite;
        
    public:
        /**
         * @brief Um construtor padrão para um objeto do tipo Personagem.
         * 
         */
        Personagem();

        /**
         * @brief Um construtor parametrizado para um objeto do tipo Personagem.
         * 
         * @param x (int) A linha do labirinto em que o personagem está.
         * @param y (int) A coluna do labirinto em que o personagem está.
         */
        Personagem(int x, int y);

        /**
         * @brief Função: setPosicao
         * Define a posição do personagem no labirinto.
         * 
         * @param x (int) A linha do labirinto em que o personagem está.
         * @param y (int) A coluna do labirinto em que o personagem está 
         */
        void setPosicao(int x, int y);
		
		
        /**
         * @brief Função: getX
         * Retorna a linha em que o personagem está.
         * 
         * @return (int) A linha em que o personagem está.
         */
        int getX();

        /**
         * @brief Função: getY
         * Retorna a coluna em que o personagem está.
         * 
         * @return (int) A coluna em que o personagem está.
         */
        int getY();
};

#endif