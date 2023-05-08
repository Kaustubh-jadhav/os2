set A

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int q[20],head,n,j,i,seek=0,max,diff;
	printf("\n Enter the max range of disk:");
	scanf("%d",&max);
	printf("\n Enter size of queue request:");
	scanf("%d",&n);
	printf("\n Enter queue disk position to be read:");
	for(i=1;i<=n;i++)
		scanf("%d",&q[i]);
	printf("\n Enter initial head position:");
	scanf("%d",&head);
	q[0]=head;
	for(j=0;j<=n-1;j++)
	{
		diff=abs(q[j+1]-q[j]);
		seek+=diff;
		printf("Disk head moves from %d to %d with seek %d\n",q[j],q[j+1],diff);
	}
	printf("Total head movement is %d\n",seek);
	return 0;
}

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
