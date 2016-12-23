#include <stdio.h>
#include <gmp.h>

int division_complete = 0;
int factorisation_complete = 0;
int five_count = 0;

const char *number_array = "600851475143";

mpz_t number, root, divisor, division_remainder;
unsigned long int divisor_integer;

int main(){
	// setup number
	
	mpz_init(number);
	mpz_set_str(number, number_array, 10);
	printf("\nStarting number = ");
	mpz_out_str(stdout, 10, number);
	printf("\n\n");
	
	mpz_init(root);
	mpz_init(divisor);
	mpz_init(division_remainder);

	// loop until complete
	while(!factorisation_complete){
		mpz_sqrt(root, number);
		printf("Truncated square root of ");
		mpz_out_str(stdout, 10, number);
		printf(" is:");
		mpz_out_str(stdout, 10, root);
		printf("\n\n");
				
		// set initial divisor
		divisor_integer = 2;
		mpz_set_ui(divisor, divisor_integer);
		
		five_count = 0;
		division_complete = 0;
		
		while(!division_complete){
			// perform divison (find the remainder)
			mpz_cdiv_r(division_remainder, number, divisor);
			// if no remainder then is divisible perform the division
			if(mpz_cmp_ui(division_remainder, 0) == 0){
				mpz_out_str(stdout, 10, number);
				mpz_cdiv_q(number, number, divisor);
				printf(" divided by ");
				mpz_out_str(stdout, 10, divisor);
				printf(" = ");
				mpz_out_str(stdout, 10, number);
				printf("\n");
				
				division_complete = 1;
			}
			// if not divisible increment the divisor (avoid multiples of 5)
			else{
				// increment divisor
				if(divisor_integer == 2){
					divisor_integer = 3;
					mpz_set_ui(divisor, divisor_integer);
				}
				else if(divisor_integer == 3){
					divisor_integer = 5;
					mpz_set_ui(divisor, divisor_integer);
				}
				else if(divisor_integer == 5){
					five_count++;
					if(five_count == 5){
						five_count = 1;
						mpz_add_ui(divisor,divisor, 4);
					}
					else{
						mpz_add_ui(divisor,divisor,2);
					}
				}
				if(mpz_cmp(divisor, root) > 0){
					mpz_out_str(stdout, 10, number);
					printf(" is the largest prime factor!!");
					printf("\n");
					factorisation_complete = 1;
					division_complete = 1;
				}
			}
		}	
	}
	
	printf("\n\n");
		

	return 0;
}
