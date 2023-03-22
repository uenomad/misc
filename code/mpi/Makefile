MPICC       = /hpc/base/ctt/packages/openmpi/openmpi-4.1.2_EDR_gnu/bin/mpicc
MPICC_FLAGS =

all: libnqj.so test

libnqj.so:
	$(MPICC) $(MPICC_FLAGS) -fPIC -shared -o $@ nqj.c nqj_c.c syms_c.c

test: test.c
	$(MPICC) $(MPICC_FLAGS) -o $@ test.c

clean:
	rm -rf libnqj.so test
