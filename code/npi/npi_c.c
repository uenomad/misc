#include "npi.h"

int npic_Allgather(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, MPI_Comm comm)
{
    npi_enter(Allgather, (p2i)sb,(p2i)rb);
    int res = PMPI_Allgather(sb, sc, st, rb, rc, rt, comm);
    npi_leave(Allgather);
    return res;
}

int npic_Allgatherv(M3C void *sb, int sc, MD st, void *rb, M3C int *rcs, M3C int *displs, MD rt, MPI_Comm comm)
{
    npi_enter(Allgatherv,(p2i)sb,(p2i)rb);
    int res = PMPI_Allgatherv(sb, sc, st, rb, rcs, displs, rt, comm);
    npi_leave(Allgatherv);
    return res;
}

int npic_Allreduce(M3C void *sb, void *rb, int count, MD dt, MPI_Op op, MPI_Comm comm)
{
    npi_enter(Allreduce, (p2i)sb,(p2i)rb);
    int res = PMPI_Allreduce(sb, rb, count, dt, op, comm);
    npi_leave(Allreduce);
    return res;
}

int npic_Alltoall(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, MPI_Comm comm)
{
    npi_enter(Alltoall, (p2i)sb,(p2i)rb);
    int res = PMPI_Alltoall(sb, sc, st, rb, rc, rt, comm);
    npi_leave(Alltoall);
    return res;
}

int npic_Alltoallv(M3C void *sb, M3C int *scs, M3C int *sdispls, MD st, void *rb, M3C int *rcs, M3C int *rdispls, MD rt, MPI_Comm comm)
{
    npi_enter(Alltoallv, (p2i)sb,(p2i)rb);
    int res = PMPI_Alltoallv(sb, scs, sdispls, st, rb, rcs, rdispls, rt, comm);
    npi_leave(Alltoallv);
    return res;
}

int npic_Barrier(MPI_Comm comm)
{
    npi_enter(Barrier, (p2i)comm,0);
    int res = PMPI_Barrier(comm);
    npi_leave(Barrier);
    return res;
}

int npic_Bcast(void *buffer, int count, MD dt, int root, MPI_Comm comm)
{
    npi_enter(Bcast, (p2i)comm,0);
    int res = PMPI_Bcast(buffer, count, dt, root, comm);
    npi_leave(Bcast);
    return res;
}

int npic_Bsend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm)
{
    npi_enter(Bsend, (p2i)buf,(p2i)dest);
    int res = PMPI_Bsend(buf, count, dt, dest, tag, comm);
    npi_leave(Bsend);
    return res;
}

int npic_Bsend_init(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request)
{
    npi_enter(Bsend_init, (p2i)buf,(p2i)dest);
    int res = PMPI_Bsend_init(buf, count, dt, dest, tag, comm, request);
    npi_leave(Bsend_init);
    return res;
}

int npic_Cancel(MR *request)
{
    npi_enter(Cancel, (p2i)request,(p2i)0);
    int res = PMPI_Cancel(request);
    npi_leave(Cancel);
    return res;
}

int npic_Cart_create(MPI_Comm comm_old, int ndims, M3C int dims[], M3C int periods[], int reorder, MPI_Comm *comm_cart)
{
    npi_enter(Cart_create, (p2i)ndims,(p2i)comm_cart);
    int res = PMPI_Cart_create(comm_old, ndims, dims, periods, reorder, comm_cart);
    npi_leave(Cart_create);
    return res;
}

int npic_Cart_sub(MPI_Comm comm, M3C int remain_dims[], MPI_Comm *newcomm)
{
    npi_enter(Cart_sub, (p2i)remain_dims,(p2i)newcomm);
    int res = PMPI_Cart_sub(comm, remain_dims, newcomm);
    npi_leave(Cart_sub);
    return res;
}

int npic_Comm_create(MPI_Comm comm, MPI_Group group, MPI_Comm *newcomm)
{
    npi_enter(Comm_create, (p2i)group,(p2i)newcomm);
    int res = PMPI_Comm_create(comm, group, newcomm);
    npi_leave(Comm_create);
    return res;
}

