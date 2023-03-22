CC          = gcc
CC_FLAGS    = -Wall
MPICC       = /hpc/base/ctt/packages/openmpi/openmpi-4.1.2_EDR_gnu/bin/mpicc
MPICC_FLAGS =

# Meanings:
# nqj: mpi +1 letter
# sfbe: read +1 letter

all: libnqj.so nqj_test libsfbe.so

libnqj.so:
	$(MPICC) $(MPICC_FLAGS) -fPIC -shared -o $@ nqj.c nqj_c.c nqj_mpi_c.c

nqj_test: nqj_test.c
	$(MPICC) $(MPICC_FLAGS) -o $@ $<

libsfbe.so: sfbe.c
	$(CC) $(CC_FLAGS) -fPIC -shared -o $@ $^ -ldl

clean:
	rm -rf libnqj.so nqj_test libsfbe.so
