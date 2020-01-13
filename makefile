
cillionaire: cillionaire.o game.o readFile.o classes.h
	gcc cillionaire.o game.o readFile.o -o cillionaire

cillionaire.o: cillionaire.c classes.h
	gcc -c -g -Wall -Wpedantic -Wextra -std=c99 cillionaire.c -o cillionaire.o

game.o: game.c classes.h
	gcc -c -g -Wall -Wpedantic -Wextra -std=c99 game.c -o game.o

readFile.o: readFile.c classes.h
	gcc -c -g -Wall -Wpedantic -Wextra -std=c99 readFile.c -o readFile.o


clean:
	rm -rf *.o cillionaire