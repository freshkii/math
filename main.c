#include "numbers.h"
#include <stdio.h>

int main(void){
	Numbers nbs;

	init_numbers(&nbs, 0);
	add_number(&nbs,12);
	add_number(&nbs,9);
	add_number(&nbs,7);
	print_numbers(&nbs, 0, nbs.size, 1);
	pop_number(&nbs, 1);
	print_numbers(&nbs, 0, nbs.size, 1);

	free_numbers(&nbs);

	Numbers divs;
	init_numbers(&divs,5);
	get_dividors(&divs,12);
	print_numbers(&divs,0,divs.size,1);

	Numbers primes;
	init_numbers(&primes, 50);
	crible(&primes, 50);
	print_numbers(&primes, 0, primes.size, 1);

	Numbers dividors;
	init_numbers(&dividors, 20);
	get_prime_dividors(&dividors, 23);
	print_numbers(&dividors,0,dividors.size,1);
	free_numbers(&dividors);
	init_numbers(&dividors, 20);
	get_prime_dividors(&dividors, 21);
	print_numbers(&dividors,0,dividors.size,1);

	printf("est-ce que 10 est premier ?");
	if (is_prime(10))
		printf("oui\n");
	else
		printf("non\n");

	printf("est-ce que 11 est premier ?");
	if (is_prime(11))
		printf("oui\n");
	else
		printf("non\n");

	printf("est-ce que les entier 2 et 5 sont premiers entre eux ?");
	if (are_primes(2,5))
		printf("oui\n");
	else
		printf("non\n");
	return 0;
}