int npic_Comm_dup(MPI_Comm comm, MPI_Comm *newcomm)
{
    npi_enter(Comm_dup, (p2i)newcomm,(p2i)0);
    int res = PMPI_Comm_dup(comm, newcomm);
    npi_leave(Comm_dup);
    return res;
}

int npic_Comm_free(MPI_Comm *comm)
{
    npi_enter(Comm_free, (p2i)comm,(p2i)0);
    int res = PMPI_Comm_free(comm);
    npi_leave(Comm_free);
    return res;
}

int npic_Comm_rank(MPI_Comm comm, int *rank)
{
    npi_enter(Comm_rank, (p2i)comm,(p2i)rank);
    int res = PMPI_Comm_rank(comm, rank);
    npi_leave(Comm_rank);
    return res;
}

int npic_Comm_size(MPI_Comm comm, int *size)
{
    npi_enter(Comm_size, (p2i)size,(p2i)0);
    int res = PMPI_Comm_size(comm, size);
    npi_leave(Comm_size);
    return res;
}

int npic_Comm_spawn(M3C char *command, char *argv[], int maxprocs, MPI_Info info, int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
    npi_enter(Comm_spawn, (p2i)command,(p2i)info);
    int res = PMPI_Comm_spawn(command, argv, maxprocs, info, root, comm, intercomm, array_of_errcodes);
    npi_leave(Comm_spawn);
    return res;
}

int npic_Comm_spawn_multiple(int count, char *array_of_commands[], char **array_of_argv[], M3C int array_of_maxprocs[], M3C MPI_Info array_of_info[], int root, MPI_Comm comm, MPI_Comm *intercomm, int array_of_errcodes[])
{
    npi_enter(Comm_spawn_multiple, (p2i)array_of_commands,(p2i)array_of_info);
    int res = PMPI_Comm_spawn_multiple(count, array_of_commands, array_of_argv, array_of_maxprocs, array_of_info, root, comm, intercomm, array_of_errcodes);
    npi_leave(Comm_spawn_multiple);
    return res;
}

int npic_Comm_split(MPI_Comm comm, int color, int key, MPI_Comm *newcomm)
{
    npi_enter(Comm_split, (p2i)key,(p2i)newcomm);
    int res = PMPI_Comm_split(comm, color, key, newcomm);
    npi_leave(Comm_split);
    return res;
}

int npic_File_close(MF *fh)
{
    npi_enter(File_close, (p2i)fh,(p2i)0);
    int res = PMPI_File_close(fh);
    npi_leave(File_close);
    return res;
}

int npic_File_read(MF fh, void *buf, int count, MD dt, MS *status)
{
    npi_enter(File_read, (p2i)buf,(p2i)dt);
    int res = PMPI_File_read(fh, buf, count, dt, status);
    npi_leave(File_read);
    return res;
}

int npic_File_read_all(MF fh, void *buf, int count, MD dt, MS *status)
{
    npi_enter(File_read_all, (p2i)buf,(p2i)dt);
    int res = PMPI_File_read_all(fh, buf, count, dt, status);
    npi_leave(File_read_all);
    return res;
}

int npic_File_read_at(MF fh, MPI_Offset offset, void *buf, int count, MD dt, MS *status)
{
    npi_enter(File_read_at, (p2i)buf,(p2i)dt);
    int res = PMPI_File_read_at(fh, offset, buf, count, dt, status);
    npi_leave(File_read_at);
    return res;
}

int npic_File_read_at_all(MF fh, MPI_Offset offset, void *buf, int count, MD dt, MS *status)
{
    npi_enter(File_read_at_all, (p2i)buf,(p2i)dt);
    int res = PMPI_File_read_at_all(fh, offset, buf, count, dt, status);
    npi_leave(File_read_at_all);
    return res;
}

int npic_File_write(MF fh, M3C void *buf, int count, MD dt, MS *status)
{
    npi_enter(File_write, (p2i)buf,(p2i)dt);
    int res = PMPI_File_write(fh, buf, count, dt, status);
    npi_leave(File_write);
    return res;
}

