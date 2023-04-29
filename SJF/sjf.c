#include<stdio.h>
int main()
{
    //n    number of processes 
    //bt   burst time
    //p    process 
    //at   arrays to store the arrival time 
    //wt   waiting time 
    //tat  turnaround time
    //rt   remaining burst time
    //ct   completion time
    // variables for loop counters i and j and a temporary variable temp for sorting

    int n, bt[20],P[20], at[20], wt[20], tat[20], rt[20], ct[20], i, j, temp;
    float avg_wt, avg_tat;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter the arrival time & burst time for each process:\n");
    for(i=0; i<n; i++)
    {
        printf("P%d: ", i+1);
        P[i]=i+1;
        scanf("%d %d", &at[i], &bt[i]);
        rt[i]=bt[i];
    }
    // sorting processes based on arrival time using selection sort
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(at[i]>=at[j])
            {   //sorting arival time
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
               //sorting bt
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
               //sorting rt remaining time 
                temp=rt[i];
                rt[i]=rt[j];
                rt[j]=temp;
              //sorting process
                temp=P[i];
                P[i]=P[j];
                P[j]=temp;
            }
        }
    }
    //algorithm for sjf
    int time=at[0], done=0, min_bt, k;
    while(done!=n)//all n process not executed
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
    //calculating average waiting time and 
    //average turnaround time and printing it
    avg_wt=0;
    avg_tat=0;
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", P[i], at[i], bt[i], ct[i], wt[i], tat[i]);
        avg_wt+=wt[i];
        avg_tat+=tat[i];
    }
    avg_wt/=n;
    avg_tat/=n;
    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f\n", avg_tat);
    return 0;
}
