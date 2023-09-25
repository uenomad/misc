#include "npi_fortran.h"

#define M3C  MPI3_CONST
#define MI   MPI_Fint
#define MF   MPI_File
#define MS   MPI_Status

void mpi_allgather   (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *comm, MI *ie) { npif_allgather(sb, sc, st, rb, rc, rt, comm, ie); }
void mpi_allgather_  (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *comm, MI *ie) __attribute__((alias("mpi_allgather")));
void mpi_allgather__ (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *comm, MI *ie) __attribute__((alias("mpi_allgather")));
void mpi_allgatherv  (M3C void *sb, MI *sc, MI *st, void *rb, M3C MI *rcs, M3C MI *displs, MI *rt, MI *comm, MI *ie) { npif_allgatherv(sb, sc, st, rb, rcs, displs, rt, comm, ie); }
void mpi_allgatherv_ (M3C void *sb, MI *sc, MI *st, void *rb, M3C MI *rcs, M3C MI *displs, MI *rt, MI *comm, MI *ie) __attribute__((alias("mpi_allgatherv")));
void mpi_allgatherv__(M3C void *sb, MI *sc, MI *st, void *rb, M3C MI *rcs, M3C MI *displs, MI *rt, MI *comm, MI *ie) __attribute__((alias("mpi_allgatherv")));
void mpi_allreduce   (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *comm, MI *ie) { npif_allreduce(sb, rb, count, dt, op, comm, ie); }
void mpi_allreduce_  (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *comm, MI *ie) __attribute__((alias("mpi_allreduce")));
void mpi_allreduce__ (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *comm, MI *ie) __attribute__((alias("mpi_allreduce")));
void mpi_alltoall    (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *comm, MI *ie) { npif_alltoall(sb, sc, st, rb, rc, rt, comm, ie); }
void mpi_alltoall_   (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *comm, MI *ie) __attribute__((alias("mpi_alltoall")));
void mpi_alltoall__  (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *comm, MI *ie) __attribute__((alias("mpi_alltoall")));
void mpi_alltoallv   (M3C void *sb, M3C MI *scs, M3C MI *sdispls, MI *st, void *rb, M3C MI *rcs, M3C MI *rdispls, MI *rt, MI *comm, MI *ie) { npif_alltoallv(sb, scs, sdispls, st, rb, rcs, rdispls, rt, comm, ie); }
void mpi_alltoallv_  (M3C void *sb, M3C MI *scs, M3C MI *sdispls, MI *st, void *rb, M3C MI *rcs, M3C MI *rdispls, MI *rt, MI *comm, MI *ie) __attribute__((alias("mpi_alltoallv")));
void mpi_alltoallv__ (M3C void *sb, M3C MI *scs, M3C MI *sdispls, MI *st, void *rb, M3C MI *rcs, M3C MI *rdispls, MI *rt, MI *comm, MI *ie) __attribute__((alias("mpi_alltoallv")));
void mpi_barrier     (MI *comm, MI *ie) { npif_barrier(comm, ie); }
void mpi_barrier_    (MI *comm, MI *ie) __attribute__((alias("mpi_barrier")));
void mpi_barrier__   (MI *comm, MI *ie) __attribute__((alias("mpi_barrier")));
void mpi_bcast       (void *buffer, MI *count, MI *dt, MI *root, MI *comm, MI *ie) { npif_bcast(buffer, count, dt, root, comm, ie); }
void mpi_bcast_      (void *buffer, MI *count, MI *dt, MI *root, MI *comm, MI *ie) __attribute__((alias("mpi_bcast")));
void mpi_bcast__     (void *buffer, MI *count, MI *dt, MI *root, MI *comm, MI *ie) __attribute__((alias("mpi_bcast")));
void mpi_bsend       (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *ie) { npif_bsend(buf, count, dt, dest, tag, comm, ie); }
void mpi_bsend_      (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *ie) __attribute__((alias("mpi_bsend")));
void mpi_bsend__     (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *ie) __attribute__((alias("mpi_bsend")));
void mpi_bsend_init  (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) { npif_bsend_init(buf, count, dt, dest, tag, comm, rq, ie); }
void mpi_bsend_init_ (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_bsend_init")));
void mpi_bsend_init__(M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_bsend_init")));
void mpi_cancel      (MI *rq, MI *ie) { npif_cancel(rq, ie); }
void mpi_cancel_     (MI *rq, MI *ie) __attribute__((alias("mpi_cancel")));
void mpi_cancel__    (MI *rq, MI *ie) __attribute__((alias("mpi_cancel")));
void mpi_cart_create  (MI *comm_old, MI *ndims, M3C MI *dims, M3C MI *periods, MI *reorder, MI *comm_cart, MI *ie) { npif_cart_create(comm_old, ndims, dims, periods, reorder, comm_cart, ie); }
void mpi_cart_create_ (MI *comm_old, MI *ndims, M3C MI *dims, M3C MI *periods, MI *reorder, MI *comm_cart, MI *ie) __attribute__((alias("mpi_cart_create")));
void mpi_cart_create__(MI *comm_old, MI *ndims, M3C MI *dims, M3C MI *periods, MI *reorder, MI *comm_cart, MI *ie) __attribute__((alias("mpi_cart_create")));
void mpi_cart_sub    (MI *comm, M3C MI *remain_dims, MI *comm_new, MI *ie) { npif_cart_sub(comm, remain_dims, comm_new, ie); }
void mpi_cart_sub_   (MI *comm, M3C MI *remain_dims, MI *comm_new, MI *ie) __attribute__((alias("mpi_cart_sub")));
void mpi_cart_sub__  (MI *comm, M3C MI *remain_dims, MI *comm_new, MI *ie) __attribute__((alias("mpi_cart_sub")));
void mpi_comm_create  (MI *comm, MI *group, MI *newcomm, MI *ie) { npif_comm_create(comm, group, newcomm, ie); }
void mpi_comm_create_ (MI *comm, MI *group, MI *newcomm, MI *ie) __attribute__((alias("mpi_comm_create")));
void mpi_comm_create__(MI *comm, MI *group, MI *newcomm, MI *ie) __attribute__((alias("mpi_comm_create")));
void mpi_comm_dup    (MI *comm, MI *newcomm, MI *ie) { npif_comm_dup(comm, newcomm, ie); }
void mpi_comm_dup_   (MI *comm, MI *newcomm, MI *ie) __attribute__((alias("mpi_comm_dup")));
void mpi_comm_dup__  (MI *comm, MI *newcomm, MI *ie) __attribute__((alias("mpi_comm_dup")));
void mpi_comm_free   (MI *comm, MI *ie) { npif_comm_free(comm, ie); }
void mpi_comm_free_  (MI *comm, MI *ie) __attribute__((alias("mpi_comm_free")));
void mpi_comm_free__ (MI *comm, MI *ie) __attribute__((alias("mpi_comm_free")));
void mpi_comm_rank   (MI *comm, MI *rank, MI *ie) { npif_comm_rank(comm, rank, ie); }
void mpi_comm_rank_  (MI *comm, MI *rank, MI *ie) __attribute__((alias("mpi_comm_rank")));
void mpi_comm_rank__ (MI *comm, MI *rank, MI *ie) __attribute__((alias("mpi_comm_rank")));
void mpi_comm_size   (MI *comm, MI *size, MI *ie) { npif_comm_size(comm, size, ie); }
void mpi_comm_size_  (MI *comm, MI *size, MI *ie) __attribute__((alias("mpi_comm_size")));
void mpi_comm_size__ (MI *comm, MI *size, MI *ie) __attribute__((alias("mpi_comm_size")));
void mpi_comm_spawn  (M3C char *command, char *argv, MI *maxprocs, MI *info, MI *root, MI *comm, MI *intercomm, MI *ae, MI *ie) { npif_comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, ae, ie); }
void mpi_comm_spawn_ (M3C char *command, char *argv, MI *maxprocs, MI *info, MI *root, MI *comm, MI *intercomm, MI *ae, MI *ie) __attribute__((alias("mpi_comm_spawn")));
void mpi_comm_spawn__(M3C char *command, char *argv, MI *maxprocs, MI *info, MI *root, MI *comm, MI *intercomm, MI *ae, MI *ie) __attribute__((alias("mpi_comm_spawn")));
void mpi_comm_spawn_multiple  (MI *count, char *ac, char *aa, M3C MI *am, M3C MI *array_of_info, MI *root, MI *comm, MI *intercomm, MI *ae, MI *ie) { npif_comm_spawn_multiple(count, ac, aa, am, array_of_info, root, comm, intercomm, ae, ie); }
void mpi_comm_spawn_multiple_ (MI *count, char *ac, char *aa, M3C MI *am, M3C MI *array_of_info, MI *root, MI *comm, MI *intercomm, MI *ae, MI *ie) __attribute__((alias("mpi_comm_spawn_multiple")));
void mpi_comm_spawn_multiple__(MI *count, char *ac, char *aa, M3C MI *am, M3C MI *array_of_info, MI *root, MI *comm, MI *intercomm, MI *ae, MI *ie) __attribute__((alias("mpi_comm_spawn_multiple")));
void mpi_comm_split  (MI *comm, MI *color, MI *key, MI *newcomm, MI *ie) { npif_comm_split(comm, color, key, newcomm, ie); }
void mpi_comm_split_ (MI *comm, MI *color, MI *key, MI *newcomm, MI *ie) __attribute__((alias("mpi_comm_split")));
void mpi_comm_split__(MI *comm, MI *color, MI *key, MI *newcomm, MI *ie) __attribute__((alias("mpi_comm_split")));
void mpi_file_close  (MF *fh, MI *ie) { npif_file_close(fh, ie); }
void mpi_file_close_ (MF *fh, MI *ie) __attribute__((alias("mpi_file_close")));
void mpi_file_close__(MF *fh, MI *ie) __attribute__((alias("mpi_file_close")));
void mpi_file_read   (MF *fh, void *buf, MI *count, MI *dt, MS *status, MI *ie) { npif_file_read(fh, buf, count, dt, status, ie); }
void mpi_file_read_  (MF *fh, void *buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_read")));
void mpi_file_read__ (MF *fh, void *buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_read")));
void mpi_file_read_all  (MF *fh, void *buf, MI *count, MI *dt, MS *status, MI *ie) { npif_file_read_all(fh, buf, count, dt, status, ie); }
void mpi_file_read_all_ (MF *fh, void *buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_read_all")));
void mpi_file_read_all__(MF *fh, void *buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_read_all")));
void mpi_file_read_at  (MF *fh, MPI_Offset *offset, void* buf, MI *count, MI *dt, MS *status, MI *ie) { npif_file_read_at(fh, offset, buf, count, dt, status, ie); }
void mpi_file_read_at_ (MF *fh, MPI_Offset *offset, void* buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_read_at")));
void mpi_file_read_at__(MF *fh, MPI_Offset *offset, void* buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_read_at")));
void mpi_file_read_at_all  (MF *fh, MPI_Offset *offset, void* buf, MI *count, MI *dt, MS *status, MI *ie) { npif_file_read_at_all(fh, offset, buf, count, dt, status, ie); }
void mpi_file_read_at_all_ (MF *fh, MPI_Offset *offset, void* buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_read_at_all")));
void mpi_file_read_at_all__(MF *fh, MPI_Offset *offset, void* buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_read_at_all")));
void mpi_file_write  (MF *fh, M3C void *buf, MI *count, MI *dt, MS *status, MI *ie) { npif_file_write(fh, buf, count, dt, status, ie); }
void mpi_file_write_ (MF *fh, M3C void *buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_write")));
void mpi_file_write__(MF *fh, M3C void *buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_write")));
void mpi_file_write_all  (MF *fh, M3C void *buf, MI *count, MI *dt, MS *status, MI *ie) { npif_file_write_all(fh, buf, count, dt, status, ie); }
void mpi_file_write_all_ (MF *fh, M3C void *buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_write_all")));
void mpi_file_write_all__(MF *fh, M3C void *buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_write_all")));
void mpi_file_write_at  (MF *fh, MPI_Offset *offset, M3C void *buf, MI *count, MI *dt, MS *status, MI *ie) { npif_file_write_at(fh, offset, buf, count, dt, status, ie); }
void mpi_file_write_at_ (MF *fh, MPI_Offset *offset, M3C void *buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_write_at")));
void mpi_file_write_at__(MF *fh, MPI_Offset *offset, M3C void *buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_write_at")));
void mpi_file_write_at_all  (MF *fh, MPI_Offset *offset, M3C void *buf, MI *count, MI *dt, MS *status, MI *ie) { npif_file_write_at_all(fh, offset, buf, count, dt, status, ie); }
void mpi_file_write_at_all_ (MF *fh, MPI_Offset *offset, M3C void *buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_write_at_all")));
void mpi_file_write_at_all__(MF *fh, MPI_Offset *offset, M3C void *buf, MI *count, MI *dt, MS *status, MI *ie) __attribute__((alias("mpi_file_write_at_all")));
void mpi_finalize    (MI *ie) { npif_finalize(ie); }
void mpi_finalize_   (MI *ie) __attribute__((alias("mpi_finalize")));
void mpi_finalize__  (MI *ie) __attribute__((alias("mpi_finalize")));
void mpi_gather      (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *ie) { npif_gather(sb, sc, st, rb, rc, rt, root, comm, ie); }
void mpi_gather_     (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *ie) __attribute__((alias("mpi_gather")));
void mpi_gather__    (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *ie) __attribute__((alias("mpi_gather")));
void mpi_gatherv     (M3C void *sb, MI *sc, MI *st, void *rb, M3C MI *rcs, M3C MI *displs, MI *rt, MI *root, MI *comm, MI *ie) { npif_gatherv(sb, sc, st, rb, rcs, displs, rt, root, comm, ie); }
void mpi_gatherv_    (M3C void *sb, MI *sc, MI *st, void *rb, M3C MI *rcs, M3C MI *displs, MI *rt, MI *root, MI *comm, MI *ie) __attribute__((alias("mpi_gatherv")));
void mpi_gatherv__   (M3C void *sb, MI *sc, MI *st, void *rb, M3C MI *rcs, M3C MI *displs, MI *rt, MI *root, MI *comm, MI *ie) __attribute__((alias("mpi_gatherv")));
void mpi_get         (MI *origin_addr, MI *origin_count, MI *origin_dt, MI *target_rank, MI *target_disp, MI *target_count, MI *target_dt, MI *win, MI *ie) { npif_get(origin_addr, origin_count, origin_dt, target_rank, target_disp, target_count, target_dt, win, ie); }
void mpi_get_        (MI *origin_addr, MI *origin_count, MI *origin_dt, MI *target_rank, MI *target_disp, MI *target_count, MI *target_dt, MI *win, MI *ie) __attribute__((alias("mpi_get")));
void mpi_get__       (MI *origin_addr, MI *origin_count, MI *origin_dt, MI *target_rank, MI *target_disp, MI *target_count, MI *target_dt, MI *win, MI *ie) __attribute__((alias("mpi_get")));
void mpi_ibsend      (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) { npif_ibsend(buf, count, dt, dest, tag, comm, rq, ie); }
void mpi_ibsend_     (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ibsend")));
void mpi_ibsend__    (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ibsend")));
void mpi_init        (MI *ie) { npif_init(ie); }
void mpi_init_       (MI *ie) __attribute__((alias("mpi_init")));
void mpi_init__      (MI *ie) __attribute__((alias("mpi_init")));
void mpi_init_thread  (MI *required, MI *provided, MI *ie) { npif_init_thread(required, provided, ie); }
void mpi_init_thread_ (MI *required, MI *provided, MI *ie) __attribute__((alias("mpi_init_thread")));
void mpi_init_thread__(MI *required, MI *provided, MI *ie) __attribute__((alias("mpi_init_thread")));
void mpi_intercomm_create  (MI *local_comm, MI *local_leader, MI *peer_comm, MI *remote_leader, MI *tag, MI *newintercomm, MI *ie) { npif_intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm, ie); }
void mpi_intercomm_create_ (MI *local_comm, MI *local_leader, MI *peer_comm, MI *remote_leader, MI *tag, MI *newintercomm, MI *ie) __attribute__((alias("mpi_intercomm_create")));
void mpi_intercomm_create__(MI *local_comm, MI *local_leader, MI *peer_comm, MI *remote_leader, MI *tag, MI *newintercomm, MI *ie) __attribute__((alias("mpi_intercomm_create")));
void mpi_intercomm_merge  (MI *intercomm, MI *high, MI *newintracomm, MI *ie) { npif_intercomm_merge(intercomm, high, newintracomm, ie); }
void mpi_intercomm_merge_ (MI *intercomm, MI *high, MI *newintracomm, MI *ie) __attribute__((alias("mpi_intercomm_merge")));
void mpi_intercomm_merge__(MI *intercomm, MI *high, MI *newintracomm, MI *ie) __attribute__((alias("mpi_intercomm_merge")));
void mpi_iprobe      (MI *source, MI *tag, MI *comm, MI *flag, MI *status, MI *ie) { npif_iprobe(source, tag, comm, flag, status, ie); }
void mpi_iprobe_     (MI *source, MI *tag, MI *comm, MI *flag, MI *status, MI *ie) __attribute__((alias("mpi_iprobe")));
void mpi_iprobe__    (MI *source, MI *tag, MI *comm, MI *flag, MI *status, MI *ie) __attribute__((alias("mpi_iprobe")));
void mpi_irecv       (void *buf, MI *count, MI *dt, MI *source, MI *tag, MI *comm, MI *rq, MI *ie) { npif_irecv(buf, count, dt, source, tag, comm, rq, ie); }
void mpi_irecv_      (void *buf, MI *count, MI *dt, MI *source, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_irecv")));
void mpi_irecv__     (void *buf, MI *count, MI *dt, MI *source, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_irecv")));
void mpi_irsend      (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) { npif_irsend(buf, count, dt, dest, tag, comm, rq, ie); }
void mpi_irsend_     (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_irsend")));
void mpi_irsend__    (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_irsend")));
void mpi_isend       (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) { npif_isend(buf, count, dt, dest, tag, comm, rq, ie); }
void mpi_isend_      (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_isend")));
void mpi_isend__     (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_isend")));
void mpi_issend      (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) { npif_issend(buf, count, dt, dest, tag, comm, rq, ie); }
void mpi_issend_     (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_issend")));
void mpi_issend__    (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_issend")));
void mpi_probe       (MI *source, MI *tag, MI *comm, MI *status, MI *ie) { npif_probe(source, tag, comm, status, ie); }
void mpi_probe_      (MI *source, MI *tag, MI *comm, MI *status, MI *ie) __attribute__((alias("mpi_probe")));
void mpi_probe__     (MI *source, MI *tag, MI *comm, MI *status, MI *ie) __attribute__((alias("mpi_probe")));
void mpi_put         (M3C void *origin_addr, MI *origin_count, MI *origin_dt, MI *target_rank, MI *target_disp, MI *target_count, MI *target_dt, MI *win, MI *ie) { npif_put(origin_addr, origin_count, origin_dt, target_rank, target_disp, target_count, target_dt, win, ie); }
void mpi_put_        (M3C void *origin_addr, MI *origin_count, MI *origin_dt, MI *target_rank, MI *target_disp, MI *target_count, MI *target_dt, MI *win, MI *ie) __attribute__((alias("mpi_put")));
void mpi_put__       (M3C void *origin_addr, MI *origin_count, MI *origin_dt, MI *target_rank, MI *target_disp, MI *target_count, MI *target_dt, MI *win, MI *ie) __attribute__((alias("mpi_put")));
void mpi_recv        (void *buf, MI *count, MI *dt, MI *source, MI *tag, MI *comm, MI *status, MI *ie) { npif_recv(buf, count, dt, source, tag, comm, status, ie); }
void mpi_recv_       (void *buf, MI *count, MI *dt, MI *source, MI *tag, MI *comm, MI *status, MI *ie) __attribute__((alias("mpi_recv")));
void mpi_recv__      (void *buf, MI *count, MI *dt, MI *source, MI *tag, MI *comm, MI *status, MI *ie) __attribute__((alias("mpi_recv")));
void mpi_recv_init   (void *buf, MI *count, MI *dt, MI *source, MI *tag, MI *comm, MI *rq, MI *ie) { npif_recv_init(buf, count, dt, source, tag, comm, rq, ie); }
void mpi_recv_init_  (void *buf, MI *count, MI *dt, MI *source, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_recv_init")));
void mpi_recv_init__ (void *buf, MI *count, MI *dt, MI *source, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_recv_init")));
void mpi_reduce      (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *root, MI *comm, MI *ie) { npif_reduce(sb, rb, count, dt, op, root, comm, ie); }
void mpi_reduce_     (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *root, MI *comm, MI *ie) __attribute__((alias("mpi_reduce")));
void mpi_reduce__    (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *root, MI *comm, MI *ie) __attribute__((alias("mpi_reduce")));
void mpi_reduce_scatter  (M3C void *sb, void *rb, M3C MI *rcs, MI *dt, MI *op, MI *comm, MI *ie) { npif_reduce_scatter(sb, rb, rcs, dt, op, comm, ie); }
void mpi_reduce_scatter_ (M3C void *sb, void *rb, M3C MI *rcs, MI *dt, MI *op, MI *comm, MI *ie) __attribute__((alias("mpi_reduce_scatter")));
void mpi_reduce_scatter__(M3C void *sb, void *rb, M3C MI *rcs, MI *dt, MI *op, MI *comm, MI *ie) __attribute__((alias("mpi_reduce_scatter")));
void mpi_request_free  (MI *rq, MI *ie) { npif_rq_free(rq, ie); }
void mpi_request_free_ (MI *rq, MI *ie) __attribute__((alias("mpi_rq_free")));
void mpi_request_free__(MI *rq, MI *ie) __attribute__((alias("mpi_rq_free")));
void mpi_request_get_status  (MI *rq, int *flag, MI *status, MI *ie) { npif_rq_get_status(rq, flag, status, ie); }
void mpi_request_get_status_ (MI *rq, int *flag, MI *status, MI *ie) __attribute__((alias("mpi_rq_get_status")));
void mpi_request_get_status__(MI *rq, int *flag, MI *status, MI *ie) __attribute__((alias("mpi_rq_get_status")));
void mpi_rsend       (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *ie) { npif_rsend(buf, count, dt, dest, tag, comm, ie); }
void mpi_rsend_      (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *ie) __attribute__((alias("mpi_rsend")));
void mpi_rsend__     (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *ie) __attribute__((alias("mpi_rsend")));
void mpi_rsend_init  (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) { npif_rsend_init(buf, count, dt, dest, tag, comm, rq, ie); }
void mpi_rsend_init_ (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_rsend_init")));
void mpi_rsend_init__(M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_rsend_init")));
void mpi_scan        (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *comm, MI *ie) { npif_scan(sb, rb, count, dt, op, comm, ie); }
void mpi_scan_       (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *comm, MI *ie) __attribute__((alias("mpi_scan")));
void mpi_scan__      (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *comm, MI *ie) __attribute__((alias("mpi_scan")));
void mpi_scatter     (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *ie) { npif_scatter(sb, sc, st, rb, rc, rt, root, comm, ie); }
void mpi_scatter_    (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *ie) __attribute__((alias("mpi_scatter")));
void mpi_scatter__   (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *ie) __attribute__((alias("mpi_scatter")));
void mpi_scatterv    (M3C void *sb, M3C MI *scs, M3C MI *displs, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *ie) { npif_scatterv(sb, scs, displs, st, rb, rc, rt, root, comm, ie); }
void mpi_scatterv_   (M3C void *sb, M3C MI *scs, M3C MI *displs, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *ie) __attribute__((alias("mpi_scatterv")));
void mpi_scatterv__  (M3C void *sb, M3C MI *scs, M3C MI *displs, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *ie) __attribute__((alias("mpi_scatterv")));
void mpi_send        (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *ie) { npif_send(buf, count, dt, dest, tag, comm, ie); }
void mpi_send_       (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *ie) __attribute__((alias("mpi_send")));
void mpi_send__      (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *ie) __attribute__((alias("mpi_send")));
void mpi_send_init   (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) { npif_send_init(buf, count, dt, dest, tag, comm, rq, ie); }
void mpi_send_init_  (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_send_init")));
void mpi_send_init__ (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_send_init")));
void mpi_sendrecv    (M3C void *sb, MI *sc, MI *st, MI *dest, MI *sg, void *rb, MI *rc, MI *rt, MI *source, MI *recvtag, MI *comm, MI *status, MI *ie) { npif_sendrecv(sb, sc, st, dest, sg, rb, rc, rt, source, recvtag, comm, status, ie); }
void mpi_sendrecv_   (M3C void *sb, MI *sc, MI *st, MI *dest, MI *sg, void *rb, MI *rc, MI *rt, MI *source, MI *recvtag, MI *comm, MI *status, MI *ie) __attribute__((alias("mpi_sendrecv")));
void mpi_sendrecv__  (M3C void *sb, MI *sc, MI *st, MI *dest, MI *sg, void *rb, MI *rc, MI *rt, MI *source, MI *recvtag, MI *comm, MI *status, MI *ie) __attribute__((alias("mpi_sendrecv")));
void mpi_sendrecv_replace(void *buf, MI *count, MI *dt, MI *dest, MI *sg, MI *source, MI *recvtag, MI *comm, MI *status, MI *ie) { npif_sendrecv_replace(buf, count, dt, dest, sg, source, recvtag, comm, status, ie); }
void mpi_sendrecv_replace_(void *buf, MI *count, MI *dt, MI *dest, MI *sg, MI *source, MI *recvtag, MI *comm, MI *status, MI *ie) __attribute__((alias("mpi_sendrecv_replace")));
void mpi_sendrecv_replace__(void *buf, MI *count, MI *dt, MI *dest, MI *sg, MI *source, MI *recvtag, MI *comm, MI *status, MI *ie) __attribute__((alias("mpi_sendrecv_replace")));
void mpi_ssend       (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *ie) { npif_ssend(buf, count, dt, dest, tag, comm, ie); }
void mpi_ssend_      (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *ie) __attribute__((alias("mpi_ssend")));
void mpi_ssend__     (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *ie) __attribute__((alias("mpi_ssend")));
void mpi_ssend_init  (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) { npif_ssend_init(buf, count, dt, dest, tag, comm, rq, ie); }
void mpi_ssend_init_ (M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ssend_init")));
void mpi_ssend_init__(M3C void *buf, MI *count, MI *dt, MI *dest, MI *tag, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ssend_init")));
void mpi_start       (MI *rq, MI *ie) { npif_start(rq, ie); }
void mpi_start_      (MI *rq, MI *ie) __attribute__((alias("mpi_start")));
void mpi_start__     (MI *rq, MI *ie) __attribute__((alias("mpi_start")));
void mpi_startall    (MI *count, MI *ar, MI *ie) { npif_startall(count, ar, ie); }
void mpi_startall_   (MI *count, MI *ar, MI *ie) __attribute__((alias("mpi_startall")));
void mpi_startall__  (MI *count, MI *ar, MI *ie) __attribute__((alias("mpi_startall")));
void mpi_test        (MI *rq, MI *flag, MI *status, MI *ie) { npif_test(rq, flag, status, ie); }
void mpi_test_       (MI *rq, MI *flag, MI *status, MI *ie) __attribute__((alias("mpi_test")));
void mpi_test__      (MI *rq, MI *flag, MI *status, MI *ie) __attribute__((alias("mpi_test")));
void mpi_testall     (MI *count, MI *ar, MI *flag, MI *as, MI *ie) { npif_testall(count, ar, flag, as, ie); }
void mpi_testall_    (MI *count, MI *ar, MI *flag, MI *as, MI *ie) __attribute__((alias("mpi_testall")));
void mpi_testall__   (MI *count, MI *ar, MI *flag, MI *as, MI *ie) __attribute__((alias("mpi_testall")));
void mpi_testany     (MI *count, MI *ar, MI *index, MI *flag, MI *status, MI *ie) { npif_testany(count, ar, index, flag, status, ie); }
void mpi_testany_    (MI *count, MI *ar, MI *index, MI *flag, MI *status, MI *ie) __attribute__((alias("mpi_testany")));
void mpi_testany__   (MI *count, MI *ar, MI *index, MI *flag, MI *status, MI *ie) __attribute__((alias("mpi_testany")));
void mpi_testsome    (MI *incount, MI *ar, MI *outcount, MI *ai, MI *as, MI *ie) { npif_testsome(incount, ar, outcount, ai, as, ie); }
void mpi_testsome_   (MI *incount, MI *ar, MI *outcount, MI *ai, MI *as, MI *ie) __attribute__((alias("mpi_testsome")));
void mpi_testsome__  (MI *incount, MI *ar, MI *outcount, MI *ai, MI *as, MI *ie) __attribute__((alias("mpi_testsome")));
void mpi_wait        (MI *rq, MI *status, MI *ie) { npif_wait(rq, status, ie); }
void mpi_wait_       (MI *rq, MI *status, MI *ie) __attribute__((alias("mpi_wait")));
void mpi_wait__      (MI *rq, MI *status, MI *ie) __attribute__((alias("mpi_wait")));
void mpi_waitall     (MI *count, MI *ar, MI *as, MI *ie) { npif_waitall(count, ar, as, ie); }
void mpi_waitall_    (MI *count, MI *ar, MI *as, MI *ie) __attribute__((alias("mpi_waitall")));
void mpi_waitall__   (MI *count, MI *ar, MI *as, MI *ie) __attribute__((alias("mpi_waitall")));
void mpi_waitany     (MI *count, MI *rqs, MI *index, MI *status, MI *ie) { npif_waitany(count, rqs, index, status, ie); }
void mpi_waitany_    (MI *count, MI *rqs, MI *index, MI *status, MI *ie) __attribute__((alias("mpi_waitany")));
void mpi_waitany__   (MI *count, MI *rqs, MI *index, MI *status, MI *ie) __attribute__((alias("mpi_waitany")));
void mpi_waitsome    (MI *incount, MI *ar, MI *outcount, MI *ai, MI *as, MI *ie) { npif_waitsome(incount, ar, outcount, ai, as, ie); }
void mpi_waitsome_   (MI *incount, MI *ar, MI *outcount, MI *ai, MI *as, MI *ie) __attribute__((alias("mpi_waitsome")));
void mpi_waitsome__  (MI *incount, MI *ar, MI *outcount, MI *ai, MI *as, MI *ie) __attribute__((alias("mpi_waitsome")));
void mpi_win_complete  (MI *win, MI *ie) { npif_win_complete(win, ie); }
void mpi_win_complete_ (MI *win, MI *ie) __attribute__((alias("mpi_win_complete")));
void mpi_win_complete__(MI *win, MI *ie) __attribute__((alias("mpi_win_complete")));
void mpi_win_create  (void *base, MPI_Aint *size, MI *disp_unit, MI *info, MI *comm, MI *win, MI *ie) { npif_win_create(base, size, disp_unit, info, comm, win, ie); }
void mpi_win_create_ (void *base, MPI_Aint *size, MI *disp_unit, MI *info, MI *comm, MI *win, MI *ie) __attribute__((alias("mpi_win_create")));
void mpi_win_create__(void *base, MPI_Aint *size, MI *disp_unit, MI *info, MI *comm, MI *win, MI *ie) __attribute__((alias("mpi_win_create")));
void mpi_win_fence   (MI *assert, MI *win, MI *ie) { npif_win_fence(assert, win, ie); }
void mpi_win_fence_  (MI *assert, MI *win, MI *ie) __attribute__((alias("mpi_win_fence")));
void mpi_win_fence__ (MI *assert, MI *win, MI *ie) __attribute__((alias("mpi_win_fence")));
void mpi_win_free    (MI *win, MI *ie) { npif_win_free(win, ie); }
void mpi_win_free_   (MI *win, MI *ie) __attribute__((alias("mpi_win_free")));
void mpi_win_free__  (MI *win, MI *ie) __attribute__((alias("mpi_win_free")));
void mpi_win_post    (MI *group, MI *assert, MI *win, MI *ie) { npif_win_post(group, assert, win, ie); }
void mpi_win_post_   (MI *group, MI *assert, MI *win, MI *ie) __attribute__((alias("mpi_win_post")));
void mpi_win_post__  (MI *group, MI *assert, MI *win, MI *ie) __attribute__((alias("mpi_win_post")));
void mpi_win_start   (MI *group, MI *assert, MI *win, MI *ie) { npif_win_start(group, assert, win, ie); }
void mpi_win_start_  (MI *group, MI *assert, MI *win, MI *ie) __attribute__((alias("mpi_win_start")));
void mpi_win_start__ (MI *group, MI *assert, MI *win, MI *ie) __attribute__((alias("mpi_win_start")));
void mpi_win_wait    (MI *win, MI *ie) { npif_win_wait(win, ie); }
void mpi_win_wait_   (MI *win, MI *ie) __attribute__((alias("mpi_win_wait")));
void mpi_win_wait__  (MI *win, MI *ie) __attribute__((alias("mpi_win_wait")));
void mpi_iallgather  (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *comm, MI *rq, MI *ie) { npif_iallgather(sb, sc, st, rb, rc, rt, comm, rq, ie); }
void mpi_iallgather_ (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_iallgather")));
void mpi_iallgather__(M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_iallgather")));
void mpi_iallgatherv  (M3C void *sb, MI *sc, MI *st, void *rb, M3C MI *rc, M3C MI *displs, MI *rt, MI *comm, MI *rq, MI *ie) { npif_iallgatherv(sb, sc, st, rb, rc, displs, rt, comm, rq, ie); }
void mpi_iallgatherv_ (M3C void *sb, MI *sc, MI *st, void *rb, M3C MI *rc, M3C MI *displs, MI *rt, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_iallgatherv")));
void mpi_iallgatherv__(M3C void *sb, MI *sc, MI *st, void *rb, M3C MI *rc, M3C MI *displs, MI *rt, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_iallgatherv")));
void mpi_iallreduce  (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *comm, MI *rq, MI *ie) { npif_iallreduce(sb, rb, count, dt, op, comm, rq, ie); }
void mpi_iallreduce_ (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_iallreduce")));
void mpi_iallreduce__(M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_iallreduce")));
void mpi_ialltoall   (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *comm, MI *rq, MI *ie) { npif_ialltoall(sb, sc, st, rb, rc, rt, comm, rq, ie); }
void mpi_ialltoall_  (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ialltoall")));
void mpi_ialltoall__ (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ialltoall")));
void mpi_ialltoallv  (M3C void *sb, M3C MI *scs, M3C MI *sdispls, MI *st, MI *rb, M3C MI *rcs, M3C MI *rdispls, MI *rt, MI *rq, MI *comm, MI *ie) { npif_ialltoallv(sb, scs, sdispls, st, rb, rcs, rdispls, rt, rq, comm, ie); }
void mpi_ialltoallv_ (M3C void *sb, M3C MI *scs, M3C MI *sdispls, MI *st, MI *rb, M3C MI *rcs, M3C MI *rdispls, MI *rt, MI *rq, MI *comm, MI *ie) __attribute__((alias("mpi_ialltoallv")));
void mpi_ialltoallv__(M3C void *sb, M3C MI *scs, M3C MI *sdispls, MI *st, MI *rb, M3C MI *rcs, M3C MI *rdispls, MI *rt, MI *rq, MI *comm, MI *ie) __attribute__((alias("mpi_ialltoallv")));
void mpi_ibarrier    (MI *comm, MI *rq, MI *ie) { npif_ibarrier(comm, rq, ie); }
void mpi_ibarrier_   (MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ibarrier")));
void mpi_ibarrier__  (MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ibarrier")));
void mpi_ibcast      (void *buffer, MI *count, MI *dt, MI *root, MI *comm, MI *rq, MI *ie) { npif_ibcast(buffer, count, dt, root, comm, rq, ie); }
void mpi_ibcast_     (void *buffer, MI *count, MI *dt, MI *root, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ibcast")));
void mpi_ibcast__    (void *buffer, MI *count, MI *dt, MI *root, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ibcast")));
void mpi_igather     (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *rq, MI *ie) { npif_igather(sb, sc, st, rb, rc, rt, root, comm, rq, ie); }
void mpi_igather_    (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_igather")));
void mpi_igather__   (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_igather")));
void mpi_igatherv    (M3C void *sb, MI *sc, MI *st, void *rb, M3C MI *rcs, M3C MI *displs, MI *rt, MI *root, MI *comm, MI *rq, MI *ie) { npif_igatherv(sb, sc, st, rb, rcs, displs, rt, root, comm, rq, ie); }
void mpi_igatherv_   (M3C void *sb, MI *sc, MI *st, void *rb, M3C MI *rcs, M3C MI *displs, MI *rt, MI *root, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_igatherv")));
void mpi_igatherv__  (M3C void *sb, MI *sc, MI *st, void *rb, M3C MI *rcs, M3C MI *displs, MI *rt, MI *root, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_igatherv")));
void mpi_ireduce     (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *root, MI *comm, MI *rq, MI *ie) { npif_ireduce(sb, rb, count, dt, op, root, comm, rq, ie); }
void mpi_ireduce_    (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *root, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ireduce")));
void mpi_ireduce__   (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *root, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ireduce")));
void mpi_ireduce_scatter  (M3C void *sb, void *rb, M3C MI *rcs, MI *dt, MI *op, MI *comm, MI *rq, MI *ie) { npif_ireduce_scatter(sb, rb, rcs, dt, op, comm, rq, ie); }
void mpi_ireduce_scatter_ (M3C void *sb, void *rb, M3C MI *rcs, MI *dt, MI *op, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ireduce_scatter")));
void mpi_ireduce_scatter__(M3C void *sb, void *rb, M3C MI *rcs, MI *dt, MI *op, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_ireduce_scatter")));
void mpi_iscan       (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *comm, MI *rq, MI *ie) { npif_iscan(sb, rb, count, dt, op, comm, rq, ie); }
void mpi_iscan_      (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_iscan")));
void mpi_iscan__     (M3C void *sb, void *rb, MI *count, MI *dt, MI *op, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_iscan")));
void mpi_iscatter    (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *rq, MI *ie) { npif_iscatter(sb, sc, st, rb, rc, rt, root, comm, rq, ie); }
void mpi_iscatter_   (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_iscatter")));
void mpi_iscatter__  (M3C void *sb, MI *sc, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_iscatter")));
void mpi_iscatterv   (M3C void *sb, M3C MI *scs, M3C MI *displs, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *rq, MI *ie) { npif_iscatterv(sb, scs, displs, st, rb, rc, rt, root, comm, rq, ie); }
void mpi_iscatterv_  (M3C void *sb, M3C MI *scs, M3C MI *displs, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_iscatterv")));
void mpi_iscatterv__ (M3C void *sb, M3C MI *scs, M3C MI *displs, MI *st, void *rb, MI *rc, MI *rt, MI *root, MI *comm, MI *rq, MI *ie) __attribute__((alias("mpi_iscatterv")));