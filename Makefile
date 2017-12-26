CC=gcc
CFLAGS= -lgmp -Wall -lm
SS=../Sudoku_Solver/

TARGETS = problem001 problem002 problem003 problem003_v2 problem004 problem005 problem006 problem007 problem008 problem009 problem010 problem055 problem059 \
problem064 problem011 problem112

all: $(TARGETS) problem096

$(TARGETS): %: %.c
	$(CC) -o $@ $< $(CFLAGS)

problem096: problem096.cpp $(SS)sudoku.cpp $(SS)sudoku_tande.cpp $(SS)sudoku.h $(SS)sudoku_tande.h
	$(CC) -o $@ $(SS)sudoku.cpp $(SS)sudoku_tande.cpp problem096.cpp -I$(SS)
	
clean:
	rm -f $(TARGETS)
	rm -f problem096
