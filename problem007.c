#include <stdio.h>

unsigned long primes[10002];
unsigned long prime_candidate;
int n;
int prime_count = 1;
int prime_check, complete;

int main(){
	printf("Project Euler Problem 7:\n- Find the 10,001st prime number\n\n");
	
	primes[0] = 2;
	prime_candidate = 3;
	
	while(complete != 1){
		prime_check = 1;
		for(n = 0; n < prime_count; n++){
			if((prime_candidate % primes[n]) == 0){
				prime_check = 0;
				break;
			}
		}
		if(prime_check){
			printf("\rPrime number %d = %lu", prime_count + 1, prime_candidate);
			primes[prime_count] = prime_candidate;
			prime_count++;
		}
		if(prime_count == 10001){
			complete = 1;
		}
		prime_candidate += 2;	
	}	
	
	printf("\n\n");
	
	return 0;
}
