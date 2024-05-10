CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -g -Werror=vla
EXEC = watopoly
OBJECTS = academicbuilding.o board.o controller.o display.o gym.o location.o main.o ownable.o player.o residence.o unownable.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
