/*
 * Project Euler Problem 10:
 * - find the sum of all prime numbers below 2,000,000
 */
 
#include <stdio.h>
#include <gmp.h>
#include <math.h>

#define BUFFER_SIZE 200000

unsigned long primes[BUFFER_SIZE];
unsigned long prime_candidate;
unsigned long prime_candidate_root;
unsigned long prime_index;
unsigned long prime_test_index;
int prime = 0;

mpz_t prime_sum;

int main(){
	printf("\nProject Euler Problem 10:\n- find the sum of all prime numbers below 2,000,000\n\n");
	
	// input the first primes
	primes[0] = 2;
	primes[1] = 3;
	
	prime_candidate = 5;
	prime_index = 2;
	prime_test_index = 0;
	
	while(prime_candidate < 2000000){
		prime_candidate_root = sqrtl(prime_candidate);
		//printf("square root of %lu is %lu\n", prime_candidate, prime_candidate_root);
		prime_test_index = 0;
		prime = 1;
		while(primes[prime_test_index] <= prime_candidate_root){
			//printf("%lu modulo %lu\n", prime_candidate, primes[prime_test_index]);
			if((prime_candidate % primes[prime_test_index]) == 0){
				//printf("%lu isn't prime\n", prime_candidate);
				prime = 0;
				break;
			}
			prime_test_index++;
		}
		if(prime){
			primes[prime_index] = prime_candidate;
			printf("\rPrime %lu = %lu", prime_index+1, prime_candidate);
			prime_index++;
		}
		prime_candidate += 2;
	}
	
	printf("\n\n");
	
	mpz_init(prime_sum);
	
	unsigned long n;
	for(n = 0; n < prime_index; n++){
		mpz_add_ui(prime_sum, prime_sum, primes[n]);
	}
	
	printf("Sum of primes < 2,000,000 = ");
	mpz_out_str(stdout, 10, prime_sum);
	printf("\n\n");
	
	return 0;
}
