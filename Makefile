CC=gcc
CFLAGS= -lgmp -Wall -lm

TARGETS = problem001 problem002 problem003 problem003_v2 problem004 problem005 problem006 problem007 problem008 problem009 problem010 problem055 problem059 \
problem064

all: $(TARGETS)

$(TARGETS): %: %.c
	$(CC) -o $@ $< $(CFLAGS)
	
clean:
	rm -f $(TARGETS)
