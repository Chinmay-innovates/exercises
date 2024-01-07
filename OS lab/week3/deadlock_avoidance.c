#include<stdio.h>
#include<conio.h>
int main()
{
 int allocated[15][15],max[15][15],need[15][15],avail[15];
 int tres[15],work[15],flag[15];
 int pno,rno,i,j,count,t,total,prc;
 count=0;

 printf("enter no.of process: ");
 scanf("%d",&pno);
 printf("enter no.of resouces: ");
 scanf("%d",&rno);
  for(i=0;i<=pno;i++){
   flag[i]=0;
  }
 printf("\nEnter total no.of each resources: ");
  for(i=1;i<=rno;i++)
  scanf("%d",&tres[i]);
 printf("Enter max. resouces for each process: ");
 for(i=1;i<=pno;i++)
  {
   printf("\nfor prcocess%d: ",i);
    for(j=1;j<=rno;j++)
      scanf("%d",&max[i][j]);
  }
printf("\nEnter allocated resouces for each process: ");
 for(i=1;i<=pno;i++)
  {
   printf("\nfor prcocess%d: ",i);
    for(j=1;j<=rno;j++)
      scanf("%d",&allocated[i][j]);
  }
printf("\nAvailable resources : \n");
  for(j=1;j<=rno;j++)
   {
    avail[j]=0;
    total=0;
    for(i=1;i<=pno;i++)
     {
       total+=allocated[i][j];
     }
    avail[j]=tres[j]-total;
    work[j]=avail[j];
    printf("  %d\t",work[j]);
   }
do
{
   for(i=1;i<=pno;i++)
    {
     for(j=1;j<=rno;j++)
     {
       need[i][j]=max[i][j]-allocated[i][j];
     }
    }

printf("\nAllocated    Max    Need");
 for(i=1;i<=pno;i++)
  {
    printf("\n");
      for(j=1;j<=rno;j++)
       printf("%4d",allocated[i][j]);
    printf("|");
     for(j=1;j<=rno;j++)
       printf("%4d",max[i][j]);
    printf("|");
      for(j=1;j<=rno;j++)
       printf("%4d",need[i][j]);
   }
 prc=0;
  for(i=1;i<=pno;i++)
   {   
    if(flag[i]==0)
     {
      prc=i;
      for(j=1;j<=rno;j++){
	    if(work[j]<need[i][j])
	  {
	    prc=0;
	    break;
	  }
	}
}
    if(prc!=0)
    break;
   }

   if(prc!=0)
    {
     printf("\nProcess %d completed",i);
     count++;
     printf("\nAvailable matrix");
      for(j=1;j<=rno;j++)
       {
	       work[j]+=allocated[i][j];
	       allocated[prc][j]=0;
	       max[prc][j]=0;
	       flag[prc]=1;
	       printf(" %d",work[j]);
       }
     }
}while(count!=pno && prc!=0);
    if(count==pno)
      printf("\nThe system is in safe state!!");
    else
     printf("\nThe system is in unsafe state!!!");
  return 0;
}