int npic_File_write_all(MF fh, M3C void *buf, int count, MD dt, MS *status)
{
    npi_enter(File_write_all, (p2i)buf,(p2i)dt);
    int res = PMPI_File_write_all(fh, buf, count, dt, status);
    npi_leave(File_write_all);
    return res;
}

int npic_File_write_at(MF fh, MPI_Offset offset, M3C void *buf, int count, MD dt, MS *status)
{
    npi_enter(File_write_at, (p2i)buf,(p2i)dt);
    int res = PMPI_File_write_at(fh, offset, buf, count, dt, status);

    npi_leave(File_write_at);
    return res;
}

int npic_File_write_at_all(MF fh, MPI_Offset offset, M3C void *buf, int count, MD dt, MS *status)
{
    npi_enter(File_write_at_all, (p2i)buf,(p2i)dt);
    int res = PMPI_File_write_at_all(fh, offset, buf, count, dt, status);
    npi_leave(File_write_at_all);
    return res;
}

int npic_Finalize(void)
{
    before_finalize();
    int res = PMPI_Finalize();
    after_finalize();
    return res;
}

int npic_Gather(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm)
{
    npi_enter(Gather, (p2i)sb,(p2i)rb);
    int res = PMPI_Gather(sb, sc, st, rb, rc, rt, root, comm);
    npi_leave(Gather);
    return res;
}

int npic_Gatherv(M3C void *sb, int sc, MD st, void *rb, M3C int *rcs, M3C int *displs, MD rt, int root, MPI_Comm comm)
{
    npi_enter(Gatherv, (p2i)sb,(p2i)rb);
    int res = PMPI_Gatherv(sb, sc, st, rb, rcs, displs, rt, root, comm);
    npi_leave(Gatherv);
    return res;
}

int npic_Get(void *origin_addr, int origin_count, MD origin_dt, int target_rank, MPI_Aint target_disp, int target_count, MD target_dt, MPI_Win win)
{
    npi_enter(Get, (p2i)origin_addr,(p2i)origin_dt);
    int res = PMPI_Get(origin_addr, origin_count, origin_dt, target_rank, target_disp, target_count, target_dt, win);
    npi_leave(Get);
    return res;
}

int npic_Ibsend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request)
{
    npi_enter(Ibsend, (p2i)buf,(p2i)dt);
    int res = PMPI_Ibsend(buf, count, dt, dest, tag, comm, request);
    npi_leave(Ibsend);
    return res;
}

int npic_Init(int *argc, char ***argv)
{
    before_init();
    int res = PMPI_Init(argc, argv);
    after_init();
    return res;
}

int npic_Init_thread(int *argc, char ***argv, int required, int *provided)
{
    before_init();
    int res = PMPI_Init_thread(argc, argv, required, provided);
    after_init();
    return res;
}

int npic_Intercomm_create(MPI_Comm local_comm, int local_leader, MPI_Comm peer_comm, int remote_leader, int tag, MPI_Comm *newintercomm)
{
    npi_enter(Intercomm_create, (p2i)local_leader,(p2i)remote_leader);
    int res = PMPI_Intercomm_create(local_comm, local_leader, peer_comm, remote_leader, tag, newintercomm);
    npi_leave(Intercomm_create);
    return res;
}

int npic_Intercomm_merge(MPI_Comm intercomm, int high, MPI_Comm *newintracomm)
{
    npi_enter(Intercomm_merge, (p2i)newintracomm,(p2i)0);
    int res = PMPI_Intercomm_merge(intercomm, high, newintracomm);
    npi_leave(Intercomm_merge);
    return res;
}

int npic_Iprobe(int source, int tag, MPI_Comm comm, int *flag, MS *status)
{
    npi_enter(Iprobe, (p2i)flag,(p2i)status);
    int res = PMPI_Iprobe(source, tag, comm, flag, status);
    npi_leave(Iprobe);
    return res;
}

int npic_Irecv(void *buf, int count, MD dt, int source, int tag, MPI_Comm comm, MR *request)
{
    npi_enter(Irecv, (p2i)buf,(p2i)request);
    int res = PMPI_Irecv(buf, count, dt, source, tag, comm, request);
    npi_leave(Irecv);
    return res;
}

