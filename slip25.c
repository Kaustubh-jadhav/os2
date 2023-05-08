set A

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int initial_head_pos, direction, num_requests,temp,total_seek=0,current_head_pos;
    float avg_seek_time;
    
    printf("Enter initial head position : ");
    scanf("%d",&initial_head_pos);
    
    printf("Enter the direction (0 for left 1 for right) : ");
    scanf("%d",&direction);
    
    printf("Enter the number of disk requests : ");
    scanf("%d",&num_requests);
    
    int request_queue[num_requests];
    
    printf("Enter the disk queue : ");
    for (int i=0;i<num_requests;i++)
    {
         scanf("%d",&request_queue[i]);
    }    
    for (int i=0;i<num_requests-1;i++)
    {
         for (int j=0;j<num_requests-1;j++)
         {
              if (request_queue[j]>request_queue[j+1])
              {
                  temp = request_queue[j];
                  request_queue[j]=request_queue[j+1];
                  request_queue[j+1]=temp;
              }
         }
    }
    
    int i;
    for (i=0;i<num_requests;i++)
    {
         if (request_queue[i]>=initial_head_pos)
             break;
    }
    
    current_head_pos=initial_head_pos;
    
    if (direction==1)
    {
        for (int j=i;j<num_requests;j++)
        {
             total_seek+=abs(request_queue[j]-current_head_pos);
             current_head_pos = request_queue[j];
             printf("Head Moving towards %d\n",current_head_pos);
        }
        
        for (int j=i-1;j>=0;j--)
        {
             total_seek+=abs(request_queue[j]-current_head_pos);
             current_head_pos=request_queue[j];
             printf("Head Moving towards %d\n",current_head_pos);
        }
    }
    else
    {
        for (int j=i-1;j>=0;j--)
        {
             total_seek+=abs(request_queue[j]-current_head_pos);
             current_head_pos=request_queue[j];
             printf("Head Moving towards %d\n",current_head_pos);
        }
        
        for (int j=i;j<num_requests;j++)
        {
             total_seek+=abs(request_queue[j]-current_head_pos);
             current_head_pos = request_queue[j];
             printf("Head Moving towards %d\n",current_head_pos);
        }
        
    }
    printf("Total seek movement : %d\n",total_seek);
    
    return 0;
}


set B

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
