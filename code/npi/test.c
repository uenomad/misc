#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

#if 1
#endif

int main(int argc, char *argv[])
{
    char host[128];
    int i = 0;
    int rank;
    int size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    gethostname(host, sizeof(host));
    fprintf(stderr, "%s: mpi %d/%d\n", host, rank, size);
    
    while(i < 3) {
        sleep(1);
        int res = MPI_Barrier(MPI_COMM_WORLD) == MPI_SUCCESS;
        fprintf(stderr, "MPI_barrier(%d): %d\n", rank, res);
        ++i;
    }
    MPI_Finalize();
    return 0;
}
