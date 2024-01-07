#include<stdio.h>
int main()
{
    int st[10],bt[10],wt[10],tat[10],n,tq;
    int i,count=0,swt=0,stat=0,temp,sq=0;
    float awt,atat;
     printf("\nenter no.of process: ");
    scanf("%d",&n);
        printf("\nenter Burst time: \n");
        for ( i = 0; i < n; i++)
        {
           printf("p%d: ",i+1);
           scanf("%d",&bt[i]);
           st[i]=bt[i];
        }
        printf("Enter the time quantum: ");
        scanf("%d",&tq);
        while(1)
        {
           for ( i = 0,count=0; i < n ; i++)
           {
             temp=tq;
             if(st[i]==0){
                count++;
                continue;
             }
             if(st[i]>tq)
             st[i]=st[i]-tq;
             else
             if(st[i]>=0){
                temp=st[i];
                st[i]=0;
             }
             sq=sq+temp; /*sq+=temp*/
             tat[i]=sq;
           }
           if(n==count)
             break;
        }
        for(i=0;i<n;i++){
            wt[i]=tat[i]-bt[i]; /*waiting_time = total_time - burst_time*/
            swt=swt+wt[i];
            stat=stat+tat[i];
        }
        awt=(float)swt/n;
        atat=(float)stat/n;
        printf("\nProcess  \tBurstTime  \tWaitingTime  \tTurnAroundTime");
          for ( i = 0; i < n; i++){
              printf("\np%d\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
        }
        printf("\n\nAVG WT = %.2f",awt);
        printf("\n\nAVG TAT = %.2f",atat);
}