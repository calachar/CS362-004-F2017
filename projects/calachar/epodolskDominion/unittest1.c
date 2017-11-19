/* Ralph Calachan
Unit Test 1 */

#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
int main (int argc, char** argv) {
	
	struct gameState G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

	printf("==========\n\n");
	printf("Unit Test 1: Initialize Game Function Test\n");
	printf("==========\n");

	initializeGame(2, k, atoi(argv[1]), &G);
  
	/*Testing for number of Players*/
	printf(" Number of Players : %d, Supposed to be 2 \n", G.numPlayers );
	if( G.numPlayers == 2)
	{
		printf(" Player Count Correct! \n");
	}
	else
	{
		printf(" Player Count Incorrect =( \n");
	}
	
	/* Testing for supply count */
	printf(" Number of Supply/Curse : %d, Supposed to be 10 \n", G.supplyCount[curse]);
	if( G.supplyCount[curse] == 10)
	{
		printf(" Supply Count Correct! \n");
	}
	else
	{
		printf(" Supply Count Incorrect =( \n");
	}
	
	/* Testing for duchy count */
	printf(" Number of Supply/Duchy : %d, Supposed to be 8 \n", G.supplyCount[duchy]);
	if( G.supplyCount[duchy] == 8)
	{
		printf(" Supply Count Correct! \n");
	}
	else
	{
		printf(" Supply Count Incorrect =( \n");
	}
	
	/* Testing for estate count */
	printf(" Number of Supply/Estate : %d, Supposed to be 8 \n", G.supplyCount[estate]);
	if( G.supplyCount[estate] == 8)
	{
		printf(" Supply Count Correct! \n");
	}
	else
	{
		printf(" Supply Count Incorrect =( \n");
	}
	
	/* Testing for province count */
	printf(" Number of Supply/Province : %d, Supposed to be 8 \n", G.supplyCount[province]);
	if( G.supplyCount[province] == 8)
	{
		printf(" Supply Count Correct! \n");
	}
	else
	{
		printf(" Supply Count Incorrect =( \n");
	}
	
	int i;
	int j;
	int copperCount;
	int estateCount;
	for( i = 0; i < G.numPlayers; i++)
	{
		copperCount = 0;
		estateCount = 0;
		for( j = 0; j < 10; j++)
		{
			if( G.deck[i][j] == estate)
			{
				estateCount += 1;
			}
			else if( G.deck[i][j] == copper)
			{
				copperCount += 1;
			}
			else
			{
				printf("Error, non-copper/non-estate card in opening hand!\n");
			}
		}
		
		printf(" Player %d, Coppers: %d (should be 7), Estates: %d (should be 3)\n", i, copperCount, estateCount);
		
		if( copperCount == 7)
		{
			printf(" Copper Count Correct! \n");
		}
		else
		{
			printf(" Copper Count Incorrect =( \n");
		}
		
		if( estateCount == 3)
		{
			printf(" Estate Count Correct! \n");
		}
		else
		{
			printf(" Estate Count Incorrect =( \n");
		}
	}
	
	/*
	printf ("Finished game.\n");
	printf ("Player 0: %d\nPlayer 1: %d\n", scoreFor(0, &G), scoreFor(1, &G));
	*/
	
	return 0;
}
  