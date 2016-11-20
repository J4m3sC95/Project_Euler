// TODO - create quicker modulo function, subtract higher numbers

#include <stdio.h>
#include <stdint.h>

#define INCREMENT 0
#define DECREMENT 1

//int number_array[] = {600,851,475,143};
int number_array[] = {1,0,0,1};
int test_divisor[] = {0,0,0,5};
unsigned long number = 0;

unsigned long prime_factors[100];

int prime_factor_count = 0;

// function to either increment or decrement count variable, returns 0 if success, 1 if overflow, or 2 if negative
int count_indecrement(int *input, int direction){
	if(direction == INCREMENT){
		input[3] += 1;
		if(input[3] > 999){
			input[2] += 1;
			input[3] -= 1000;
			if(input[2] > 999){
				input[1] += 1;
				input[2] -= 1000;
				if(input[1] > 999){
					input[0] += 1;
					input[1] -= 1000;
					if(input[0] > 999){
						printf("Error!! - Incrementing Overflow\n\n");
						return 1;
					}
				}
			}
		}
	}
	else if(direction == DECREMENT){
		input[3] -= 1;
		if(input[3] < 0){
			input[2] -= 1;
			input[3] += 1000;
			if(input[2] < 0){
				input[1] -= 1;
				input[2] += 1000;
				if(input[1] < 0){
					input[0] -= 1;
					input[1] += 1000;
					if(input[0] < 0){
						printf("Error!! - Decrementing Negative Result\n\n");
						return 2;
					}
				}
			}
		}
	}
	return 0;
}
			

// function to divide number from array, returns 1 if not divisor, returns 0 if success and divides number_array by the divisor
int number_array_division(int *divisor){
	int array[5];
	int count[5] = {0,0,0,0};
	int n,m;
	int finished = 0;
	int result;

	// put number array into array
	for(n = 0; n<4; n++){
		array[n] = number_array[n];
	}
	
	printf("Start value = %03d,%03d,%03d,%03d\t", array[0],array[1],array[2],array[3]);
	printf("Divisor = %03d,%03d,%03d,%03d\t", divisor[0],divisor[1],divisor[2],divisor[3]);

	do{
		for(n = 3; n >= 0; n--){
			// subtract 1000^(3-n)s
			result = array[n] - divisor[n];
			// check if gone negative
			if(result < 0){
				// if working on 1000^3 it cant go negative otherwise its finsihed
				if(n == 0){
					finished = 1;
				}
				else{
					array[n-1] -= 1;
					result += 1000;
				}
			}
			array[n] = result;
		}
		count_indecrement(count, INCREMENT);
	}while(!finished);

	// when finished need to add divisor back on to array to get leftover
	for(n = 3; n>=0; n--){
		result = array[n] + divisor[n];
		if(result > 999){
			array[n-1] += 1;
			result -= 1000;
		}
		array[n] = result;
	}
	count_indecrement(count, DECREMENT);
	
	printf("Result = %03d,%03d,%03d,%03d\t", count[0],count[1],count[2],count[3]);
	printf("Remainder = %03d,%03d,%03d,%03d\n", array[0],array[1],array[2],array[3]);

	//check leftover
	if((array[0]==0) & (array[1]==0) & (array[2]==0) & (array[3]==0)){
		// the divisor is a factor so the new number_array is the count
		for(n = 0; n<4; n++){
			number_array[n] = count[n];
		}
		return 0;
	}
	else{
		return 1;
	}
}

int main(){
	printf("\nProject Euler Problem 3\n- What is the largest prime factor of 600851475143?\n\n");

	if(!number_array_division(test_divisor)){
		printf("successful division!!\n\n");
	}
	else{
		printf("Non-successful division\n\n");
	}
	
	return 0;
}
