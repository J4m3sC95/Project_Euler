#include <stdio.h>
#include <inttypes.h>
#include <math.h>

uint16_t factor_count(uint32_t number){
	uint32_t n, count = 0;
	// number of factors = number of factors below the square root of the number * 2
	uint32_t root = (uint32_t)sqrt(number);
	for(n = 1; n <= root; n++){
		if((number % n) == 0){
			count++;
		}
	}
	return count << 1;
}

int main(){
	printf("\nProject Euler problem number 12:\n-find the first triangle number which has more than 500 factors\n\n");
	uint32_t triangle_num = 1;
	uint32_t natural_num = 1;
	while(factor_count(triangle_num) < 500){
		printf("\r%d",triangle_num);
		natural_num++;
		triangle_num += natural_num;
	}
	printf("\rFirst number with more than 500 factors = %d\n\n",triangle_num);
	
	return 0;
}

