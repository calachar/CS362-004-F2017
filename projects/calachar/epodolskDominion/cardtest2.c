/* Ralph Calachan
Card Test 2: Adventurer */

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
	printf("Card Test 2: Adventurer Function Test\n");
	printf("==========\n\n");

	initializeGame(2, k, atoi(argv[1]), &G);
	
	
	printf("Adding adding adventurer card to player 0's hand.\n");
	G.hand[0][G.handCount[0]] = adventurer;
	G.handCount[0]++;

	printf("Player 0 has %d cards in hand.\n", G.handCount[0]);
	for( i = 0; i < 1; i++)
	{
		printf("\nPlayer %d Hand:\n", i);
		for( j = 0; j < G.handCount[0]; j++)
		{
			if(G.hand[i][j] == copper)
			{
				printf("Copper");
			}
			else if(G.hand[i][j] == estate)
			{
				printf("Estate");
			}
			else if(G.hand[i][j] == adventurer)
			{
				printf("Adventurer");
			}
		}
	}
	printf("\n");
	printf("Player 0 has %d cards in deck.\n", G.deckCount[0]);
	for( i = 0; i < 1; i++)
	{
		printf("\nPlayer %d Deck:\n", i);
		for( j = 0; j < G.deckCount[0]; j++)
		{
			if(G.deck[i][j] == copper)
			{
				printf("Copper");
			}
			else if(G.deck[i][j] == estate)
			{
				printf("Estate");
			}
			else if(G.deck[i][j] == adventurer)
			{
				printf("Adventurer");
			}
		}
	}
	printf("\n");
	printf("Player 0 has %d cards in discard.\n", G.discardCount[0]);
	for( i = 0; i < 1; i++)
	{
		printf("\nPlayer %d Discard:\n", i);
		for( j = 0; j < G.discardCount[0]; j++)
		{
			if(G.discard[i][j] == copper)
			{
				printf("Copper");
			}
			else if(G.discard[i][j] == estate)
			{
				printf("Estate");
			}
			else if(G.discard[i][j] == adventurer)
			{
				printf("Adventurer");
			}
		}
	}
	printf("\n");
	printf("==Playing a adventurer card.==\n");
	playCard(G.handCount[0]-1, -1, -1, -1, &G);
	//Initial Score
	
	printf("Player 0 has %d cards in hand.\n", G.handCount[0]);
	for( i = 0; i < 1; i++)
	{
		printf("\nPlayer %d Hand:\n", i);
		for( j = 0; j < G.handCount[0]; j++)
		{
			if(G.hand[i][j] == copper)
			{
				printf("Copper");
			}
			else if(G.hand[i][j] == estate)
			{
				printf("Estate");
			}
			else if(G.hand[i][j] == adventurer)
			{
				printf("Adventurer");
			}
		}
	}
	printf("\n");
	printf("Player 0 has %d cards in deck.\n", G.deckCount[0]);
	for( i = 0; i < 1; i++)
	{
		printf("\nPlayer %d Deck:\n", i);
		for( j = 0; j < G.deckCount[0]; j++)
		{
			if(G.deck[i][j] == copper)
			{
				printf("Copper");
			}
			else if(G.deck[i][j] == estate)
			{
				printf("Estate");
			}
			else if(G.deck[i][j] == adventurer)
			{
				printf("Adventurer");
			}
		}
	}
	printf("\n");
	printf("Player 0 has %d cards in discard.\n", G.discardCount[0]);
	for( i = 0; i < 1; i++)
	{
		printf("\nPlayer %d Discard:\n", i);
		for( j = 0; j < G.discardCount[0]; j++)
		{
			if(G.discard[i][j] == copper)
			{
				printf("Copper");
			}
			else if(G.discard[i][j] == estate)
			{
				printf("Estate");
			}
			else if(G.discard[i][j] == adventurer)
			{
				printf("Adventurer");
			}
		}
	}
	printf("\n");
	if( G.handCount[0] != 6) 
	{
		printf("TESTING FAILED: INCORRECT AMOUNTS OF CARDS IN HAND\n");
	}
	else
	{
		printf("HAND COUNT TEST SUCCESSFUL\n");
	}
	if(G.deckCount[0] != 4)
	{
		printf("TESTING FAILED: INCORRECT AMOUNTS OF CARDS IN DECK\n");
	}
	else
	{
		printf("DECK COUNT TEST SUCCESSFUL\n");
	}
	if( G.discardCount[0] != 1)
	{
		printf("TESTING FAILED: INCORRECT AMOUNTS OF CARDS IN DISCARD\n");
	}
	else
	{
		printf("DISCARD COUNT TEST SUCCESSFUL\n");
	}
	if(G.handCount[0] == 8 && G.deckCount[0] == 2 && G.discardCount[0] == 1)
	{
		printf("TESTING SUCEEDED\n");
	}

	
	return 0;
}