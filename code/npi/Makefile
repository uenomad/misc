CC          = gcc
CC_FLAGS    = -Wall
MPICC       = mpicc
MPICC_FLAGS =

all: libnpi.so test_mpi

libnpi.so: npi.c npi_c.c mpi_c.c
	$(MPICC) $(MPICC_FLAGS) -fPIC -shared -o $@ $^

test_mpi: test_mpi.c
	$(MPICC) $(MPICC_FLAGS) -o $@ $^

clean:
	rm -rf *.o *.a *.so test_mpi
