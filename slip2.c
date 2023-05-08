set A

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct dir
{
      char fname[20];
      int start;
      struct dir *next;
}NODE;

NODE *head,*last,*temp,*prev,*dell,*tmp;
int n,bit[MAX],fb=0;

void init()
{
      int i;
      printf("Enter total no. of disk blocks : ");
      scanf("%d",&n);
      for (i=0;i<n;i++)
      {
           bit[i]=rand()%2;
      }
}

void show_bitvector()
{
     int i;
     for (i=0;i<n;i++)
          printf("%d ",bit[i]);
     printf("\n");
}

void show_dir()
{
     NODE *temp;
     int i;
     printf("\nDirectory : ");
     printf("\nFile Name   Allocated Block Number");
     for (temp=head;temp!=NULL;temp=temp->next)
     {
          printf("\n %s",temp->fname);
          printf("      %d",temp->start);
     }
     printf("\n\nAllocated Blocks : ");
     for (temp=head;temp!=NULL;temp=temp->next)
     {
          printf("%d->",temp->start);
     }
     printf("NULL\n\n");
}

void create()
{
     NODE *p;
     char fname[20];
     int i,j,nob;
     int fb=0;
     printf("Enter file name : ");
     scanf("%s",&fname);
     printf("Enter the no of blocks : ");
     scanf("%d",&nob);
     for (i=0;i<n;i++)
     {
          if (bit[i]==0)
              fb++;
     }
     if (nob>fb)
     {
         printf("Failed to create file %s\n",fname);
         return;
     }
     else
     {
         for (i=0;i<n;i++)
         {
              if (bit[i]==0 && nob!=0)
              {
                  p=(NODE*)malloc(sizeof(NODE));
                  strcpy(p->fname,fname);
                  nob--;
                  bit[i]=1;
                  p->start=i;
                  p->next=NULL;
                  if (head==NULL)
                      head=p;
                  else
                      last->next=p;
                  last=p;
              }
         }
         printf("File %s created successfully \n",fname);
     }
}

int main()
{
    int ch;
    init();
    while(1)
    {
        printf("\n*******Menu*******\n");
        printf("\n1.Show bit Vector");
        printf("\n2.Create New File");
        printf("\n3.Show Directory");
        printf("\n4.Exit\n");
        printf("\nEnter Your Choice : \n");
        scanf("%d",&ch);
        
        switch (ch)
        {
                case 1: show_bitvector();
                        break;
                case 2: create();
                        break;
                case 3: show_dir();
                        break;
                case 4: exit(0);
        }
    }
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