int npic_Irsend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request)
{
    npi_enter(Irsend, (p2i)buf,(p2i)dest);
    int res = PMPI_Irsend(buf, count, dt, dest, tag, comm, request);
    npi_leave(Irsend);
    return res;
}

int npic_Isend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request)
{
    npi_enter(Isend, (p2i)buf,(p2i)dest);
    int res = PMPI_Isend(buf, count, dt, dest, tag, comm, request);
    npi_leave(Isend);
    return res;
}

int npic_Issend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request)
{
    npi_enter(Issend, (p2i)buf,(p2i)dest);
    int res = PMPI_Issend(buf, count, dt, dest, tag, comm, request);
    npi_leave(Issend);
    return res;
}

int npic_Probe(int source, int tag, MPI_Comm comm, MS *status)
{
    npi_enter(Probe, (p2i)source,(p2i)0);
    int res = PMPI_Probe(source, tag, comm, status);
    npi_leave(Probe);
    return res;
}

int npic_Put(M3C void *origin_addr, int origin_count, MD origin_dt, int target_rank, MPI_Aint target_disp, int target_count, MD target_dt, MPI_Win win)
{
    npi_enter(Put, (p2i)origin_addr,(p2i)0);
    int res = PMPI_Put(origin_addr, origin_count, origin_dt, target_rank, target_disp, target_count, target_dt, win);
    npi_leave(Put);
    return res;
}

int npic_Recv(void *buf, int count, MD dt, int source, int tag, MPI_Comm comm, MS *status)
{
    npi_enter(Recv, (p2i)buf,(p2i)source);
    int res = PMPI_Recv(buf, count, dt, source, tag, comm, status);
    npi_leave(Recv);
    return res;
}

int npic_Recv_init(void *buf, int count, MD dt, int source, int tag, MPI_Comm comm, MR *request)
{
    npi_enter(Recv_init, (p2i)buf,(p2i)source);
    int res = PMPI_Recv_init(buf, count, dt, source, tag, comm, request);
    npi_leave(Recv_init);
    return res;
}

int npic_Reduce(M3C void *sb, void *rb, int count, MD dt, MPI_Op op, int root, MPI_Comm comm)
{
    npi_enter(Reduce, (p2i)sb,(p2i)rb);
    int res = PMPI_Reduce(sb, rb, count, dt, op, root, comm);
    npi_leave(Reduce);
    return res;
}

int npic_Reduce_scatter(M3C void *sb, void *rb, M3C int *rcs, MD dt, MPI_Op op, MPI_Comm comm)
{
    npi_enter(Reduce_scatter, (p2i)sb,(p2i)rb);
    int res = PMPI_Reduce_scatter(sb, rb, rcs, dt, op, comm);
    npi_leave(Reduce_scatter);
    return res;
}

int npic_Request_free(MR *request)
{
    npi_enter(Request_free, (p2i)request,(p2i)0);
    int res = PMPI_Request_free(request);
    npi_leave(Request_free);
    return res;
}

int npic_Request_get_status(MR request, int *flag, MS *status)
{
    npi_enter(Request_get_status, (p2i)request,(p2i)0);
    int res = PMPI_Request_get_status(request, flag, status);
    npi_leave(Request_get_status);
    return res;
}

int npic_Rsend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm)
{
    npi_enter(Rsend, (p2i)buf,(p2i)dest);
    int res = PMPI_Rsend(buf, count, dt, dest, tag, comm);
    npi_leave(Rsend);
    return res;
}

int npic_Rsend_init(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request)
{
    npi_enter(Rsend_init, (p2i)buf,(p2i)0);
    int res = PMPI_Rsend_init(buf, count, dt, dest, tag, comm, request);
    npi_leave(Rsend_init);
    return res;
}

int npic_Scan(M3C void *sb, void *rb, int count, MD dt, MPI_Op op, MPI_Comm comm)
{
    npi_enter(Scan, (p2i)sb,(p2i)rb);
    int res = PMPI_Scan(sb, rb, count, dt, op, comm);
    npi_leave(Scan);
    return res;
}

