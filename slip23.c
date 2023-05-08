set A

#include <stdio.h>

int banker_algorithm(int n, int m, int allocation[n][m], int max[n][m], int need[n][m], int available[m], int finish[n], int safe_sequence[n]) {
    int i, j, count = 0;
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int safe = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        safe = 0;
                        break;
                    }
                }
                if (safe == 1) {
                    safe_sequence[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                    for (j = 0; j < m; j++) {
                        available[j] += allocation[i][j];
                    }
                }
            }
        }
        if (found == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
   
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], need[n][m];
    int available[m], request[m], finish[n], safe_sequence[n];

   
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    
    printf("Enter the maximum matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Need :")
    for (i = 0; i < n; i++) {
    printf("p%d ",i);
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%2d",need[i][j]);
        }
        printf("/n");
    }

    
    printf("Enter the available resources vector:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

   
    printf("Enter the resource request vector:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &request[i]);
    }

    
    k = 0; // Only for this example, assuming that the request is for process 0
    for (i = 0; i < m; i++) {
        if (request[i] > need[k][i]) {
            printf("Error: Requested resources exceed maximum claim.\n");
            return 0;
        }
        if (request[i] > available[i]) {
            printf("Error: Requested resources are not available.\n");
            return 0
    }
}


for (i = 0; i < m; i++) {
    allocation[k][i] += request[i];
    need[k][i] -= request[i];
    available[i] -= request[i];
}


printf("\nNew Allocation Matrix:\n");
for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
        printf("%d ", allocation[i][j]);
    }
    printf("\n");
}

printf("\nNew Need Matrix:\n");
for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
        printf("%d ", need[i][j]);
    }
    printf("\n");
}

printf("\nNew Available Vector:\n");
for (i = 0; i < m; i++) {
    printf("%d ", available[i]);
}
printf("\n");

int safe = banker_algorithm(n, m, allocation, max, need, available, finish, safe_sequence);

if (safe == 1) {
    printf("\nResource request granted.\nSafe sequence:");
    for (i = 0; i < n; i++) {
        printf(" %d", safe_sequence[i]);
    }
    printf("\n");
} else {
    printf("\nResource request denied.\n");
}

return 0;


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
