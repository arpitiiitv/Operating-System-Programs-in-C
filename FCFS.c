#include<stdio.h>
int main()
{
    printf("  ***  First Come First Serve ***\n\n");
    int n; //Number of process
    printf("Enter the number of process :- ");
    scanf("%d",&n);
    int BurstTime[n];   //Array variable to store burst time of each process
    printf("\nEnter the burst time of  %d processes :- \n",n);
    int i;
    for(i=0;i<n;i++)
    {
             scanf("%d",&BurstTime[i]); //Burst time of n processes is stored in this Array
    }

 //calculation for waiting time
 int wait[n];   //Array of size n to store waiting time of each process
  wait[0]=0;   //First process will not wait
 int x=0;  
 for(x=0;x<n-1;x++)
 {
     wait[x+1]=wait[x]+BurstTime[x];   //waiting time of next process is equal to sum of
                               //waiting times of all privious process
 }
 int TotalWait=0;
 int q;
 for(q=0;q<n;q++) { TotalWait+=wait[q];}  //Sum of all waiting times is equals to total waiting time
 
   float avg; 
   avg=(float)TotalWait/(float) n; //Average time is equal to total wait time divided by number of process
   printf("\n+--------------------------------------------+\n");
   printf("| Average Waitng Time is equals to %0.2f      |",avg);
   printf("\n+--------------------------------------------+\n");
    int j;
    printf("\n               ***  Table Of Process  ***\n");
     printf("+----------------------------------------------------------+");
    printf("\n| Process   |  ArrivalTime  | BurstTime    | WaitingTime   |\n");
   for(j=0;j<n;j++)
   {
    printf("|  P[%d]     |       0       |  %03d         |     %03d       |\n",j,BurstTime[j],wait[j]);

   }
    printf("+----------------------------------------------------------+\n");
    printf("\nGantt Chart of processes :-  \n\n|");
   int a,b;
    for(a=0;a<n;a++)
       {    
            printf("P%d",a);
           for(b=0;b<BurstTime[a];b++)
           {
               printf(" *");
           }
           printf(" |");
       }  
  
  printf("\n\n");
 
   return 0;
}