int npic_Scatter(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm)
{
    npi_enter(Scatter, (p2i)sb,(p2i)rb);
    int res = PMPI_Scatter(sb, sc, st, rb, rc, rt, root, comm);
    npi_leave(Scatter);
    return res;
}

int npic_Scatterv(M3C void *sb, M3C int *scs, M3C int *displs, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm)
{
    npi_enter(Scatterv, (p2i)sb,(p2i)rb);
    int res = PMPI_Scatterv(sb, scs, displs, st, rb, rc, rt, root, comm);
    npi_leave(Scatterv);
    return res;
}

int npic_Send(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm)
{
    npi_enter(Send, (p2i)buf,(p2i)dest);
    int res = PMPI_Send(buf, count, dt, dest, tag, comm);
    npi_leave(Send);
    return res;
}

int npic_Send_init(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request)
{
    npi_enter(Send_init, (p2i)buf,(p2i)dest);
    int res = PMPI_Send_init(buf, count, dt, dest, tag, comm, request);
    npi_leave(Send_init);
    return res;
}

int npic_Sendrecv(M3C void *sb, int sc, MD st, int dest, int sendtag, void *rb, int rc, MD rt, int source, int recvtag, MPI_Comm comm, MS *status)
{
    npi_enter(Sendrecv, (p2i)sb,(p2i)rb);
    int res = PMPI_Sendrecv(sb, sc, st, dest, sendtag, rb, rc, rt, source, recvtag, comm, status);
    npi_leave(Sendrecv);
    return res;
}

int npic_Sendrecv_replace(void *buf, int count, MD dt, int dest, int sendtag, int source, int recvtag, MPI_Comm comm, MS *status)
{
    npi_enter(Sendrecv_replace, (p2i)buf,(p2i)dest);
    int res = PMPI_Sendrecv_replace(buf, count, dt, dest, sendtag, source, recvtag, comm, status);
    npi_leave(Sendrecv_replace);
    return res;
}

int npic_Ssend(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm)
{
    npi_enter(Ssend, (p2i)buf,(p2i)dest);
    int res = PMPI_Ssend(buf, count, dt, dest, tag, comm);
    npi_leave(Ssend);
    return res;
}

int npic_Ssend_init(M3C void *buf, int count, MD dt, int dest, int tag, MPI_Comm comm, MR *request)
{
    npi_enter(Ssend_init, (p2i)buf,(p2i)dest);
    int res = PMPI_Ssend_init(buf, count, dt, dest, tag, comm, request);
    npi_leave(Ssend_init);
    return res;
}

int npic_Start(MR *request)
{
    npi_enter(Start, (p2i)request,(p2i)0);
    int res = PMPI_Start(request);
    npi_leave(Start);
    return res;
}

int npic_Startall(int count, MR array_of_requests[])
{
    npi_enter(Startall, (p2i)array_of_requests,(p2i)0);
    int res = PMPI_Startall(count, array_of_requests);
    npi_leave(Startall);
    return res;
}

int npic_Test(MR *request, int *flag, MS *status)
{
    npi_enter(Test, (p2i)request,(p2i)0);
    int res = PMPI_Test(request, flag, status);
    npi_leave(Test);
    return res;
}

int npic_Testall(int count, MR array_of_requests[], int *flag, MS array_of_statuses[])
{
    npi_enter(Testall, (p2i)array_of_requests,(p2i)array_of_statuses);
    int res = PMPI_Testall(count, array_of_requests, flag, array_of_statuses);
    npi_leave(Testall);
    return res;
}

int npic_Testany(int count, MR array_of_requests[], int *indx, int *flag, MS *status)
{
    npi_enter(Testany, (p2i)array_of_requests,(p2i)flag);
    int res = PMPI_Testany(count, array_of_requests, indx, flag, status);
    npi_leave(Testany);
    return res;
}

