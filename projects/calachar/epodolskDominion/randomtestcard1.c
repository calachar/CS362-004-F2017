/* Ralph Calachan
Card Test 1 */

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
int main (int argc, char** argv) {
	int iterator;
	
	for( iterator = 0; iterator < 200; iterator++)
	{
		int i;
		int j;
		struct gameState G;
		int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
			   sea_hag, tribute, smithy};

		printf("Random Test %d : Smithy Function Test\n", iterator);

		initializeGame(2, k, atoi(argv[1]), &G);
		
		/*
		printf("Adding smithy card to player 0's hand.\n");
		G.hand[0][G.handCount[0]] = smithy;
		G.handCount[0]++;
		
		printf("Player 0 has %d cards in hand.\n", G.handCount[0]);
		printf("Player 0 has %d cards in deck.\n", G.deckCount[0]);
		printf("Player 0 has %d cards in discard.\n", G.discardCount[0]);
		*/
		
		/* CREATE GAMES AND TEST */
		for( i = 0; i < G.numPlayers; i++){
			G.handCount[i] = rand()%30;
			for( j = 0; j < G.handCount[i]; j++){
				G.hand[i][j] = k[rand()%10];
			}
			G.hand[i][G.handCount[i]] = smithy;
			G.handCount[i]++;
		}
		
		for( i = 0; i < G.numPlayers; i++){
			G.discardCount[i] = rand()%30;
			for( j = 0; j < G.discardCount[i]; j++){
				G.hand[i][j] = k[rand()%10];
			}
		}
		
		for( i = 0; i < G.numPlayers; i++){
			G.deckCount[i] = rand()%30;
			for( j = 0; j < G.deckCount[i]; j++){
				G.deck[i][j] = k[rand()%10];
			}
		}
		
		int playerNumCards = G.handCount[0] + 2;
		
		smithyCard( &G, G.whoseTurn, G.handCount[0]-1 );
		
		if( G.handCount[0] != (playerNumCards)){
			printf(" ERROR Run %d: DeckCount = %d, HandCount = %d, Expected HandCount = %d\n", iterator, G.deckCount[0], G.handCount[0], playerNumCards);
		}
		
	}
	
	return 0;
}