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

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,n,seek=0,max,head,move,q[100];
	printf("\n Enter queue size:");
	scanf("%d",&n);
	printf("\n Enter queue elements:");
	for(i=0;i<n;i++)
		scanf("%d",&q[i]);
	printf("\n Enter initial head position:");
	scanf("%d",&head);
	printf("\n Enter max disk size:");
	scanf("%d",&max);
	printf("\n Enter the head movemnet direction 1 for right and 0 for left:");
	scanf("%d",&move);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(q[j]>q[j+1])
			{
				int temp;
				temp=q[j];
				q[j]=q[j+1];
				q[j+1]=temp;
			}
		}
	}
	
	int index;
	for(i=0;i<n;i++)
	{
		if(head<q[i])
		{
			index=i;
			break;
		}
	}
	
	printf("\n Sequence of head movement:");
	if(move==1)
	{
		printf("%d\t",head);
		for(i=index;i<n;i++)
		{
			seek+=abs(q[i]-head);
			head=q[i];
			printf("%d\t",q[i]);
		}
		seek+=abs(max-q[i-1]-1);
		seek+=abs(max-1-0);
		printf("%d\t",max-1);
		head=0;
		printf("%d\t",head);
		for(i=0;i<index;i++)
		{
			seek+=abs(q[i]-head);
			head=q[i];
			printf("%d\t",q[i]);
		}
	}
	else
	{
		printf("%d\t",head);
		for(i=index-1;i>=0;i--)
		{
			seek+=abs(q[i]-head);
			head=q[i];
			printf("%d\t",q[i]);
		}
		seek+=abs(q[i+1]-0);
		seek+=abs(max-1-0);
		head=max-1;
		printf("%d\t",head);
		for(i=n-1;i>=index;i--)
		{
			seek+=abs(q[i]-head);
			head=q[i];
			printf("%d\t",q[i]);
		}
	}
	printf("\n\n Total head movements are %d",seek);
	return 0;
}
