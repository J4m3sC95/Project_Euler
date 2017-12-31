#include <stdio.h>
#include <inttypes.h>
#include <string.h>

char *number_strings[21] = {"","One", "Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
char *tens_string[11]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty", "Ninety"};

int main(){
	uint16_t number;
	uint32_t char_count = 0;
	uint8_t index;
	
	char temp[100] = "";
	char text[100] = "";
	printf("\n");
	
	for(number = 1; number <=1000; number++){
		printf("\r%d = ", number);
		
		uint8_t hundreds, teens, tens, units;
		
		hundreds = (number % 1000) / 100;
		teens = number % 100;
		tens = (number % 100)/10;
		units = number %10;
		
		if(number == 1000){
			sprintf(temp,"One Thousand ");	
			strcat(text, temp);
		}	
		if(hundreds){
			sprintf(temp,"%s Hundred ", number_strings[hundreds]);
			strcat(text, temp);
		}
		if((teens > 9) && (teens < 20)){
			if(hundreds){
				sprintf(temp,"and ");
				strcat(text, temp);
			}
			sprintf(temp,"%s", number_strings[teens]);
			strcat(text, temp);
		}
		else{
			if(tens){
				if(hundreds){
					sprintf(temp,"and ");
					strcat(text, temp);
				}
				sprintf(temp,"%s", tens_string[tens]);
				strcat(text, temp);
				if(units){
					sprintf(temp,"-%s", number_strings[units]);
					strcat(text, temp);
				}
			}
			else if(units){
				if(hundreds){
					sprintf(temp,"and ");
					strcat(text, temp);
				}
				sprintf(temp,"%s",number_strings[units]);
				strcat(text, temp);
			}
		}
		// print string
		printf("%s",text);
		
		//count string entries
		index = 0;
		while(text[index] != 0){
			if(!((text[index] == '\n') || (text[index] == ' ') || (text[index] == '-'))){
				char_count++;
			}
			index++;
		}
		
		//clear string
		strcpy(text, "");
	}		
	
	printf("\n\nCharacter count = %d\n\n", char_count);
	
	
		
	return 0;
}
