#ifndef TRADERS_H
#define TRADERS_H

struct Seller {
	int card;
	int profit;
};

struct Buyer {
	int card;
	int profit;
};

void init_buyers(struct Buyer **buyers, int buyer_count);
void destroy_buyers(struct Buyer **buyers, int buyer_count);
void update_cards(struct Seller *seller, struct Buyer *buyer);

#endif