#include <stdio.h>
#include <gmp.h>

unsigned long int n, sum;
mpz_t square_sum, sum_square, result;

int main(){
	printf("\nProject Euler Problem 6:\n\tfind the difference between:\n\t\t- the sum of sqaures below 100\n\t\t- the sume of numbers below 100 sqaured\n\n");
	// initialise multi precision numbers
	mpz_init(square_sum);
	mpz_set_ui(square_sum, 0);
	mpz_init(sum_square);
	mpz_init(result);
	
	// calculates sum of squares below 100
	for(n = 1; n <=100; n++){
		mpz_add_ui(square_sum, square_sum, n*n);
	}
	
	printf("Sum of squares = ");
	mpz_out_str(stdout, 10, square_sum);
	printf("\n\n");
	
	// calculate square of sum
	sum = 0;
	for(n = 1; n<=100; n++){
		sum += n;
	}
	
	mpz_ui_pow_ui(sum_square, sum, 2);
	printf("Sum of numbers < 100 = %lu\nSquared = ", sum);
	mpz_out_str(stdout, 10, sum_square);
	printf("\n\n");
	
	mpz_sub(result, sum_square, square_sum);
	printf("Square of sum - sum of squares = ");
	mpz_out_str(stdout, 10, result);
	printf("\n\n");
	
	return 0;
}
