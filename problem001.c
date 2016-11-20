//  todo: incorrect answer the sum is of multiples of 5 or 3 not both

#include <stdio.h>

unsigned long grand_total = 0;

int n;


unsigned long multiple_sum(int multiple, int limit, int exclusion){
	unsigned int max_val;
	unsigned long sum = 0;
	unsigned long old_sum = 0;

	// find sum of all multiples of 'multiple'
	max_val = ((limit - 1)/multiple)*multiple;
	printf("highest multiple of %d below %d is %d which is %d*%d\n", multiple, limit, max_val, max_val/multiple, multiple);

	for(n = max_val/multiple; n > 0; n --){
		// check for repeat counts eg exclusion multiple
		if(exclusion){
			if((n % exclusion) != 0){
				sum += n;
			}
		}
		else{
			sum += n;
		}
		// check for overflow
		if(old_sum > sum){
			printf("Error!! - addition overflow");
			return 0;
		}
		old_sum = sum;
	}
	sum *= multiple;

	if(old_sum > sum){
		printf("Error!! - multiplication overflow");
		return 0;
	}

	printf("Sum of all multiples of %d = %d\n\n", multiple, sum);

	return sum;
}

int main(){
	printf("Project Euler - problem 1\n - find the sum of multiples of 3 or 5 below 1000\n\n");

	grand_total += multiple_sum(3, 1000, 5);

	//printf("Sum after multiples of 3 added = %d\n", grand_total);

	grand_total += multiple_sum(5, 1000, 0);

	//printf("Sum after multiples of 5 added = %d\n", grand_total);

	printf("Complete!! - Sum = %d\n\n", grand_total);

	return 0;
}
