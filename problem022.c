#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

int main(){
	FILE *input_file = fopen("names.txt", "r");
	uint16_t n;
	char c;
	uint16_t name_count = 0;
	uint16_t max_len = 0;
	uint16_t len = 0;
	
	// figure out how many names and longest name length
	while(!feof(input_file)){
		c = fgetc(input_file);
		if((c=='"') || (c==',')){
			if(len){
				name_count++;
				if(len > max_len){
					max_len = len;
				}
			}
			len = 0;
		}
		else{
			len++;
		}
	}
	
	fclose(input_file);
	
	printf("\nNumber of names = %d, maximum name length = %d\n\n", name_count, max_len);
	
	// create array for holding the names
	char **names = (char **)malloc((name_count + 1) * sizeof(char *)); 	
	names[0] = (char *)malloc((name_count + 1) * (max_len + 1) * sizeof(char));
	for(n = 0; n < name_count; n++){
		names[n] = (*names + (max_len + 1)*n);
		strcpy(names[n], "");
	}
	
	// load names into array
	char temp_name[20] = "";
	uint16_t name_index = 0;
	input_file = fopen("names.txt", "r");
	while(!feof(input_file)){
		c = fgetc(input_file);
		if((c==',')){
			strcpy(names[name_index], temp_name);
			strcpy(temp_name, "");
			name_index++;
		}		
		else if(c>64){
			strncat(temp_name, &c,1);
		}
	}
	strcpy(names[name_index], temp_name);
	
	// sort names
	// sort based on first letter
	char sorting_letter = 'A';
	uint16_t sorting_index = 0;
	while(sorting_letter <= 'Z'){
		for(n = 0; n<name_count; n++){
			if(names[n][0] == sorting_letter){
				strcpy(temp_name, names[sorting_index]);
				strcpy(names[sorting_index], names[n]);
				strcpy(names[n], temp_name);
				sorting_index++;
			}
		}
		sorting_letter++;
	}
	
	//uint16_t sorted = 0;
	uint16_t first_index = 0;
	uint16_t last_index = 0;
	uint8_t pos;
	uint16_t index;
	char low_name[20];		
	uint16_t low_index;
	sorting_letter = 'A';
	while(sorting_letter <= 'Z'){
		// find out where the names starting with the current letter start and end
		first_index = 0;
		last_index = 0;
		while(names[first_index][0] != sorting_letter){
			first_index++;
		}
		last_index = first_index;
		while(names[last_index][0] == sorting_letter){
			last_index++;
			if(last_index == name_count){
				break;
			}
		}
		last_index--;
		
		//printf("Letter = %c, First index = %d, last index = %d\n\n", sorting_letter,first_index, last_index);
		
		// sort the names starting with the current letter

		
		while(first_index != last_index){
			pos = 1;
			index = 1;
			low_index = first_index;
			strcpy(low_name, names[first_index]);
			// search through all names beginning with the sorting letter to find the smallest
			while(first_index + index <= last_index){
				// if the current name is smaller than the current low_name then update the low_name and move to the next name
				if(names[first_index + index][pos] < low_name[pos]){
					low_index = first_index + index;
					strcpy(low_name, names[low_index]);
					pos = 1;
					index++;
				}
				// if names are equal then look at the next letter
				else if(names[first_index + index][pos] == low_name[pos]){
					pos++;
				}
				// else the name is bigger and not important move to next name
				else{
					pos = 1;
					index++;
				}
			}
			// move the lowest name to the top of the pile, increment first_name and repeat until sorted
			//printf("Lowest name = %s at postion %d\n", low_name, low_index);
			strcpy(names[low_index], names[first_index]);
			strcpy(names[first_index], low_name);
			first_index++;
		}
		sorting_letter++;
	}
	uint16_t name_score;
	uint64_t name_sum = 0;
	for(n = 0; n< name_count; n++){
		name_score=0;
		pos = 0;
		while((names[n][pos] > 64) && (names[n][pos] < 91) ){
			name_score+=names[n][pos] - 64;
			pos++;
		}
		
		printf("\r%11s = %d, \t ", names[n], name_score);
		name_score *= n+1;
		name_sum += name_score;
		printf("pos = %d,\t score = %d,\t sum = %lu", n+1, name_score, name_sum);
	}
		
	printf("\n\n");
	
	return 0;
}
