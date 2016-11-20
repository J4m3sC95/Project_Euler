#include <stdio.h>

int n,m;

int main(){
	printf("Project Euler Problem 5\n- what is the lowest number whcih is  evenly divisible by all numbers from 1 to 20\n\n");
	
	int product = 3*16;
	int prime;
	
	// find product of all prime numbers < 21
	
	for(n = 3; n<=20; n += 2){
		// determine if n is prime
		prime = 1;
		for(m = n - 2; m>= 3; m -=2){
			if((n % m) == 0){
				prime = 0;
			}
		}
		
		if(prime){
			//printf("Prime: %d\n", n);
			product *= n;
		}
	}
	
	printf("\nProduct of all primes below 20 = %d\n\n", product);
	
	// check divisible by everything
	printf("Checking divisible by everything\n");
	for(n = 1; n <=20; n++){
		if((product % n) != 0){
			printf("Not divisible by %d\n", n);
		}
	}
	
	printf("\n");
	
	return 0;
}
	
	
