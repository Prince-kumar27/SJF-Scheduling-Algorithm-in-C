#include<stdio.h>
int main()
{
    int n, bt[20], at[20], wt[20], tat[20], rt[20], ct[20], i, j, temp;
    float avg_wt, avg_tat;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter the arrival time and burst time for each process:\n");
    for(i=0; i<n; i++)
    {
        printf("P[%d]: ", i+1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i]=bt[i];
    }
    // sorting processes based on arrival time using selection sort
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(at[i]>at[j])
            {
                //shorting arival time
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;

                //shorting burst time
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                //shorting responsetime
                temp=rt[i];
                rt[i]=rt[j];
                rt[j]=temp;
            }
        }
    }
    int time=at[0], done=0, min_bt, k;
    while(done!=n)
    {
        min_bt=9999; // assuming maximum burst time to be 9999
        k=-1;
        for(i=0; i<n; i++)
        {
            if(rt[i]>0 && at[i]<=time && rt[i]<min_bt)
            {
                min_bt=rt[i];
                k=i;
            }
        }
        if(k==-1) // no process available to execute
        {
            time++;
            continue;
        }
        // executing the process
        rt[k]--;
        time++;
        if(rt[k]==0) // process execution completed
        {
            done++;
            ct[k]=time;
            tat[k]=ct[k]-at[k];
            wt[k]=tat[k]-bt[k];
            if(wt[k]<0) wt[k]=0;
        }
    }
    // calculating average waiting time and average turnaround time
    avg_wt=0;
    avg_tat=0;
    printf("\nProcess\t   Arrival Time\t  Burst Time\t  Completion Time\t  Waiting Time\t  Turnaround Time\n");
    for(i=0; i<n; i++)
    {
        printf("P[%d]\t\t %d\t     %d\t\t\t %d\t\t    %d\t\t\t  %d\n", i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
        avg_wt+=wt[i];
        avg_tat+=tat[i];
    }
    avg_wt/=n;
    avg_tat/=n;
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f\n", avg_tat);
    return 0;
}
