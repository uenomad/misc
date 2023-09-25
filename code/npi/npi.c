#include "npi.h"
#include <stdio.h>

void npi_init()
{
    fprintf(stderr, "npi_init()\n");
}

void npi_finalize()
{
    fprintf(stderr, "npi_finalize()\n");
}

void npi_enter(mpi_call_e call, p2i buf, p2i dest)
{
    fprintf(stderr, "npi_enter()\n");
}

void npi_leave(mpi_call_e call)
{
    fprintf(stderr, "npi_leave()\n");

}
