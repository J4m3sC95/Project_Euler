#include <stdio.h>
#include <inttypes.h>

uint32_t collatz_len(uint32_t num){
	uint32_t iterations = 1;
	while(num != 1){
		if(num%2){
			num = (3*num) + 1;
		}
		else{
			num /=2;
		}
		//printf("%d,",num);
		iterations++;
	}
	//printf("\niterations or lenght = %d",iterations);
	return iterations;
}

int main (){
	printf("\nProject Euler problem 14, find the longest collatz sequence under 1 million\n\n");
	
	uint32_t max_num = 0, max_len = 0;
	uint32_t num = 1;
	uint32_t len;
	
	while(num < 1000000){
		printf("\r%d", num);
		len = collatz_len(num);
		if(len > max_len){
			max_len = len;
			max_num = num;
		}
		num++;
	}
	
	printf("\rLongest sequence = %d terms with starting value %d\n\n", max_len, max_num);
	
	return 0;
}
