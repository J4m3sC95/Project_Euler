/* Project Euler Problem 64
 * - find number of continued fractions with an odd period for numbers < 10,000
 * 
 *  in order to solve this problem and avoid errors caused by multiple iterations of doubleing point math:
 * 		- this program uses an irrational form of the roots in the form (a*sqrt(b) + c)/d 
 */
 
#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 220

// function declerations
unsigned int root_period(unsigned int candidate);
double irrational_to_double(int *irrational_number, double root_b);
void calculate_irrational_remainder(int *irrational_number, int rounded_remainder);
void irrational_inverse(int *irrational_number);
void irrational_number_simplify(int *irrational_number);
void print_irrational_number(int *irrational_number);

int error_count = 0;
int max_period = 0;
int max_period_candidate = 0;
	
 
int main(){
	int n;
	unsigned int odd_period = 0;
	printf("\nProject Euler Problem 64\n- find number of continued fractions with an odd period for numbers < 10,000\n\n");
	
	for(n = 2; n <= 10000; n++){
		if((root_period(n) % 2) != 0){
			odd_period ++;
		}
	}
	
	if(error_count){
		printf("\nNumber of errors = %d\n", error_count);
	}
	else{
		printf("\nNumber of fractions with odd period = %d\nMaximum period = %d for number %d, representation shown below:\n\n", odd_period, max_period, max_period_candidate);
		root_period(max_period_candidate);
		printf("\n");
	}
	
	return 0;
}

// function to calculate the root period
unsigned int root_period(unsigned int candidate){
	int n,m;
	unsigned int iteration[MAX_ITERATIONS + 1];
	unsigned int iteration_index = 0;
	double remainder[MAX_ITERATIONS + 1];
	double candidate_root;
	int candidate_root_int;
	// build irrational number array (a*sqrt(b) + c)/d 
	int irrational_remainder[] = {1, (int)candidate, 0, 1}; 
	// print_irrational_number(irrational_remainder);
	
	// calculate root of number
	candidate_root = sqrt((double)candidate);
	candidate_root_int = (int) candidate_root;
	if((candidate_root * (double)candidate_root_int) == candidate){
		// printf("Candidate is a square number\n\n");
		return 0;
	}
	
	//printf("Root of %d = %f and has the following iterations:\n", candidate, candidate_root);
	for(n = 0; n < MAX_ITERATIONS; n++){
		// calculate the doubleing point version of the remainder
		remainder[iteration_index] = irrational_to_double(irrational_remainder, candidate_root);
		// round the remainder down (to nearest integer) and put into the iteration array
		iteration[iteration_index] = (unsigned int)remainder[iteration_index];
		//printf("Iteration %2d remainder = %f which rounds down to %d\t", iteration_index, remainder[iteration_index], iteration[iteration_index]);
		// calculate new remainder using irrational form
		calculate_irrational_remainder(irrational_remainder, iteration[iteration_index]);
		//printf("New remainder = ");
		//print_irrational_number(irrational_remainder);
		// calculate inverse of the irrational form of the remainder
		irrational_inverse(irrational_remainder);
		//printf("\tInverse remainder = ");
		//print_irrational_number(irrational_remainder);
		//printf("\n");
		
		if(iteration_index > 1){
			if(remainder[iteration_index] == remainder[1]){
				printf("Sqrt(%d) = [%d;(", candidate, iteration[0]);
				for(m = 1; m<iteration_index; m++){
					printf("%d,", iteration[m]);
				}
				printf("\b)], period = %d\n", iteration_index - 1);
				if((iteration_index - 1) > max_period){
					max_period = iteration_index - 1;
					max_period_candidate = candidate;
				}
				return iteration_index -1;
			}
		}
		iteration_index++;
			
	}
	
	printf("Error!! - Not enough iterationsfor number %d\n", candidate);
	error_count++;
	
	return 0;
}

// function to convert an irrational number to a double
double irrational_to_double(int *irrational_number, double root_b){
	double result;
	// a * sqrt(b)
	result = irrational_number[0] * root_b;
	// a*sqrt(b) + c
	result += irrational_number[2];
	// (a*sqrt(b) + c)/d
	result /= irrational_number[3];
	
	return result;
}

// function to calculate the irrational remainder
void calculate_irrational_remainder(int *irrational_number, int rounded_remainder){
	// doubleing point version: remainder = remainder - (double)iteration[iteration_index];
	
	// new c = c - x*d
	irrational_number[2] -= rounded_remainder*irrational_number[3];	
}

// function to calculate the inverse of an irrational number
void irrational_inverse(int *irrational_number){
	int a,b,c,d;
	a = irrational_number[0];
	b = irrational_number[1];
	c = irrational_number[2];
	d = irrational_number[3];
	// a' = ad
	irrational_number[0] = a*d;
	// b' = b
	irrational_number[1] = b;
	// c' = -d*c
	irrational_number[2] = -(d*c);
	// d' = (a^2)*b - (c^2)
	irrational_number[3] = (a*a*b) - (c*c);
	
	irrational_number_simplify(irrational_number);
}

// function to simplify an irrational number
void irrational_number_simplify(int *irrational_number){
	int a,b,c,d,n;
	a = irrational_number[0];
	b = irrational_number[1];
	c = irrational_number[2];
	d = irrational_number[3];
	// find smallest of a, c and d
	int min = a;
	if(c < min){
		min = c;
	}
	if(d < min){
		min = d;
	}
	
	for(n = min; n > 1; n--){
		if((((a%n) == 0) && ((c%n) == 0)) && ((d%n) == 0)){
			a /= n;
			c /= n;
			d /= n;
		}
	}
	irrational_number[0] = a;
	irrational_number[1] = b;
	irrational_number[2] = c;
	irrational_number[3] = d;
}

// function to print out an irrational number 
void print_irrational_number(int *irrational_number){
	int a,b,c,d;
	a = irrational_number[0];
	b = irrational_number[1];
	c = irrational_number[2];
	d = irrational_number[3];
	printf("(%d*sqrt(%d) + %d)/%d",a,b,c,d);
}
