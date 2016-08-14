
CC=clang++
CFLAGS=-Wall -g -lboost_system -lboost_filesystem -std=c++11

PROJECT = game

OBJECTS=Atts.o Combat.o loader.o shop.o healer.o smith.o World.o Ability.o list.o Inventory.o sanctuary.o touchStone.o main.o

all: ${PROJECT}

${PROJECT}: ${OBJECTS}
	$(CC) -o ${PROJECT} ${OBJECTS}

%.o: %.cpp
	${CC} -c ${CFLAGS} $<

clean:
	rm -f core.* *.o *~ ${PROJECT}
