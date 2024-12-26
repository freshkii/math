#include "numbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CHECK_MEM_ALLOC(X) \
	do {\
		if ((X) == NULL){\
			fprintf(stderr, "error: couldn't alloc memory\n");\
			exit(EXIT_FAILURE);\
		}\
	} while(0) // the ending semi-colon is left for the user

void init_numbers(Numbers *nbs, uint size){
	nbs->size = 0;
	nbs->capacity = size;
	nbs->list = (long*)malloc(sizeof(long) * nbs->capacity);
	CHECK_MEM_ALLOC(nbs->list);
}

void free_numbers(Numbers *nbs){
	if (nbs->list)
		free(nbs->list);
}

void add_number(Numbers *nbs, long n){
	if (nbs->size == nbs->capacity){
		nbs->capacity += ADDING_NUMBERS_CAPACITY;
		long *temp = (long*)realloc(nbs->list,sizeof(long) * nbs->capacity);
		CHECK_MEM_ALLOC(temp);
		nbs->list = temp;
	}
	nbs->list[nbs->size++] = n;
}

void pop_number(Numbers *nbs, uint index){
	if (!nbs->size || nbs->size <= index)
		return;

	for (int i = index+1;i<nbs->size;i++){
		nbs->list[i-1] = nbs->list[i];
	}

	nbs->size--;
}

void print_numbers(Numbers *nbs, int start, int end, int step) {
	if (step == 0 || nbs->size == 0){
		return;
	}

	if (0<=start && start < nbs->size) {
		printf("%li",nbs->list[start]);
	}
	
	if (end%nbs->size!=0){
		end = end % nbs->size;
	}
	for (int i = (start+step); i != end; i+= step){
		int r = i % nbs->size;
		printf(", %li", nbs->list[r]);
	}
	printf("\n");
}

void fill_range_numbers(Numbers *nbs, uint start, uint end, uint step){
	for (uint c = start; c != end; c+=step){
		add_number(nbs, c);
	}
}


void crible(Numbers *result, uint n){
	Numbers N;
	init_numbers(&N,n);
	fill_range_numbers(&N, 2, n+1, 1);
	uint c = 0;
	while (N.size) {
		c = N.list[0];
		add_number(result,c);
		pop_number(&N,0);
		for (int i=N.size-1;i > -1;i--){
			if (N.list[i]%c==0){
				pop_number(&N,i);
				i--;
			}
		}
	}
}

void get_dividors(Numbers *result, uint n) {
	if (n==0)
		return;
	uint max = (uint)sqrt(n)+1;
	for (int d = 1; d < max; d++) {
		if (n%d == 0) {
			add_number(result, d);
		}
	}

	if (result->size == 2)
		return;

	for (int i = result->size-1; -1< i;i--) {
		add_number(result,n/result->list[i]);
	}
}

void get_prime_dividors(Numbers *result, uint n) {
	Numbers primes;

	init_numbers(&primes, n);
	crible(&primes,n+1);

	int index = 0;
	while (n != 1){
		if (n%primes.list[index]==0){
			n /= primes.list[index];
			add_number(result, primes.list[index]);
		} else{
			index++;
		}
	}

	if (result->size == 0){
		add_number(result, n);
	}
}


bool is_prime(uint n){
	if (n == 1)
		return false;

	if (n == 2)
		return true;

	int max = (int)sqrt(n)+1;
	for (int i =2;i<max;i++){
		if (n % i == 0)
			return false;
	}

	return true;
}

bool are_primes(uint a, uint b) {
	int m = fmin(a,b);
	for (int i=2;i<=m;i++){
		if (a%i==0 && b%i==0)
			return false;
	}

	return true;
}
