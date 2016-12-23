#include <stdio.h>

unsigned long sum = 2;
unsigned long old_sum = 0;
unsigned long n_minus_2 = 1;
unsigned long n_minus_1 = 2;
unsigned long n = 0;


#define LIMIT 4000000

int main(){
	printf("\nProject Euler Problem 2\n- find the sum of even fibonacci numbers < 4,000,000\n");
	do{
		// if even add previous fibonacci number to sum
		if((n%2) == 0){
			old_sum = sum;
			sum += n;
			if(old_sum > sum){
				printf("Error!! - Overflow occured");
			}
		}
		//printf("sum = %d,", sum);
		// calculate next fibonacci number
		n = n_minus_2 + n_minus_1;
		//printf("\tnext fibonacci number = %d\n", n);

		// renew n-2 and n-1 variables
		n_minus_2 = n_minus_1;
		n_minus_1 = n;

	}while(n < LIMIT);

	printf("\nFinal sum = %lu\n\n", sum);

	return 0;
}
