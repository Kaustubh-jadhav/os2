set A

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

set B

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
