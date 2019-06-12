CXX = g++
CXXFLAGS = -std=c++11
OBJS = die.o loadedDie.o game.o player.o war.o
SRCS = die.cpp loadedDie.cpp game.cpp player.cpp war.cpp 
HEADERS = die.hpp loadedDie.hpp game.hpp player.hpp

war:${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o war

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm *.o war

make zip:
	zip -D War.zip *.cpp *.hpp *.pdf makefile