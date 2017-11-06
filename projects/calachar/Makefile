CFLAGS = -Wall -fpic -coverage -lm -fprofile-arcs -ftest-coverage

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

RandomTest1: dominion.o randomtestcard1.c
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	gcov -b -f randomtestcard1 >> randomtestcard1.out
#To run unitTesting1 you need to entere: ./unitTesting1 <any integer number> like ./unitTesting1 10*/

RandomTest2: dominion.o randomtestcard2.c
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	gcov -b -f randomtestcard2 >> randomtestcard2.out

RandomTestAdventurer: dominion.o randomtestadventurer.c
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)
	gcov -b -f randomtestadventurer >> randomtestadventurer.out
#To run unitTesting1 you need to entere: ./unitTesting1 <any integer number> like ./unitTesting1 10*/
	
interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

testFull:
	./randomtestcard1 2 >> randomtestcard1.out
	gcov -b -f randomtestcard1.c >> randomtestcard1.out
	./randomtestadventurer 2 >> randomtestadventurer.out
	gcov -b -f randomtestadventurer.c >> randomtestadventurer.out
	./randomtestcard2 2 >> randomtestcard2.out
	gcov -b -f randomtestcard2.c >> randomtestcard2.out
	
player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all:  dominion.o rngs.o player RandomTest1 RandomTest2 RandomTestAdventurer testFull

