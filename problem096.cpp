/* Project Euler problem 96
 * - solve 50 sudokus and sum top left 3 digit numbers
 */
 
#include <stdio.h>
#include <ctype.h>
#include "../Sudoku_Solver/sudoku.h"
#include "../Sudoku_Solver/sudoku_tande.h"
#include "../Sudoku_Solver/sudoku_examples.h"

#define SUDOKU_TO_SOLVE metro_sudoku_easy
unsigned char sudoku[82];
unsigned char data_buffer[90];
unsigned char index;
unsigned char sudoku_count = 1;
unsigned long sum = 0;


int main() {
	FILE *data_file = fopen("sudoku.txt", "r");
	unsigned char n, m;
	
	while(sudoku_count <= 50){
		// see if its a letter, if so loop until newline
		fread(&n, 1, 1, data_file);
		if(isalpha(n)){
			while(n != '\n'){
				fread(&n, 1, 1, data_file);
			}
		}
		// get sudoku data
		fread(data_buffer, 1, 90, data_file);
		index = 0;
		for(m = 0; m<90; m++){
			if(data_buffer[m] != '\n'){
				sudoku[index] = data_buffer[m] - 48;
				index++;
			}
		}
		// get the last newline out of the way
		fread(&n, 1, 1, data_file);
		// solve sudoku
		sudoku_solve_tande(sudoku, sudoku);
		
		sum += ((sudoku[0] * 100) + (sudoku[1] * 10) + (sudoku[2]));
		printf(" Sudoku number %2d solved, Sum = %d\n", sudoku_count, sum);
		sudoku_count++;
	}
		
		
	// wait till key press (for windows)
	// getchar();

	return 0;
}
