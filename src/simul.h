#ifndef SIMUL_H
#define SIMUL_H

#include "traders.h"

void print_profits(struct Seller *seller, struct Buyer** buyers,
                   int buyer_count);
void trade(struct Seller *seller, struct Buyer *buyer);

#endif