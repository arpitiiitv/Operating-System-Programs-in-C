#include<stdio.h>
#include<stdlib.h>
/*
Arpit Tiwari (IIITV)
*/
int main()
{
    int n;    //Number of procesess
    printf("  *** SJF NON-PREEMPTIVE (when arrival time of all is same) ***\n\n");
    printf("  Enter the number of process =>  ");
    scanf("%d",&n);   //number of proceses taken 
    printf("  Enter burst time of %d process => ",n);
    int BT[n];   //Array to store burst time of N process
    int q;  
    for(q=0;q<n;q++) { scanf("%d",&BT[q]); }   //burst time stored here in BT[n]
   
   /*
   @Normal table formation
   */
    printf("\n           *** Table ***     ");
    printf("\n+=================================+\n");
    printf("|  Process | Arrival  | BurstTime |\n");
    int a;
    for(a=0;a<n;a++)
    {
        printf("|  P%d      |    0     |    %02d     |\n",a,BT[a]);
    }
    printf("+=================================+\n");
    
    /*
    Sorting Array of Burst Time so that we can find Smallest length first
    */
     int i,j;
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
     {
          if(BT[i]>BT[j])   //if previous element is larger then swap it
          {
              int temp;
              temp=BT[i];
              BT[i]=BT[j];
              BT[j]=temp;
          }
     }
    
    int k,wait[n];  //array to store aiting time of each process
     wait[0]=0;  //first process will not wait
    for(k=0;k<n-1;k++)
     { wait[k+1]=wait[k]+BT[k];}  //next process will wait untill all previous processes completion
    int totalwait=0,t;   
    for(t=0;t<n;t++) { totalwait+=wait[t];}   //total wait is equals to sum of all waits before last process
    float avg=(float)totalwait/(float)n;
    printf("\n        *** Average Time *** ");
    printf("\n==============================================\n");
    printf("| Average waiting time of processes are %0.2f |",avg);
    printf("\n==============================================\n\n");
    
    printf("** Thank You ** \n");
    return 0;


}