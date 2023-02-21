CC     = gcc
CFLAGS = -I.

########

all: avx_test sve_test symbol_search

avx_test:
	$(CC) $(CFLAGS) -DRYZEN=1 -mavx2 -o test_ryzen avx_test.c -lpthread
	$(CC) $(CFLAGS) -DSKYLAKE=1 -march=skylake-avx512 -o test_skylake avx_test.c -lpthread

sve_test:
	$(CC) $(CFLAGS) -march=armv8.2-a+sve -o test_arm82a sve_test.c

symbol_search:
	$(CC) $(CFLAGS) -DMAIN -o test_symbol strtable.c symbol_search.c -ldl

########

clean:
	rm -rf test_ryzen
	rm -rf test_skylake
	rm -rf test_symbol