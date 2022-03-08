CC     = gcc
CFLAGS = -I.

########

all: symbol_search simd_test

simd_test:
	$(CC) $(CFLAGS) -DRYZEN=1 -mavx2 -o test_ryzen simd_test.c -lpthread
	$(CC) $(CFLAGS) -DSKYLAKE=1 -march=skylake-avx512 -o test_skylake simd_test.c -lpthread

symbol_search:
	$(CC) $(CFLAGS) -DMAIN -o test_symbol strtable.c symbol_search.c -ldl

########

clean:
	rm -rf test_ryzen
	rm -rf test_skylake
	rm -rf test_symbol