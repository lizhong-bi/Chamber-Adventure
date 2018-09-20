CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = cc3k
MAINOBJ = main.o game.o floor.o chamber.o textdisplay.o
OBJTYPES = wall.o passage.o empty.o blank.o door.o stairs.o
ENEMY = enemy.o human.o elf.o dwarf.o halfling.o orcs.o merchant.o dragon.o
PLAYER = playerCharacter.o shade.o drow.o troll.o goblin.o vampire.o
SUPEROBJ = subject.o object.o character.o
ITEMOBJ = rh.o ba.o bd.o ph.o wa.o wd.o potion.o item.o gold.o
OBJECTS = ${OBJTYPES} ${MAINOBJ} ${ENEMY} ${PLAYER} ${SUPEROBJ} ${ITEMOBJ}
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
