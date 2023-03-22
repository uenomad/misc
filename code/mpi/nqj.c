#include "nqj.h"
#include <stdio.h>

void nqj_init()
{
    fprintf(stderr, "nqj_init()\n");
}

void nqj_finalize()
{
    fprintf(stderr, "nqj_finalize()\n");
}

void nqj_enter(mpi_call_e call, p2i buf, p2i dest)
{

}

void nqj_leave(mpi_call_e call)
{

}
