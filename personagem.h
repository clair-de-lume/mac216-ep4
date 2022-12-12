#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#define MORTO 0
#define VIVO 1

class Personagem{
    protected:
        int x, y;
        //int status;
        char sprite;
        
    public:
        Personagem();
        Personagem(int x, int y);
        void setPosicao(int x, int y);
        // int getX();
        // int getY();
};

#endif