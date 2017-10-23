

testme: testme.c
	gcc -o testme -coverage -lm -Wall testme.c

runtest:
	./testme
	gcov -b -f testme.c
	
all: testme runtest