CC=gcc
CFLAGS= -lgmp

all:
	$(CC) problem001.c -o problem001 $(CFLAGS)
	$(CC) problem002.c -o problem002 $(CFLAGS)
	$(CC) problem003.c -o problem003 $(CFLAGS)
	$(CC) problem003_v2.c -o problem003_v2 $(CFLAGS)
	$(CC) problem004.c -o problem004 $(CFLAGS)
	$(CC) problem005.c -o problem005 $(CFLAGS)
	$(CC) problem006.c -o problem006 $(CFLAGS)
	$(CC) problem007.c -o problem007 $(CFLAGS)
	$(CC) problem008.c -o problem008 $(CFLAGS)
	$(CC) problem009.c -o problem009 $(CFLAGS)
	$(CC) problem055.c -o problem055 $(CFLAGS)
	$(CC) problem055.c -o problem059 $(CFLAGS)

clean:
	rm -f problem001
	rm -f problem002
	rm -f problem003
	rm -f problem003_v2
	rm -f problem004
	rm -f problem005
	rm -f problem006
	rm -f problem007
	rm -f problem008
	rm -f problem009
	rm -f problem055
	rm -f problem059
