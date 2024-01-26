#include<stdio.h>
int max[10][10],alloc[10][10],need[10][10],avail[10],i,j,r,p,flag=0,finish[10]={0};
 int main()
   {
     printf("\nSIMULATION OF DEADLOCK PREVENTION");
     printf("\nenter no of process and resources : ");
     scanf("%d%d",&p,&r);
     printf("\n enter allocation marix");
     for(i=0;i<p;i++)
      for(j=0;j<r;j++)
      scanf("%d",&alloc[i][j]);

      printf("\n enter max marix");
      for(i=0;i<p;i++)    /* reading max matrix and avail. matrix*/
       for(j=0;j<r;j++)
       scanf("%d",&max[i][j]);
      printf("\n enter available marix");
      for(i=0;i<p;i++)
       scanf("%d",&avail[i]);
      for(i=0;i<p;i++)
       for(j=0;j<r;j++)
       need[i][j]=max[i][j]-alloc[i][j];
         void fun();
       if(flag==0)
	    {
	      if(finish[i]!=1)
        {
	       printf("failing : mututal exclusion!");
	       for(j=0;j<r;j++)
	       {
	         if(avail[j]<need[i][j])
	         avail[j]=need[i][j];
	        } void fun();
      printf("\n by allocating required process to process %d, deadlock is prevented ",i);
      printf("\n lack of preumtion");
	    for(j=0;j<r;j++)
	   {
	     if(avail[j]<need[i][j])
	     avail[j]=need[i][j];
	     alloc[i][j]=0;
     }
	  void fun();
	 printf("\n deadlock is prevented by allocating needed resources");
	 printf("\nfailing : hold and wait condition\n");
	 for(j=0;j<r;j++)
	 {
	  if(avail[j]<need[i][j])
	  avail[j]=need[i][j];
	 }
	 void fun();
      printf("AVOIDING ANYONE OF THE CONDITION,YOU CAN PREVENT DEADLOCK");
     }
   }
   return 0;
  }   

 void fun()
{
 while(1)
  {
   for(flag=0,i=0;i<p;i++)
    {
     if(finish[i]==0)
      {
       for(j=0;j<r;j++)
	     {
	       if(need[i][j]<=avail[j])
	         continue;
	       else
	        break;
	     }
       if(j==r)
       { 
         for(j=0;j<r;j++)
         avail[j]+=alloc[i][j];
         flag=1;
         finish[i]=1;
       }
     } 
   }
 }
}

