set A

#include<stdio.h>
int main()
{
   int n,i,p[10],m,all[10][10],j,max[10][10],avail[10],need[10][10],option;
   printf("\n Enter total number of processes:");
   scanf("%d",&n);
   printf("\n Enter total number of resource instances:");
   scanf("%d",&m);
   printf("\n Enter Allocation matrix:");
   for(i=0;i<n;i++)
   {
      printf("\n for process p%d:",i);
      for(j=0;j<m;j++)
      {
         scanf("%d",&all[i][j]);
      }
   }
   printf("\n Enter Max matrix:");
   for(i=0;i<n;i++)
   {
      printf("\n for process p%d:",i);
      for(j=0;j<m;j++)
      {
         scanf("%d",&max[i][j]);
      }
   }
   while(1)
   {
      printf("\n---- menu ----\n");
      printf("\n1> Accept Available");
      printf("\n2> Display Allocation, Max");
      printf("\n3> Display the content of need matrix");
      printf("\n4> Display Available");
      printf("\n5> Exit :");
      printf("\n Enter Available:");
      scanf("%d",&option);
      switch(option)
      {
            case 1 :printf("\n Enter Available matrix :");
                     for(i=0;i<m;i++)
                     {  
                        scanf("%d",&avail[i]);
                     }
                     break;
            case 2 :
                     printf("\nAllocation matrix\n");
                     for(i=0;i<n;i++)
                     {
                        for(j=0;j<m;j++)
                        {
                           printf("%d\t",all[i][j]);
                        }
                        printf("\n");
                     }
                     printf("\nMax matrix\n");
                     for(i=0;i<n;i++)
                     {
                        for(j=0;j<m;j++)
                        {
                           printf("%d\t",max[i][j]);
                        }
                        printf("\n");
                     }
                     break;
            case 3 : printf("\nNeed matrix\n");
                     for(i=0;i<n;i++)
                     {
                        for(j=0;j<m;j++)
                        {
                           need[i][j]=max[i][j]-all[i][j];
                           printf("%d\t",need[i][j]);
                        }
                        printf("\n");
                     }
                     break;
            case 4 : printf("\n Available\n");
                     for(i=0;i<n;i++)
                     {
                        if(i==0)
                        {
                           for(j=0;j<m;j++)
                           {
                              printf("%d\t",avail[j]);
                           }
                        }
                     }
                     break;
            case 5 : printf("\n Bye");
                     return 0;
   
      }
   } 
   return 0; 
}

set B

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
