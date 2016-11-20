#include <stdio.h>
#include <stdlib.h>

char file_path[] = "cipher.txt";

// prints out an integer array
void array_print(unsigned char *array, int array_size){
	int n;
	for(n = 0; n < array_size; n++){
		printf("%d,", array[n]);
	}
}

int main(){
	unsigned char n;
	int char_count = 0;
	unsigned int temp_data_index = 0;
	unsigned int raw_data_index = 0;
	
	printf("\nProject Euler Problem 59\n- XOR decryption\n\n");
	
	// open file and get data
	FILE *input_file = fopen(file_path, "r+");
	
	while(!feof(input_file)){
		fread(&n, 1, 1, input_file);
		if(n == ','){
			char_count++;
		}			
	}
	// add one more as there is no comma at the end of the input
	char_count++;
	fclose(input_file);
	printf("Character count of input file = %d\n\n", char_count);
	
	// create dynamic array to store the data in
	unsigned char *raw_data = malloc(char_count * sizeof(char));
	
	// put data into array
	input_file = fopen(file_path, "r+");
	unsigned char temp_data[4] = {0,0,0};
	while(!feof(input_file)){
		fread(&n, 1, 1, input_file);
		if(n == ','){
			// then put number from temp_data into correct raw_data array place
			if(temp_data_index == 1){
				raw_data[raw_data_index] = temp_data[0];
			}
			else if(temp_data_index == 2){
				raw_data[raw_data_index] = (temp_data[0] * 10) + temp_data[1];
			}
			else{
				printf("Error - temp data index = %d", temp_data_index);
			}
			temp_data_index = 0;
			raw_data_index++;
		}
		else if(isalnum(n)){
			// put number in correct place in temp_data array
			if(temp_data_index > 3){
				printf("oi%d, n = %d at raw_data_index %d\n", temp_data_index, n, raw_data_index);
			}
			temp_data[temp_data_index] = n - 48;
			temp_data_index++;
		}
	}
	// put final value into raw_data array
	if(temp_data_index == 1){
		raw_data[raw_data_index] = temp_data[0];
	}
	else if(temp_data_index == 2){
		raw_data[raw_data_index] = (temp_data[0] * 10) + temp_data[1];
	}
	else{
		printf("Error - temp data index final = %d", temp_data_index);
	}
	
	// print out array
	// array_print(raw_data, char_count);
	
	// the encoded data is the original xor with the key
	// the below print statement shows that the encoded data xor with the orginal letter = the key 
	// printf("%d xor %d = %d, %d xor %d = %d\n", 12, 53, 12^53, 12^53, 53, (12^53)^53);
	
	// TODO: write function which goes through the data and finds the desired key for common words starting at multiple positions through the word
	//			this function will check for combinations which are all lower case and repeated, after this the key can be used on the remaining
	//			 data to see if it is decoded
	
	unsigned int temp_key_index = 0;
	unsigned int test_string_index;
	
	unsigned char test_string[6] = " and ";
	unsigned char key[4] = {0,0,0};
	unsigned char key_index = 0;
	
	unsigned char *temp_key = malloc(char_count * sizeof(char));
	
	int m,p;
	
	for(m = 0; m < 5; m++){	
		temp_key_index = 0;
		while(temp_key_index < char_count){
			test_string_index = (temp_key_index % 5) + m;
			if(test_string_index > 4){
				test_string_index -= 5;
			}
			temp_key[temp_key_index] = raw_data[temp_key_index] ^ test_string[test_string_index];
			temp_key_index ++;
		}
		
		// printf("Temp key:\n\n%s\n\n", temp_key);
		
		// go through the temp key and try to find a pattern
		temp_key_index = 3;
		
		while(temp_key_index < char_count){
			if(temp_key[temp_key_index - 3] == temp_key[temp_key_index]){
				temp_key_index++;
				if(temp_key_index < char_count){
					if(temp_key[temp_key_index - 3] == temp_key[temp_key_index]){
						for(p = 0; p<3;p++){
							key_index = (temp_key_index - 4) % 3 + p;
							if(key_index > 2){
								key_index -= 3;
							}
							key[key_index] = temp_key[temp_key_index - (4 - p)];
						}
						printf("Potential key for m = %d and key index = %d = %s\n", m, temp_key_index, key);
					}
				}
			}
			else{
				temp_key_index++;
			}
		}
	}	
	
	key[0] = 'g';
	key[1] = 'o';
	key[2] = 'd';
	
	unsigned char *decoded_message = malloc(char_count * sizeof(char));
	
	unsigned long ascii_count = 0;
	
	printf("\nDecoding using key \"%s\"...\n\n", key);
	for(m = 0; m < char_count; m++){
		decoded_message[m] = raw_data[m] ^ key[m%3];
		ascii_count += decoded_message[m];
	}
	printf("%s\n\nSum of ascii values = %d\n\n", decoded_message, ascii_count);
	
	return 0;
}
