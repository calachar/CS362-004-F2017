/* Ralph Calachan
Unit Test 2 */

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
int main (int argc, char** argv) {
	
	int i;
	int j;
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

	printf("==========\n\n");
	printf("Unit Test 2: Shuffle Game Function Test\n");
	printf("==========\n");

	initializeGame(2, k, atoi(argv[1]), &G);
  
	//Initialize the decks
	for (i = 0; i < G.numPlayers; i++)
    {
		G.deckCount[i] = 0;
		for (j = 0; j < 3; j++)
		{
			G.deck[i][j] = estate;
			G.deckCount[i]++;
		}
		for (j = 3; j < 10; j++)
		{
			G.deck[i][j] = copper;
			G.deckCount[i]++;		
		}
    }
	
	//print decks before shuffle
	printf("\n=========Player Decks Before Shuffle========\n\n");
	for( i = 0; i < G.numPlayers; i++)
	{
		printf("\nPlayer %d Deck:\n", i);
		for( j = 0; j < 10; j++)
		{
			if(G.deck[i][j] == copper)
			{
				printf("Copper");
			}
			else if(G.deck[i][j] == estate)
			{
				printf("Estate");
			}
			printf("\n");
		}
	}
	shuffle( 0, &G);
	shuffle( 1, &G);
	
	//print decks after shuffle
	printf("\n=========Player Decks after Shuffling=======\n");
	
	for( i = 0; i < G.numPlayers; i++)
	{
		printf("\nPlayer %d Deck:\n", i);
		for( j = 0; j < 10; j++)
		{
			if(G.deck[i][j] == copper)
			{
				printf("Copper");
			}
			else if(G.deck[i][j] == estate)
			{
				printf("Estate");
			}
			printf("\n");
		}
	}
	
	for( i = 0; i < G.numPlayers; i++)
	{
		int notShuffled = 1;
		for( j = 3; j < 10; j++)
		{
			if(G.deck[i][j] != copper)
			{
				notShuffled = 0;
			}
		}
		if( notShuffled == 0)
		{
			printf("\PLAYER %d DECK IS SHUFFLED: TEST SUCCESSFUL\n", i);
		}
		else
		{
			printf("PLAYER %D DECK MIGHT NOT BE SHUFFED. TEST FAIL\n", i);
		}
	}
	
	
	return 0;
}