int npic_Testsome(int incount, MR array_of_requests[], int *outcount, int array_of_indices[], MS array_of_statuses[])
{
    npi_enter(Testsome, (p2i)array_of_requests,(p2i)outcount);
    int res = PMPI_Testsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses);
    npi_leave(Testsome);
    return res;
}

int npic_Wait(MR *request, MS *status)
{
    npi_enter(Wait, (p2i)request,(p2i)status);
    int res = PMPI_Wait(request, status);
    npi_leave(Wait);
    return res;
}

int npic_Waitall(int count, MR *array_of_requests, MS *array_of_statuses)
{
    npi_enter(Waitall, (p2i)array_of_requests,(p2i)array_of_statuses);
    int res = PMPI_Waitall(count, array_of_requests, array_of_statuses);
    npi_leave(Waitall);
    return res;
}

int npic_Waitany(int count, MR *requests, int *index, MS *status)
{
    npi_enter(Waitany, (p2i)requests,(p2i)index);
    int res = PMPI_Waitany(count, requests, index, status);
    npi_leave(Waitany);
    return res;
}

int npic_Waitsome(int incount, MR *array_of_requests, int *outcount, int *array_of_indices, MS *array_of_statuses)
{
    npi_enter(Waitsome, (p2i)array_of_requests,(p2i)outcount);
    int res = PMPI_Waitsome(incount, array_of_requests, outcount, array_of_indices, array_of_statuses);
    npi_leave(Waitsome);
    return res;
}

int npic_Win_complete(MPI_Win win)
{
    npi_enter(Win_complete, (p2i)win,(p2i)0);
    int res = PMPI_Win_complete(win);
    npi_leave(Win_complete);
    return res;
}

int npic_Win_create(void *base, MPI_Aint size, int disp_unit, MPI_Info info, MPI_Comm comm, MPI_Win *win)
{
    npi_enter(Win_create, (p2i)base,(p2i)info);
    int res = PMPI_Win_create(base, size, disp_unit, info, comm, win);
    npi_leave(Win_create);
    return res;
}

int npic_Win_fence(int assert, MPI_Win win)
{
    npi_enter(Win_fence, (p2i)win,(p2i)0);
    int res = PMPI_Win_fence(assert, win);
    npi_leave(Win_fence);
    return res;
}

int npic_Win_free(MPI_Win *win)
{
    npi_enter(Win_free, (p2i)win,(p2i)0);
    int res = PMPI_Win_free(win);
    npi_leave(Win_free);
    return res;
}

int npic_Win_post(MPI_Group group, int assert, MPI_Win win)
{
    npi_enter(Win_post, (p2i)win,(p2i)0);
    int res = PMPI_Win_post(group, assert, win);
    npi_leave(Win_post);
    return res;
}

int npic_Win_start(MPI_Group group, int assert, MPI_Win win)
{
    npi_enter(Win_start, (p2i)win,(p2i)0);
    int res = PMPI_Win_start(group, assert, win);
    npi_leave(Win_start);
    return res;
}

int npic_Win_wait(MPI_Win win)
{
    npi_enter(Win_wait, (p2i)win,(p2i)0);
    int res = PMPI_Win_wait(win);
    npi_leave(Win_wait);
    return res;
}

int npic_Iallgather(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, MPI_Comm comm, MR *request)
{
    npi_enter(Iallgather, (p2i)sb,(p2i)rb);
	int res = PMPI_Iallgather(sb, sc, st, rb, rc, rt, comm, request);
    npi_leave(Iallgather);
	return res;
}

int npic_Iallgatherv(M3C void *sb, int sc, MD st, void *rb, M3C int rcs[], M3C int displs[], MD rt, MPI_Comm comm, MR *request)
{
    npi_enter(Iallgatherv, (p2i)sb,(p2i)rb);
	int res = PMPI_Iallgatherv(sb, sc, st, rb, rcs, displs, rt, comm, request);
    npi_leave(Iallgatherv);
	return res;
}

int npic_Iallreduce(M3C void *sb, void *rb, int count, MD dt, MPI_Op op, MPI_Comm comm, MR *request)
{
    npi_enter(Iallreduce, (p2i)sb,(p2i)rb);
	int res = PMPI_Iallreduce(sb, rb, count, dt, op, comm, request);
    npi_leave(Iallreduce);
	return res;
}

