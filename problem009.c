/* project euler problem 9
 * - find the pythagorean triplet (a^2 + b^2 = c^2) for which a + b + c = 1000
 */
 
#include <stdio.h>

unsigned long a, b, c, numerator, denominator, result;

int main(){
	printf("\nProject euler problem 9\n- find the pythagorean triplet (a^2 + b^2 = c^2) for which a + b + c = 1000\n\n");
	
	a = 0;
	b = 0;
	c = 0;
	
	do{
		b++;
		numerator = 1000000 - (2000*b);
		denominator = 2000- (2*b);
		result = numerator % denominator;
	}while(result);
	
	a = numerator/denominator;
	c = 1000 - (a + b);
	
	printf("\n\na = %d, b = %d, c = %d\n\nProduct = %d\n\n", a, b, c, a*b*c);
	
	
	return 0;
}
