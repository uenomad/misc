#include "nqj_c.h"

int MPI_Allgather (M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, MPI_Comm comm) { return nqjc_Allgather(sb, sc, st, rb, rc, rt, comm); }
int MPI_Allgatherv(M3C void *sb, int sc, MD st, void *rb, M3C int *rcs, M3C int *displs, MD rt, MPI_Comm comm) { return nqjc_Allgatherv(sb, sc, st, rb, rcs, displs, rt, comm); }
int MPI_Allreduce (M3C void *sb, void *rb, int count, MD dt, MPI_Op op, MPI_Comm comm) { return nqjc_Allreduce(sb, rb, count, dt, op, comm); }
int MPI_Alltoall  (M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, MPI_Comm comm) { return nqjc_Alltoall(sb, sc, st, rb, rc, rt, comm); }
int MPI_Alltoallv (M3C void *sb, M3C int *scs, M3C int *sdispls, MD st, void *rb, M3C int *rcs, M3C int *rdispls, MD rt, MPI_Comm comm) { return nqjc_Alltoallv(sb, scs, sdispls, st, rb, rcs, rdispls, rt, comm); }
int MPI_Barrier   (MPI_Comm comm) { return nqjc_Barrier(comm); }
int MPI_Bcast     (void *buffer, int count, MD dt, int root, MPI_Comm comm) { return nqjc_Bcast(buffer, count, dt, root, comm); }
int MPI_Bsend     (M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm) { return nqjc_Bsend(buf, count, dt, dest, tag, comm); }
int MPI_Bsend_init(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *rq) { return nqjc_Bsend_init(buf, count, dt, dest, tag, comm, rq); }
int MPI_Cancel    (MR *rq) { return nqjc_Cancel(rq); }
int MPI_Cart_create(MPI_Comm comm_old, int ndims, M3C int dims[], M3C int periods[], int reorder, MPI_Comm *comm_cart) { return nqjc_Cart_create(comm_old, ndims, dims, periods, reorder, comm_cart); }
int MPI_Cart_sub  (MPI_Comm comm, M3C int remain_dims[], MPI_Comm *newcomm) { return nqjc_Cart_sub(comm, remain_dims, newcomm); }
int MPI_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm) { return nqjc_Comm_create(comm, group, newcomm); }
int MPI_Comm_dup  (MPI_Comm comm, MPI_Comm *newcomm) { return nqjc_Comm_dup(comm, newcomm); }
int MPI_Comm_free (MPI_Comm *comm) { return nqjc_Comm_free(comm); }
int MPI_Comm_rank (MPI_Comm comm, int *rank) { return nqjc_Comm_rank(comm, rank); }
int MPI_Comm_size (MPI_Comm comm, int *size) { return nqjc_Comm_size(comm, size); }
int MPI_Comm_spawn(M3C char *command, char *argv[], int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm, int ae[]) { return nqjc_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, ae); }
int MPI_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[], M3C int array_of_maxprocs[], M3C MPI_Info array_of_info[], int root, MPI_Comm comm, MPI_Comm *intercomm, int ae[]) { return nqjc_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, ae); }
int MPI_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm) { return nqjc_Comm_split(comm, color, key, newcomm); }
int MF_close      (MF *fh) { return nqjc_File_close(fh); }
int MF_read       (MF fh, void *buf, int count, MD dt, MS *status) { return nqjc_File_read(fh, buf, count, dt, status); }
int MF_read_all   (MF fh, void *buf, int count, MD dt, MS *status) { return nqjc_File_read_all(fh, buf, count, dt, status); }
int MF_read_at    (MF fh, MPI_Offset offset, void *buf, int count, MD dt, MS *status) { return nqjc_File_read_at(fh, offset, buf, count, dt, status); }
int MF_read_at_all(MF fh, MPI_Offset offset, void *buf, int count, MD dt, MS *status) { return nqjc_File_read_at_all(fh, offset, buf, count, dt, status); }
int MF_write      (MF fh, M3C void *buf, int count, MD dt, MS *status) { return nqjc_File_write(fh, buf, count, dt, status); }
int MF_write_all  (MF fh, M3C void *buf, int count, MD dt, MS *status) { return nqjc_File_write_all(fh, buf, count, dt, status); }
int MF_write_at   (MF fh, MPI_Offset offset, M3C void *buf, int count, MD dt, MS *status) { return nqjc_File_write_at(fh, offset, buf, count, dt, status); }
int MF_write_at_all(MF fh, MPI_Offset offset, M3C void *buf, int count, MD dt, MS *status) { return nqjc_File_write_at_all(fh, offset, buf, count, dt, status); }
int MPI_Finalize  (void) { return nqjc_Finalize(); }
int MPI_Gather    (M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm) { return nqjc_Gather(sb, sc, st, rb, rc, rt, root, comm); }
int MPI_Gatherv   (M3C void *sb, int sc, MD st, void *rb, M3C int *rcs, M3C int *displs, MD rt, int root, MPI_Comm comm) { return nqjc_Gatherv(sb, sc, st, rb, rcs, displs, rt, root, comm); }
int MPI_Get       (void *origin_addr, int origin_count, MD origin_dt, int target_rank, MPI_Aint target_disp, int target_count, MD target_dt, MPI_Win win) { return nqjc_Get(origin_addr, origin_count, origin_dt, target_rank, target_disp, target_count, target_dt, win); }
int MPI_Ibsend    (M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *rq) { return nqjc_Ibsend(buf, count, dt, dest, tag, comm, rq); }
int MPI_Init      (int *argc, char ***argv) { return nqjc_Init(argc, argv); }
int MPI_Init_thread(int *argc, char ***argv, int required, int *provided) { return nqjc_Init_thread(argc, argv, required, provided); }
int MPI_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm peer_comm, int remote_leader, int tag, MPI_Comm *newintercomm) { return nqjc_Intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm); }
int MPI_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm) { return nqjc_Intercomm_merge(intercomm, high, newintracomm); }
int MPI_Iprobe    (int source, int tag, MPI_Comm comm, int *flag, MS *status) { return nqjc_Iprobe(source, tag, comm, flag, status); }
int MPI_Irecv     (void *buf, int count, MD dt, int source, int tag, MPI_Comm comm, MR *rq) { return nqjc_Irecv(buf, count, dt, source, tag, comm, rq); }
int MPI_Irsend    (M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *rq) { return nqjc_Irsend(buf, count, dt, dest, tag, comm, rq); }
int MPI_Isend     (M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *rq) { return nqjc_Isend(buf, count, dt, dest, tag, comm, rq); }
int MPI_Issend    (M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *rq) { return nqjc_Issend(buf, count, dt, dest, tag, comm, rq); }
int MPI_Probe     (int source, int tag, MPI_Comm comm, MS *status) { return nqjc_Probe(source, tag, comm, status); }
int MPI_Put       (M3C void *origin_addr, int origin_count, MD origin_dt, int target_rank, MPI_Aint target_disp, int target_count, MD target_dt, MPI_Win win) { return nqjc_Put(origin_addr, origin_count, origin_dt, target_rank, target_disp, target_count, target_dt, win); }
int MPI_Recv      (void *buf, int count, MD dt, int source, int tag, MPI_Comm comm, MS *status) { return nqjc_Recv(buf, count, dt, source, tag, comm, status); }
int MPI_Recv_init (void *buf, int count, MD dt, int source, int tag, MPI_Comm comm, MR *rq) { return nqjc_Recv_init(buf, count, dt, source, tag, comm, rq); }
int MPI_Reduce    (M3C void *sb, void *rb, int count, MD dt, MPI_Op op, int root, MPI_Comm comm) { return nqjc_Reduce(sb, rb, count, dt, op, root, comm); }
int MPI_Reduce_scatter(M3C void *sb, void *rb, M3C int *rcs, MD dt, MPI_Op op, MPI_Comm comm) { return nqjc_Reduce_scatter(sb, rb, rcs, dt, op, comm); }
int MR_free       (MR *rq) { return nqjc_Request_free(rq); }
int MR_get_status (MR rq, int *flag, MS *status) { return nqjc_Request_get_status(rq, flag, status); }
int MPI_Rsend     (M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm) { return nqjc_Rsend(buf, count, dt, dest, tag, comm); }
int MPI_Rsend_init(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *rq) { return nqjc_Rsend_init(buf, count, dt, dest, tag, comm, rq); }
int MPI_Scan      (M3C void *sb, void *rb, int count, MD dt, MPI_Op op, MPI_Comm comm) { return nqjc_Scan(sb, rb, count, dt, op, comm); }
int MPI_Scatter   (M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm) { return nqjc_Scatter(sb, sc, st, rb, rc, rt, root, comm); }
int MPI_Scatterv  (M3C void *sb, M3C int *scs, M3C int *displs, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm) { return nqjc_Scatterv(sb, scs, displs, st, rb, rc, rt, root, comm); }
int MPI_Send      (M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm) { return nqjc_Send(buf, count, dt, dest, tag, comm); }
int MPI_Send_init (M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *rq) { return nqjc_Send_init(buf, count, dt, dest, tag, comm, rq); }
int MPI_Sendrecv  (M3C void *sb, int sc, MD st, int dest, int sendtag, void *rb, int rc, MD rt, int source, int recvtag, MPI_Comm comm, MS *status) { return nqjc_Sendrecv(sb, sc, st, dest, sendtag, rb, rc, rt, source, recvtag, comm, status); }
int MPI_Sendrecv_replace(void *buf, int count, MD dt, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MS *status) { return nqjc_Sendrecv_replace(buf, count, dt, dest, sendtag, source, recvtag, comm, status); }
int MPI_Ssend     (M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm) { return nqjc_Ssend(buf, count, dt, dest, tag, comm); }
int MPI_Ssend_init(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *rq) { return nqjc_Ssend_init(buf, count, dt, dest, tag, comm, rq); }
int MPI_Start     (MR *rq) { return nqjc_Start(rq); }
int MPI_Startall  (int count, MR ar[]) { return nqjc_Startall(count, ar); }
int MPI_Test      (MR *rq, int *flag, MS *status) { return nqjc_Test(rq, flag, status); }
int MPI_Testall   (int count, MR ar[], int *flag, MS as[]) { return nqjc_Testall(count, ar, flag, as); }
int MPI_Testany   (int count, MR ar[], int *indx, int *flag, MS *status) { return nqjc_Testany(count, ar, indx, flag, status); }
int MPI_Testsome  (int incount, MR ar[], int *outcount, int ai[], MS as[]) { return nqjc_Testsome(incount, ar, outcount, ai, as); }
int MPI_Wait      (MR *rq, MS *status) { return nqjc_Wait(rq, status); }
int MPI_Waitall   (int count, MR *ar, MS *as) { return nqjc_Waitall(count, ar, as); }
int MPI_Waitany   (int count, MR *rqs, int *index, MS *status) { return nqjc_Waitany(count, rqs, index, status); }
int MPI_Waitsome  (int incount, MR *ar, int *outcount, int *ai, MS *as) { return nqjc_Waitsome(incount, ar, outcount, ai, as); }
int MPI_Win_complete(MPI_Win win) { return nqjc_Win_complete(win); }
int MPI_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win) { return nqjc_Win_create(base, size, disp_unit, info, comm, win); }
int MPI_Win_fence (int assert, MPI_Win win) { return nqjc_Win_fence(assert, win); }
int MPI_Win_free  (MPI_Win *win) { return nqjc_Win_free(win); }
int MPI_Win_post  (MPI_Group group, int assert, MPI_Win win) { return nqjc_Win_post(group, assert, win); }
int MPI_Win_start (MPI_Group group, int assert, MPI_Win win) { return nqjc_Win_start(group, assert, win); }
int MPI_Win_wait  (MPI_Win win) { return nqjc_Win_wait(win); }
int MPI_Iallgather(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, MPI_Comm comm, MR *rq) { return nqjc_Iallgather(sb, sc, st, rb, rc, rt, comm, rq); }
int MPI_Iallgatherv(M3C void *sb, int sc, MD st, void *rb, M3C int rcs[], M3C int displs[], MD rt, MPI_Comm comm, MR *rq) { return nqjc_Iallgatherv(sb, sc, st, rb, rcs, displs, rt, comm, rq); }
int MPI_Iallreduce(M3C void *sb, void *rb, int count, MD dt, MPI_Op op, MPI_Comm comm, MR *rq) { return nqjc_Iallreduce(sb, rb, count, dt, op, comm, rq); }
int MPI_Ialltoall (M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, MPI_Comm comm, MR *rq) { return nqjc_Ialltoall(sb, sc, st, rb, rc, rt, comm, rq); }
int MPI_Ialltoallv(M3C void *sb, M3C int scs[], M3C int sdispls[], MD st, void *rb, M3C int rcs[], M3C int rdispls[], MD rt, MPI_Comm comm, MR *rq) { return nqjc_Ialltoallv(sb, scs, sdispls, st, rb, rcs, rdispls, rt, comm, rq); }
int MPI_Ibarrier  (MPI_Comm comm, MR *rq) { return nqjc_Ibarrier(comm, rq); }
int MPI_Ibcast    (void *buffer, int count, MD dt, int root, MPI_Comm comm, MR *rq) { return nqjc_Ibcast(buffer, count, dt, root, comm, rq); }
int MPI_Igather   (M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm, MR *rq) { return nqjc_Igather(sb, sc, st, rb, rc, rt, root, comm, rq); }
int MPI_Igatherv  (M3C void *sb, int sc, MD st, void *rb, M3C int rcs[], M3C int displs[], MD rt, int root, MPI_Comm comm, MR *rq) { return nqjc_Igatherv(sb, sc, st, rb, rcs, displs, rt, root, comm, rq); }
int MPI_Ireduce   (M3C void *sb, void *rb, int count, MD dt, MPI_Op op, int root, MPI_Comm comm, MR *rq) { return nqjc_Ireduce(sb, rb, count, dt, op, root, comm, rq); }
int MPI_Ireduce_scatter(M3C void *sb, void *rb, M3C int rcs[], MD dt, MPI_Op op, MPI_Comm comm, MR *rq) { return nqjc_Ireduce_scatter(sb, rb, rcs, dt, op, comm, rq); }
int MPI_Iscan     (M3C void *sb, void *rb, int count, MD dt, MPI_Op op, MPI_Comm comm, MR *rq) { return nqjc_Iscan(sb, rb, count, dt, op, comm, rq); }
int MPI_Iscatter  (M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm, MR *rq) { return nqjc_Iscatter(sb, sc, st, rb, rc, rt, root, comm, rq); }
int MPI_Iscatterv (M3C void *sb, M3C int scs[], M3C int displs[], MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm, MR *rq) { return nqjc_Iscatterv(sb, scs, displs, st, rb, rc, rt, root, comm, rq); }