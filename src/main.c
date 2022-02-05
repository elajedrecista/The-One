/** main.c

She's the one!!!!!!

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "simul.h"
#include "traders.h"

#define BUYER_COUNT 15

int main(void)
{
	printf("Please wait a few seconds. . .\n\n");

	srand(time(NULL));
	struct Seller *the_one = malloc(sizeof(struct Seller));
	struct Buyer *buyers[BUYER_COUNT];
	init_buyers(buyers, BUYER_COUNT);

	// update_cards(the_one, buyers, BUYER_COUNT);
	// trade(the_one, buyers[0]);

	double avg_sell_profit = 0;
	double avg_buy_profit = 0;

	//                123456789
	int iterations = 1000000;
	int tmp_avg = 0;
	for (int k = 0; k < iterations; k++) {
		// 300 trades each round
		for (int i = 0; i < 15; i++) {
			// each buyer
			for (int j = 0; j < BUYER_COUNT; j++) {
				trade(the_one, buyers[j]);
				update_cards(the_one, buyers[j]);
			}
		}
		if (k % 100000 == 0) {
			printf("-------------------------");
			printf("\nROUND %d\n", k);
			print_profits(the_one, buyers, BUYER_COUNT);
		}

		// help calculate average profits
		avg_sell_profit += the_one->profit;

		// average each buyer's profit for this round
		// and add that intermediary average to the true avg
		tmp_avg = 0;
		for (int i = 0; i < BUYER_COUNT; i++)
			tmp_avg += buyers[i]->profit;
		avg_buy_profit += (tmp_avg / BUYER_COUNT);

		// reset profits for next iteration
		the_one->profit = 0;
		for (int i = 0; i < BUYER_COUNT; i++)
			buyers[i]->profit = 0;
	}
	avg_sell_profit /= iterations;
	avg_buy_profit /= iterations;

	printf("\n\n");
	printf("AVERAGE SELL PROFIT: %.02f\n", avg_sell_profit);
	printf("AVERAGE BUY  PROFIT: %.02f\n", avg_buy_profit);

	free(the_one);
	destroy_buyers(buyers, BUYER_COUNT);
	printf("\nSIMULATION COMPLETE.\n\n");
	return 0;
}