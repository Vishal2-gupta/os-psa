#include<stdio.h>
 int main()
{
    int bt[15],p[15],wt[20],tat[30],pr[15],at[20];
    int i,j,n,total=0,pos,temp,proc,avg_wt,avg_tat,priorityScheduling;

    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time,Arrival Time and Priority of Process\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Arrival Time:");
        scanf("%d",&at[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           
    }
 
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=at[i];
        at[i]=at[pos];
        at[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=2;
 
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;   
    total=0;
 
    printf("\nProcess\t    Burst Time\t Arrival Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];  
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t  %d\t\t  %d\t\t\t%d",p[i],bt[i],at[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;     

    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
	return 0;
}
