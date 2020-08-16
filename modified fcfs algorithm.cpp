#include<iostream>

using namespace std;
 
 struct Process
	{
   	string ccode;     // course code
   	int duration;      // class duration
   	int priority;  //priority
   	int arrival_time;   //prefered arrival time
	};
	Process processes[] = {{"CSC 2201",2,3,1}, {"CSC 3401", 3, 1,3}, {"CSC 1103", 1,4,2}, {"CSC 1405",4,2,4}};
    int n = sizeof processes / sizeof processes[0];
 
// function to find the waiting time for all processes
void findWaitingTime(Process processes[], int n,  int wt[])
{
    // waiting time for first process will be 0
    wt[0] = 0;
 
    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        wt[i] =  processes[i-1].duration + wt[i-1];
    }
}
 
// function to calculate turn around time
void findTurnAroundTime(Process processes[], int n,  int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
    {
        tat[i] = processes[i].duration + wt[i];
    }
}
 
// function to calculate average time
void findAverageTime(Process processes[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // function to find waiting time of all processes
    findWaitingTime(processes, n, wt);
 
    // function to find turn around time for all processes
    findTurnAroundTime(processes, n, wt, tat);
 
    // display processes along with all details
    cout << "Processes  "<< " Burst time  "<< " Waiting time  " << " Turn around time\n";
 
    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << processes[i].ccode  << "\t" <<processes[i].duration <<"\t    "<< wt[i] <<"\t\t  " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "<< (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "<< (float)total_tat / (float)n;
}
 
// main function
int main()
{
    
 
    findAverageTime(processes, n);
    
    return 0;
}



