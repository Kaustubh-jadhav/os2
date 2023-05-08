set B


#include <cstdio>
#include <cstdlib>
#include <mpi.h>

static int rank, nodes;

int main()
{
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &nodes);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

    int ans = 0;
    int total = 0;

    int start = rank * 1000;
    int end = start + 999;

    for(int i = start; i <= end; i++) {
        ans = ans + i;
    }

    if(rank != 0) {
        MPI_Ssend(&ans, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    } else {
        total = ans;
        for(int j = 1; j < 10; j++) {
                MPI_Recv(&ans, 1, MPI_INT, j, 0, MPI_COMM_WORLD, &status);
                total += ans;
        }
        printf("Total is %d\n", total);
        printf("Total Nodes is %d\n", nodes);
   }


    MPI_Finalize();
    return 0;
}
