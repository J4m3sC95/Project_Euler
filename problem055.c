#include <stdio.h>

#define ARRAY_SIZE 30
#define ARRAY_LENGTH (ARRAY_SIZE + 1)

void array_initialise(unsigned char *array, int array_size){
	int n;
	// fill array with zeros
	for(n = 0; n<array_size; n++){
		array[n] = 0;
	}	
}

// takes an integer (5 digits or less) puts it into an array in base 10
void number_to_array(int number, unsigned char *array, int array_size){
	int index_offset = array_size - 6;
	int sum = 0;
	
	// put number into array
	array[0 + index_offset] = number/100000;
	sum += array[0 + index_offset] * 100000;
	array[1 + index_offset] = (number-sum)/10000;
	sum += array[1 + index_offset] * 10000;
	array[2 + index_offset] = (number-sum)/1000;
	sum += array[2 + index_offset] * 1000;
	array[3 + index_offset] = (number-sum)/100;
	sum += array[3 + index_offset] * 100;
	array[4 + index_offset] = (number-sum)/10;
	sum += array[4 + index_offset] * 10;
	array[5 + index_offset] = (number-sum);
	sum += array[5 + index_offset];
}

// takes an integer array and counts the digits of the stored number
int digit_count(unsigned char *array, int array_size){
	int m = 0;
	while(1){
		// find out how many digits the number has
		if(array[m] != 0){
			return array_size - m;
		}
		else{
			m++;
		}
	}
}

// prints out an integer array
void array_print(unsigned char *array, int array_size){
	int n;
	int print_enable = 0;
	for(n = 0; n < array_size; n++){
		if(array[n] != 0){
			print_enable = 1;
		}
		if(print_enable){
			printf("%d", array[n]);
		}
	}
}

// reverses an integer array
void array_reverse(unsigned char *array, unsigned char *reverse_array, int array_size, int number_length){
	int n;
	int offset = array_size - (number_length);
	for(n = 0; n< number_length; n++){
		reverse_array[array_size - (1+n)] = array[offset + n];
	}
}

// adds two number arrays together
void array_addition(unsigned char *array1, unsigned char *array2, unsigned char *sum, int array_size){
	int n;
	int carry = 0;
	for(n = array_size - 1; n >= 0; n--){
		sum[n] = array1[n] + array2[n] + carry;
		carry = 0;
		if(sum[n] >= 10){
			sum[n] -= 10;
			carry = 1;
		}
	}
}		

// checks if integer array is palindromic or not
int palindromic_check(unsigned char *array, int array_length){
	int n;
	int array_digit_count = digit_count(array, ARRAY_SIZE);
	int offset = array_length - array_digit_count;
	for(n = 0; n<(array_digit_count/2); n++){
		if(array[n + offset] != array[(array_digit_count - n) + offset - 1]){
			return 0;
		}
	}
	
	return 1;
}

// checks if a number is a lychrel number or not, 1 = lychrel, 0 = not lychrel
int lychrel_check(int candidate){
	int n;
	unsigned char candidate_array[ARRAY_LENGTH];
	unsigned char reversed_candidate_array[ARRAY_LENGTH];
	unsigned char candidate_sum[ARRAY_LENGTH];
	array_initialise(candidate_array, ARRAY_SIZE);
	array_initialise(reversed_candidate_array, ARRAY_SIZE);
	array_initialise(candidate_sum, ARRAY_SIZE);
	
	int iteration_count = 0;
	int candidate_digit_count = 0;
	
	// put candidate number into array form
	number_to_array(candidate, candidate_array, ARRAY_SIZE);

	while(iteration_count <= 50){
		// perform iteration
		//printf("Iteration %d, number = %d, array = ", iteration_count, candidate);
		//array_print(candidate_array, ARRAY_SIZE);
		// - find the digit count of the current iteration
		candidate_digit_count = digit_count(candidate_array, ARRAY_SIZE);
		//printf(", %d digits, reversed = ", candidate_digit_count);
		// - reverse number
		array_reverse(candidate_array, reversed_candidate_array, ARRAY_SIZE, candidate_digit_count);
		//array_print(reversed_candidate_array, ARRAY_SIZE);
		// - add numbers
		array_addition(candidate_array, reversed_candidate_array, candidate_sum, ARRAY_SIZE);
		//printf(" sum = ");
		//array_print(candidate_sum, ARRAY_SIZE);

		// - check if sum is palindromic
		if(palindromic_check(candidate_sum, ARRAY_SIZE)){
			//printf(" = palindromic\n");
			return 0;
		}
		else{
			iteration_count++;
			for(n = 0; n < ARRAY_SIZE; n++){
				candidate_array[n] = candidate_sum[n];
			}
		}
		//printf("\n");
	}
	return 1;
}

int main(){
	int n;
	
	printf("\nProject Euler Problem 55:\n - find how many lychrel numbers there are below 10,000\n\n");
	
	int lychrel_count = 0;
	for(n = 1; n<10000; n++){
		if(lychrel_check(n)){
			lychrel_count++;
			printf("Lychrel number %d = %d\n", lychrel_count, n);
		}
	}
	printf("\n");
	
	return 0;
}
