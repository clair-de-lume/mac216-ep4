CXX=g++
CFLAGS= -Wall
DOC=doxygen
FLAG="testes"

DOXYFILE=Doxyfile
OBJFILES=arquivo.o labirinto.o personagem.o pacman.o fantasma.o partida.o
MAIN=ep4

all: ep4.o ${OBJFILES}
	@g++ -o ${MAIN} ep4.o ${OBJFILES} -lgtest -lpthread

ep4.o: ep4.cpp arquivo.h labirinto.h personagem.h pacman.h fantasma.h partida.h

arquivo.o: arquivo.cpp arquivo.h
	@g++ -c arquivo.cpp
	
labirinto.o: labirinto.cpp labirinto.h
	@g++ -c labirinto.cpp
	
personagem.o: personagem.cpp personagem.h
	@g++ -c personagem.cpp
	
pacman.o: pacman.cpp pacman.h
	@g++ -c pacman.cpp
	
fantasma.o: fantasma.cpp fantasma.h
	@g++ -c fantasma.cpp
	
partida.o: partida.cpp partida.h
	@g++ -c partida.cpp
	
doc:
	${DOC} ${DOXYFILE}

clear:
	@rm -rf *.o html
	
tests: ep4.o ${OBJFILES}
	g++ -o ${MAIN} ep4.o ${OBJFILES} -lgtest -lpthread
	@./${MAIN} ${FLAG}
