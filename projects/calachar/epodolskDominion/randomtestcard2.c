/* Ralph Calachan
random Test 2 */

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
		int k[10] = {adventurer, outpost, outpost, village, outpost, outpost, cutpurse,
			   outpost, outpost, smithy};

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
		
		G.outpostPlayed = rand()%20;
		int initialHandCount = G.handCount[0];
		int initialOutpost = G.outpostPlayed;
		int initialDiscard = G.discardCount[0];
		
		outpostCard( &G, G.handCount[0]-1, G.whoseTurn);
		
		if( G.handCount[0] != (initialHandCount-1)){
			printf(" ERROR(HANDCOUNT) Run %d: DeckCount = %d, HandCount = %d, Expected HandCount = %d\n", iterator, G.deckCount[0], G.handCount[0], (initialHandCount-1));
		}
		
		if( G.outpostPlayed != (initialOutpost + 1)){
			printf(" ERROR(OUTPOST COUNT) Run %d: DeckCount = %d, Outpost Number = %d, Expected HandCount = %d\n", iterator, G.deckCount[0], G.outpostPlayed, (initialOutpost+1));
		}
		
		if( G.discardCount[0] != (initialDiscard + 1)){
			printf(" ERROR(DISCARDCOUNT) Run %d: DeckCount = %d, DISCARD COUNT = %d, Expected Discard Count = %d\n", iterator, G.deckCount[0], G.discardCount[0], (initialDiscard+1));
		}
	}
	
	return 0;
}