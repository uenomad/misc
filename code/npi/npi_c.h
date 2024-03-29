#ifndef MISC_NPIC_H
#define MISC_NPIC_H

#include "npi.h"

#define MD   MPI_Datatype
#define MR   MPI_Request
#define MF   MPI_File
#define MS   MPI_Status

// Short names
// dt: datatype
// st: status
// sb: sendbuf
// sc: sendcount (s)
// st: sendtype
// sg: sendtag
// rb: recvbuf
// rc: recvcount (s)
// rt: recvtype
// ie: ierror
// ar: array_of_requests
// ai: array_of_indices
// ae: array_of_errcodes
// as: array_of_statuses
// ac: array_of_commands
// aa: array_of_argv
// am: array_of_maxprocs
// rq: request

int npic_Allgather(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, MPI_Comm comm);
int npic_Allgatherv(M3C void *sb, int sc, MD st, void *rb, M3C int *rcs, M3C int *displs, MD rt, MPI_Comm comm);
int npic_Allreduce(M3C void *sb, void *rb, int count, MD dt, MPI_Op op, MPI_Comm comm);
int npic_Alltoall(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, MPI_Comm comm);
int npic_Alltoallv(M3C void *sb, M3C int *scs, M3C int *sdispls, MD st, void *rb, M3C int *rcs, M3C int *rdispls, MD rt, MPI_Comm comm);
int npic_Barrier(MPI_Comm comm);
int npic_Bcast(void *buffer, int count, MD dt, int root, MPI_Comm comm);
int npic_Bsend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm);
int npic_Bsend_init(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request);
int npic_Cancel(MR *request);
int npic_Cart_create(MPI_Comm comm_old, int ndims, M3C int dims[], M3C int periods[], int reorder, MPI_Comm *comm_cart);
int npic_Cart_sub(MPI_Comm comm, M3C int remain_dims[], MPI_Comm *newcomm);
int npic_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm);
int npic_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm);
int npic_Comm_free(MPI_Comm *comm);
int npic_Comm_rank(MPI_Comm comm, int *rank);
int npic_Comm_size(MPI_Comm comm, int *size);
int npic_Comm_spawn(M3C char *command, char *argv[], int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[]);
int npic_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[], M3C int array_of_maxprocs[], M3C MPI_Info array_of_info[], int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[]);
int npic_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm);
int npic_File_close(MF *fh);
int npic_File_read(MF fh, void *buf, int count, MD dt, MS *status);
int npic_File_read_all(MF fh, void *buf, int count, MD dt, MS *status);
int npic_File_read_at(MF fh, MPI_Offset offset, void *buf, int count, MD dt, MS *status);
int npic_File_read_at_all(MF fh, MPI_Offset offset, void *buf, int count, MD dt, MS *status);
int npic_File_write(MF fh, M3C void *buf, int count, MD dt, MS *status);
int npic_File_write_all(MF fh, M3C void *buf, int count, MD dt, MS *status);
int npic_File_write_at(MF fh, MPI_Offset offset, M3C void *buf, int count, MD dt, MS *status);
int npic_File_write_at_all(MF fh, MPI_Offset offset, M3C void *buf, int count, MD dt, MS *status);
int npic_Finalize(void);
int npic_Gather(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm);
int npic_Gatherv(M3C void *sb, int sc, MD st, void *rb, M3C int *rcs, M3C int *displs, MD rt, int root, MPI_Comm comm);
int npic_Get(void *origin_addr, int origin_count, MD origin_dt, int target_rank, MPI_Aint target_disp, int target_count, MD target_dt, MPI_Win win);
int npic_Ibsend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request);
int npic_Init(int *argc, char ***argv);
int npic_Init_thread(int *argc, char ***argv, int required, int *provided);
int npic_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm peer_comm, int remote_leader, int tag, MPI_Comm *newintercomm);
int npic_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm);
int npic_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MS *status);
int npic_Irecv(void *buf, int count, MD dt, int source, int tag, MPI_Comm comm, MR *request);
int npic_Irsend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request);
int npic_Isend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request);
int npic_Issend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request);
int npic_Probe(int source, int tag, MPI_Comm comm, MS *status);
int npic_Put(M3C void *origin_addr, int origin_count, MD origin_dt, int target_rank, MPI_Aint target_disp, int target_count, MD target_dt, MPI_Win win);
int npic_Recv(void *buf, int count, MD dt, int source, int tag, MPI_Comm comm, MS *status);
int npic_Recv_init(void *buf, int count, MD dt, int source, int tag, MPI_Comm comm, MR *request);
int npic_Reduce(M3C void *sb, void *rb, int count, MD dt, MPI_Op op, int root, MPI_Comm comm);
int npic_Reduce_scatter(M3C void *sb, void *rb, M3C int *rcs, MD dt, MPI_Op op, MPI_Comm comm);
int npic_Request_free(MR *request);
int npic_Request_get_status(MR request, int *flag, MS *status);
int npic_Rsend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm);
int npic_Rsend_init(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request);
int npic_Scan(M3C void *sb, void *rb, int count, MD dt, MPI_Op op, MPI_Comm comm);
int npic_Scatter(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm);
int npic_Scatterv(M3C void *sb, M3C int *scs, M3C int *displs, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm);
int npic_Send(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm);
int npic_Send_init(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request);
int npic_Sendrecv(M3C void *sb, int sc, MD st, int dest, int sendtag, void *rb, int rc, MD rt, int source, int recvtag, MPI_Comm comm, MS *status);
int npic_Sendrecv_replace(void *buf, int count, MD dt, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MS *status);
int npic_Ssend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm);
int npic_Ssend_init(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request);
int npic_Start(MR *request);
int npic_Startall(int count, MR array_of_requests[]);
int npic_Test(MR *request, int *flag, MS *status);
int npic_Testall(int count, MR array_of_requests[], int *flag, MS array_of_statuses[]);
int npic_Testany(int count, MR array_of_requests[], int *indx, int *flag, MS *status);
int npic_Testsome(int incount, MR array_of_requests[], int *outcount, int array_of_indices[], MS array_of_statuses[]);
int npic_Wait(MR *request, MS *status);
int npic_Waitall(int count, MR *array_of_requests, MS *array_of_statuses);
int npic_Waitany(int count, MR *requests, int *index, MS *status);
int npic_Waitsome(int incount, MR *array_of_requests, int *outcount, int *array_of_indices, MS *array_of_statuses);
int npic_Win_complete(MPI_Win win);
int npic_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win);
int npic_Win_fence(int assert, MPI_Win win);
int npic_Win_free(MPI_Win *win);
int npic_Win_post(MPI_Group group, int assert, MPI_Win win);
int npic_Win_start(MPI_Group group, int assert, MPI_Win win);
int npic_Win_wait(MPI_Win win);
int npic_Iallgather(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, MPI_Comm comm, MR *request);
int npic_Iallgatherv(M3C void *sb, int sc, MD st, void *rb, M3C int rcs[], M3C int displs[], MD rt, MPI_Comm comm, MR *request);
int npic_Iallreduce(M3C void *sb, void *rb, int count, MD dt, MPI_Op op, MPI_Comm comm, MR *request);
int npic_Ialltoall(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, MPI_Comm comm, MR *request);
int npic_Ialltoallv(M3C void *sb, M3C int scs[], M3C int sdispls[], MD st, void *rb, M3C int rcs[], M3C int rdispls[], MD rt, MPI_Comm comm, MR *request);
int npic_Ibarrier(MPI_Comm comm, MR *request);
int npic_Ibcast(void *buffer, int count, MD dt, int root, MPI_Comm comm, MR *request);
int npic_Igather(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm, MR *request);
int npic_Igatherv(M3C void *sb, int sc, MD st, void *rb, M3C int rcs[], M3C int displs[], MD rt, int root, MPI_Comm comm, MR *request);
int npic_Ireduce(M3C void *sb, void *rb, int count, MD dt, MPI_Op op, int root, MPI_Comm comm, MR *request);
int npic_Ireduce_scatter(M3C void *sb, void *rb, M3C int rcs[], MD dt, MPI_Op op, MPI_Comm comm, MR *request);
int npic_Iscan(M3C void *sb, void *rb, int count, MD dt, MPI_Op op, MPI_Comm comm, MR *request);
int npic_Iscatter(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm, MR *request);
int npic_Iscatterv(M3C void *sb, M3C int scs[], M3C int displs[], MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm, MR *request);

#endif //MISC_NPIC_H