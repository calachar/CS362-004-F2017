/* Ralph Calachan
Unit Test 4 */

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
	printf("Unit Test 4: Score Game Function Test\n");
	printf("==========\n\n");

	initializeGame(2, k, atoi(argv[1]), &G);
  
	//Initial Score
	
	printf("Player 0 has %d points, should be 3.\n", scoreFor(0, &G));
	
	printf("Adding a estate to the discard pile\n");
	if(scoreFor(0,&G) == 10)
	{ printf("CORRECT SCORE\n");}
	else
	{ printf("INCORRECT SCORE\n");}

	//add Estate to Discard
	G.discard[0][0] = estate;
	G.discardCount[0] += 1;
	printf("Player 0 has %d points, should be 4.\n", scoreFor(0, &G));
	if(scoreFor(0,&G) == 11)
	{ printf("CORRECT SCORE\n");}
	else
	{ printf("INCORRECT SCORE\n");}
	printf("Adding a estate to the hand\n");
	
	
	//add Estate to Hand
	G.hand[0][G.handCount[0]] = estate;
	G.handCount[0] += 1;
	printf("Player 0 has %d points, should be 5.\n", scoreFor(0, &G));
	if(scoreFor(0,&G) == 12)
	{ printf("CORRECT SCORE\n");}
	else
	{ printf("INCORRECT SCORE\n");}
	printf("Adding a estate to the deck\n");
	
	//add Estate to Deck
	G.deck[0][G.deckCount[0]] = estate;
	G.deckCount[0] += 1;
	printf("Player 0 has %d points, should be 6.\n", scoreFor(0, &G));
	if(scoreFor(0,&G) == 11)
	{ printf("CORRECT SCORE\n");}
	else
	{ printf("INCORRECT SCORE\n");}
	

	
	return 0;
}