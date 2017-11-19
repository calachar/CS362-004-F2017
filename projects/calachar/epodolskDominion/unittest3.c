/* Ralph Calachan
Unit Test 3 */

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
int main (int argc, char** argv) {
	
	//int i;
	//int j;
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

	printf("==========\n\n");
	printf("Unit Test 3: Draw Game Function Test\n");
	printf("==========\n\n");

	initializeGame(2, k, atoi(argv[1]), &G);
  
	//Print the number of cards in hand and deck
	
	printf("Player 0 has %d cards in hand.\n", G.handCount[0]);
	printf("Player 0 has %d cards in deck.\n", G.deckCount[0]);
	//printf("Player 0 has %d cards in discard.\n", G.discardCount[0]);
	
	printf("\nDrawing 1 card for player 0\n");
	drawCard(0, &G);
	drawCard(0, &G);
	drawCard(0, &G);
	printf("Player 0 has %d cards in hand.\n", G.handCount[0]);
	printf("Player 0 has %d cards in deck.\n", G.deckCount[0]);
	

	
	
	if(G.handCount[0] == 8)
	{
		printf("DRAW FOR PLAYER 0 SUCCEEDED.\n");
	}
	else
	{
		printf("DRAW FOR PLAYER 0 FAILED.\n");
	}

	if(G.deckCount[0] == 2)
	{
		printf("DECK COUNT FOR PLAYER 0 CORRECT.\n");
	}
	else
	{
		printf("DECK COUNT FOR PLAYER 0 FAILED.\n");
	}
	
	return 0;
}