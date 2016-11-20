/*
 * Project Euler problem 4
 * - find the higehst palindormic number which is a product of two 3 digit numbers
 * - maximum possile product is 999*999 = 998001
 */

#include <stdio.h>


int palindromic(int input){
	int n;
	int sum = 0;
	int number[7];
	int digit_count = 6;
	int return_val = 1;
	
	// store number into array
	number[0] = input/100000;
	sum += number[0] * 100000;
	number[1] = (input-sum)/10000;
	sum += number[1] * 10000;
	number[2] = (input-sum)/1000;
	sum += number[2] * 1000;
	number[3] = (input-sum)/100;
	sum += number[3] * 100;
	number[4] = (input-sum)/10;
	sum += number[4] * 10;
	number[5] = input - sum;
	sum += number[5];
	
	//// print number
	//for(n = 0; n<6; n++){
		//printf("%d",number[n]);
	//}
	
	
	// find out how many digits	
	while(1){
		if(number[6-digit_count]){
			break;
		}
		else{
			digit_count --;
		}
	}
	
	int offset = 6 - digit_count;
	
	for(n = 0; n<(digit_count/2); n++){
		if(number[n + offset] != number[(digit_count - n) + offset - 1]){
			return_val = 0;
		}
	}
	
	//printf("\n\nDigit count = %d\n", digit_count);
	
	return return_val;
}

int main(){
	printf("Project Euler Problem 4\n- find the highest palindromic number which is a product of two 3 digit numbers");
	
	int n,m,product, operand1, operand2;
	int result = 0;
	
	for(n = 999; n > 900; n--){
		for(m = 999; m>900; m--){
			product = n*m;
			if(palindromic(product)){
				if(product > result){
					result = product;
					operand1 = n;
					operand2 = m;
				}
			}
		}
	}
	
	printf("\nResult: %d*%d = %d\n", operand1,operand2,result);
	
	return 0;
}

