#include <stdio.h>
#include <inttypes.h>
#include <math.h>

#define DIGITS 8
#define TARGET_PERCENT 99

uint8_t digits[DIGITS+1];

uint32_t pow_ten(uint8_t power){
	uint8_t n;
	uint32_t result = 1;
	for(n=0;n<power; n++){
		result*=10;
	}
	return result;
}

int is_bouncy(uint32_t input){
	int8_t n;
	// convert number to decimal format
	for(n = DIGITS-1; n >=0; n--){
		digits[n] = input/pow_ten(n);
		input %= pow_ten(n);
	}
	
	uint8_t index = DIGITS-1;
	// find where the number starts
	while(digits[index] == 0){
		index--;
	}

	uint8_t increasing = 1;
	uint8_t decreasing = 1;
	
	//check if increasing
	for(n = index; n>0; n--){
		if(digits[n] > digits[n-1]){
			increasing = 0;
		}
		else if(digits[n] < digits[n-1]){
			decreasing = 0;
		}
	}
	
	if(increasing| decreasing){
		return 0;	
	}
	else{
		return 1;
	}
 }

int main(){
	uint32_t num = 100;
	uint32_t bouncy_count = 0;
	while(1){
		if(is_bouncy(num)){
			bouncy_count++;
		}
		
		if(((bouncy_count * 100) % num) == 0){
			if(((bouncy_count * 100) / num) == TARGET_PERCENT){
				break;
			}
		}
		
		num++;
	}
	printf("\nnumber of bouncy numbers below %d is %d\n\n", num, bouncy_count);
	
	return 0;
}


