/** simul.c

Simulate each trade between buyer and seller. Print everyone's
net profits.

*/

#include <stdio.h>
#include <stdlib.h>

#include "simul.h"
#include "traders.h"

void print_profits(struct Seller *seller, struct Buyer** buyers,
                   int buyer_count)
{
	for (int i = 0; i < buyer_count; i++) {
		printf("BUYER %02d: ", i+1);
		if (buyers[i]->profit < 0)
			printf("-");
		else
			printf(" ");
		printf("$%d\n", abs(buyers[i]->profit));
		// printf("LAST CARD: %d\n\n", buyers[i]->card);
	}
	printf("  SELLER:  $%d\n", seller->profit);
	// printf("LAST CARD: %d\n\n", seller->card);
}

void trade(struct Seller *seller, struct Buyer *buyer)
{
	int price = 7;
	seller->profit += (price - seller->card);
	buyer->profit += (buyer->card - price);
}