int npic_Ialltoall(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, MPI_Comm comm, MR *request)
{
    npi_enter(Ialltoall, (p2i)sb,(p2i)rb);
	int res = PMPI_Ialltoall(sb, sc, st, rb, rc, rt, comm, request);
    npi_leave(Ialltoall);
	return res;
}

int npic_Ialltoallv(M3C void *sb, M3C int scs[], M3C int sdispls[], MD st, void *rb, M3C int rcs[], M3C int rdispls[], MD rt, MPI_Comm comm, MR *request)
{
    npi_enter(Ialltoallv, (p2i)sb,(p2i)rb);
	int res = PMPI_Ialltoallv(sb, scs, sdispls, st, rb, rcs, rdispls, rt, comm, request);
    npi_leave(Ialltoallv);
	return res;
}

int npic_Ibarrier(MPI_Comm comm, MR *request)
{
    npi_enter(Ibarrier, (p2i)request,(p2i)0);
	int res = PMPI_Ibarrier(comm, request);
    npi_leave(Ibarrier);
	return res;
}

int npic_Ibcast(void *buffer, int count, MD dt, int root, MPI_Comm comm, MR *request)
{
    npi_enter(Ibcast, (p2i)buffer,(p2i)request);
	int res = PMPI_Ibcast(buffer, count, dt, root, comm, request);
    npi_leave(Ibcast);
	return res;
}

int npic_Igather(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm, MR *request)
{
    npi_enter(Igather, (p2i)sb,(p2i)rb);
	int res = PMPI_Igather(sb, sc, st, rb, rc, rt, root, comm, request);
    npi_leave(Igather);
	return res;
}

int npic_Igatherv(M3C void *sb, int sc, MD st, void *rb, M3C int rcs[], M3C int displs[], MD rt, int root, MPI_Comm comm, MR *request)
{
    npi_enter(Igatherv, (p2i)sb,(p2i)rb);
    int res = PMPI_Igatherv(sb, sc, st, rb, rcs, displs, rt, root, comm, request);
    npi_leave(Igatherv);
	return res;
}

int npic_Ireduce(M3C void *sb, void *rb, int count, MD dt, MPI_Op op, int root, MPI_Comm comm, MR *request)
{
    npi_enter(Ireduce, (p2i)sb,(p2i)rb);
	int res = PMPI_Ireduce(sb, rb, count, dt, op, root, comm, request);
    npi_leave(Ireduce);
	return res;
}

int npic_Ireduce_scatter(M3C void *sb, void *rb, M3C int rcs[], MD dt, MPI_Op op, MPI_Comm comm, MR *request)
{
    npi_enter(Ireduce_scatter, (p2i)sb,(p2i)rb);
	int res = PMPI_Ireduce_scatter(sb, rb, rcs, dt, op, comm, request);
    npi_leave(Ireduce_scatter);
	return res;
}

int npic_Iscan(M3C void *sb, void *rb, int count, MD dt, MPI_Op op, MPI_Comm comm, MR *request)
{
    npi_enter(Iscan, (p2i)sb,(p2i)rb);
	int res = PMPI_Iscan(sb, rb, count, dt, op, comm, request);
    npi_leave(Iscan);
	return res;
}

int npic_Iscatter(M3C void *sb, int sc, MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm, MR *request)
{
    npi_enter(Iscatter, (p2i)sb,(p2i)rb);
	int res = PMPI_Iscatter(sb, sc, st, rb, rc, rt, root, comm, request);
    npi_leave(Iscatter);
	return res;
}

int npic_Iscatterv(M3C void *sb, M3C int scs[], M3C int displs[], MD st, void *rb, int rc, MD rt, int root, MPI_Comm comm, MR *request)
{
    npi_enter(Iscatterv, (p2i)sb,(p2i)rb);
	int res = PMPI_Iscatterv(sb, scs, displs, st, rb, rc, rt, root, comm, request);
    npi_leave(Iscatterv);
	return res;
}