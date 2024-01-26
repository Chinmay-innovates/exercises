#include<stdio.h>
int main()
{
    int bt[20],p[20],wt[10],tat[10],i,j,n,total=0,pos,temp;
    float avg_tat,avg_wt;
    printf("\nenter no.of process: ");
    scanf("%d",&n);
        printf("\nenter Burst time: \n");
        for ( i = 0; i < n; i++)
        {
           printf("p%d: ",i+1);
           scanf("%d",&bt[i]);
           p[i]=i+1; /*contains process no.*/
        }
        wt[0]=0;  /*waiting time of first process is zero*/
        for ( i = 1; i < n; i++)
        {
            wt[i]=0;
            for ( j = 0; j < i; j++)
                wt[i]+=bt[j];         /*calc. Waiting time*/
            total+=wt[i];    
        }
        avg_wt=(float)total/n;
        total=0;
        printf("\nProcess  \tBurstTime  \tWaitingTime  \t  TurnAroundTime");
          for ( i = 0; i < n; i++)
        {
            tat[i]=bt[i]+wt[i];
            total+=tat[i];               /*calc. TurnAround time*/
            printf("\np%d\t\t  %d\t\t  %d\t\t \t%d",p[i],bt[i],wt[i],tat[i]);
        }
        avg_tat=(float)total/n;
        printf("\n\nAVG WT = %.2f",avg_wt);
        printf("\n\nAVG TAT = %.2f",avg_tat);
}