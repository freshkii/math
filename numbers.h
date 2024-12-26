#ifndef __numbers_h__
#define __numbers_h__

#define ADDING_NUMBERS_CAPACITY 10

#include <stdbool.h>
#include <stdlib.h>

typedef struct {
	long* list;
	uint size;
	uint capacity;
} Numbers;


void init_numbers(Numbers *nbs, uint size);
void add_number(Numbers *nbs, long n);
void pop_number(Numbers *nbs, uint index);
void print_numbers(Numbers *nbs, int start, int end, int step);
void free_numbers(Numbers *nbs);

void fill_range_numbers(Numbers *nbs, uint start, uint end, uint step);

void crible(Numbers *result, uint n);
void get_dividors(Numbers *result, uint n);
void get_prime_dividors(Numbers *result, uint n);

bool is_prime(uint n);
bool are_primes(uint a, uint b);

#endif // __numbers_h__
