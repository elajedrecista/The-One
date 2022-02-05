/** traders.c

Implement buyers and sellers for the simulation.

Initialize both types of traders. Updates their cards after each
trade.

*/

#include <stdlib.h>

#include "traders.h"

static void init_buyer(struct Buyer *buyer)
{
	if (buyer == NULL)
		return;

	buyer->card = 0;
	buyer->profit = 0;
}

void init_buyers(struct Buyer **buyers, int buyer_count)
{
	if (buyers == NULL)
		return;

	for (int i = 0; i < buyer_count; i++) {
		buyers[i] = malloc(sizeof(struct Buyer));
		if (buyers[i] != NULL)
			init_buyer(buyers[i]);
		else
			return;
	}
}

void destroy_buyers(struct Buyer **buyers, int buyer_count)
{
	if (buyers == NULL)
		return;

	for (int i = 0; i < buyer_count; i++)
		free(buyers[i]);
}

// static int gen_card(void)
// {
// 	int cards[] = {1,1,1,2,2,3,4,5,8,9,9,10,10,10};
// 	return cards[rand() % 14];
// }

// static int gen_sell_card(void)
// {
// 	int cards[] = {1,1,2,8,9,9,10,10,10};
// 	return cards[rand() % 9];
// }

// static int gen_buy_card(void)
// {
// 	int cards[] = {1,1,1,1,2,2,3,8,9,10};
// 	return cards[rand() % 10];
// }

void update_cards(struct Seller *seller, struct Buyer *buyer)
{
	// random seed should be called by main()

	// % 10 will return int from 0-9
	// +1 so we get a random num in [1,10]
	seller->card = (rand() % 10) + 1;
	buyer->card = (rand() % 10) + 1;
	// seller->card = gen_card();
	// buyer->card = gen_card();
	// seller->card = gen_sell_card();
	// buyer->card = gen_buy_card();
}