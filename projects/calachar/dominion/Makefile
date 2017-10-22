CFLAGS = -Wall -fpic -coverage -lm -fprofile-arcs -ftest-coverage

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

unitTest: dominion.o unittest1.c
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)

unitTest2: dominion.o unittest2.c
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	
unitTest3: dominion.o unittest3.c
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	
unitTest4: dominion.o unittest4.c
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	
cardTest1: dominion.o cardtest1.c
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	
cardTest2: dominion.o cardtest2.c
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)	
	
cardTest3: dominion.o cardtest3.c
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)	
	
cardTest4: dominion.o cardtest4.c
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)		

testFull:
	./unittest1 2 >> unittestresults.out
	gcov -b -f unittest1.c >> unittestresults.out
	./unittest2 2 >> unittestresults.out
	gcov -b -f unittest2.c >> unittestresults.out
	./unittest3 2 >> unittestresults.out
	gcov -b -f unittest3.c >> unittestresults.out
	./unittest4 2 >> unittestresults.out
	gcov -b -f unittest4.c >> unittestresults.out
	./cardtest1 2 >> unittestresults.out
	gcov -b -f cardtest1.c >> unittestresults.out
	./cardtest2 2 >> unittestresults.out
	gcov -b -f cardtest2.c >> unittestresults.out
	./cardtest3 2 >> unittestresults.out
	gcov -b -f cardtest3.c >> unittestresults.out
	./cardtest4 2 >> unittestresults.out
	gcov -b -f cardtest4.c >> unittestresults.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all:  player unitTest unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4 testFull

