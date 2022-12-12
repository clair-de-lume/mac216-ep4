#include "arquivo.h"
#include "labirinto.h"
#include "personagem.h"
#include "fantasma.h"
#include "pacman.h"
#include "partida.h"

#include <iostream>
#include <fstream>
#include "gtest/gtest.h"

#define MAX 1000

using namespace std;

TEST(TesteFantasma, CriaFantasmaCerto){
	Fantasma FTest(0, 0);
	
	int x = FTest.getX();
	int y = FTest.getY();
	int flag = FTest.getEmCimaDot();
	
	ASSERT_EQ(x, 0);
	ASSERT_EQ(y, 0);
	ASSERT_EQ(flag, 0);
	
}

TEST(TestePersonagem, movePersonagemCerto){
	Personagem PTest(0, 0);
	
	int x0 = PTest.getX();
	int y0 = PTest.getY();
	
	PTest.setPosicao(1, 1);
	
	int xf = PTest.getX();
	int yf = PTest.getY();
	
	ASSERT_EQ(xf-x0, 1);
	ASSERT_EQ(yf-y0, 1);
	
}

TEST(TestePersonagem, movePersonagemErrado){
	Personagem PTest(0, 0);
	
	int x0 = PTest.getX();
	int y0 = PTest.getY();
	
	PTest.setPosicao(1, 1);
	
	int xf = PTest.getX();
	int yf = PTest.getY();
	
	EXPECT_EQ(xf-x0, -1);
	EXPECT_EQ(yf-y0, -1);
	
}

TEST(TestePacman, CriaPacmanCerto){
	Pacman PacTest(0, 0);
	
	int x = PacTest.getX();
	int y = PacTest.getY();
	int status = PacTest.checaStatus();
	int pontos = PacTest.getPontos();
	char sprite = PacTest.getSprite();
	
	ASSERT_EQ(x, 0);
	ASSERT_EQ(y, 0);
	ASSERT_EQ(status, 1);
	ASSERT_EQ(pontos, 0);
	ASSERT_EQ(sprite, 'C');
	
}

TEST(TestePacman, PacmanCome){
	Pacman PacTest(0, 0);
	PacTest.come();
	
	ASSERT_EQ(PacTest.getPontos(), 1);	
}

int main(int argc, char ** argv){

    if(argc != 2){
        cerr << "Uso: " << argv[0] << " <arquivo do labirinto> ou testes" << endl;
        return 1;
    }
	
	if(argv[1] == "testes"){
		::testing::InitGoogleTest(&argc, argv);
		return RUN_ALL_TESTS();
	}
	
	else{
		string nomeArquivo = argv[1];
		Partida partida(nomeArquivo);

		char jogada;
		while(!partida.perde() && !partida.vence() && !partida.colisao()){
			partida.printaLabirinto();
			partida.andaFantasma();
			if(!partida.colisao()){
				cout << "Direcao (a - esquerda, d - direita, w - cima, s - baixo): ";
				cin >> jogada;
				partida.andaPacman(jogada);
			}
		}

		if(partida.vence()){
			cout << "Congratulations! Pontos = " << partida.totalPontos() << endl;
			partida.printaLabirinto();
		}
		else if(partida.perde()){ 
			cout << "Game Over! Pontos = " << partida.totalPontos() << endl;
			partida.printaLabirinto();
		}
	}
	return 0;
}