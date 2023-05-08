set A

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

set B

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int bv[50],i,st,j,len,c,k;
char name[10][30];
int start[10],length[10],num=0;

void displayBitVector()
{
     printf("\nBit Vector contents : \n");
     for (i=0;i<50;i++)
          printf("%d ",bv[i]);
}

void createFile()
{
     char temp[30];
     printf("Enter the name of file : ");
     scanf("%s",&temp);
     for (int i=0;i<num;i++)
          if (strcmp(name[i],temp)==0)
          {
              printf("\nFilename already exists");
              return;
          }
     strcpy(name[num],temp);
     printf("Enter the start block of the file : ");
     scanf("%d",&start[num]);
     printf("Enter the length of the file : ");
     scanf("%d",&length[num]);
     
     for (j=start[num];j<(start[num]+length[num]);j++)
          if (bv[j]==1)
          {
              printf("File cannot be allocated.... block already allocated");
              strcpy(name[j],"-");
              start[j]=0;
              length[j]=0;
              return;
          }
     for (j=start[num];j<(start[num]+length[num]);j++)
     {
          bv[j]=1;
          printf("\n%d->%d",j,bv[j]);
     }
     num++;
}

void showDirectory()
{
      printf("Directory contents\n");
      printf("%s%40s%40s\n","File Name","Start Block","Length");
      int i;
      for (i=0;i<num;i++)
      {
           if (strcmp(name[i],"-")!=0)
           {
               printf("%s%40d%40d\n",name[i],start[i],length[i]);
           }
      }
}

void deleteFile()
{
     char temp[10];
     printf("\nEnter the filename : ");
     scanf("%s",&temp);
     for (int i=0;i<num;i++)
     {
          if (strcmp(name[i],temp)==0)
          {
             
                   for (j=start[i];j<(start[i]+length[i]);j++)
                   {
                        bv[j]=0;
                        printf("\n%d->%d",j,bv[j]);
                   }
                   printf("\nFile successfully deleted...");
                   strcpy(name[i],"-");
                   start[i]=0;
                   length[i]=0;
                   return;
              
          }
     }
}

int main()
{
    int ch=0;
    for (i=0;i<50;i++)
         bv[i]=0;
         
    do 
    {
        printf("\n*******Menu*******\n");
        printf("\n1.Show bit Vector");
        printf("\n2.Create New File");
        printf("\n3.Show Directory");
        printf("\n4.Delete File");
        printf("\n5.Exit\n");
        printf("\nEnter Your Choice : \n");
        scanf("%d",&ch);
        
        switch (ch)
        {
                case 1: displayBitVector();
                        break;
                case 2: createFile();
                        break;
                case 3: showDirectory();
                        break;
                case 4: deleteFile();
                        break;
        }
    }while(ch!=5);
}
