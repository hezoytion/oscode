//Bankers algo

#include <iostream> 
using namespace std; 
int main()
{
int n = 5, m = 4;
int alloc[5][4] = {{4, 0, 0, 1}, {1, 1, 0, 0}, {1, 2, 5, 4}, {1, 4,0,2}, {0, 2, 0,1}};
//for(int i=0;i<5;i++){
//	for(int j=0;j<4;j++){
//		cout<<alloc[i][j];
//	}
//	cout<<endl;
//}
int max[5][4] = {{6, 0, 1, 2}, {2, 7, 5, 0}, {2, 3, 5, 6}, {1, 6, 5, 3}, {1, 6, 5, 6}};
int avail[4] = {3, 2, 5, 1};
int need[5][4];
bool flag[5] = {false};
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < m; j++)
    {
        need[i][j] = max[i][j] - alloc[i][j];
        cout << need[i][j] << " ";
    }
    cout << endl;
}
int a = 0, res[5];
int counter=0;
int request1[4]={1,0,1,0};
for(int i=0;i<4;i++)
{
    if(request1[i]>need[1][i])
    {
        counter=1;
        cout<<"request can not be satisfied";
        break;
    }

}
if(counter==0)
{
    for(int i=0;i<4;i++)
{
    if(request1[i]>avail[i])
    {
        counter=1;
        cout<<"on hold";
        break;
    }

}
}
if(counter==0)
{
    for(int i=0;i<4;i++)
{
   avail[i]-=request1[i];
   alloc[1][i]+=request1[i];
   need[1][i]-=request1[i];

}

}
if(counter==0)
{
for (int b = 0; b < n; b++)
{
    for (int i = 0; i < n; i++)
    {
        if (!flag[i])
        {
            int f = 0;
            for (int j = 0; j < m; j++)
            {
                if (need[i][j] > avail[j])
                {
                    f = 1;
                    break;
                }
            }
            if (f == 0)
            {
                res[a] = i;
                a++;
                for (int j = 0; j < m; j++)
                {
                    avail[j] += alloc[i][j];
                }
                flag[i] = true;
            }
        }
    }
}
int f=0;
for(int i=0;i<n;i++){
if(!flag[i]){ f=1;
cout<<"Not safe";break; }
}
if(f==0){
cout<<"System is in safe mode"<<endl; for(int i=0;i<n;i++){
cout<<res[i]<<" "; }
}
}
}












/*

//fcfs

#include<iostream>
using namespace std;
int main() {
	int n,at[20],bt[20],wt[20],tat[20],ct[20],t=0,avwt=0,avtat=0,i,j;
	cout<<"Enter total number of processes(maximum 20):";
	cin>>n;
	cout<<"nEnter Process Burst Timen";
	for (i=0;i<n;i++) {
		cout<<"P["<<i+1<<"]:";
		cin>>bt[i];
	}
	cout<<"nEnter Process Arrrival Timen";
	for (i=0;i<n;i++) {
		cout<<"P["<<i+1<<"]:";
		cin>>at[i];
	}
	//completion time
	for(int i=0;i<n;i++)
	{
		while(at[i]>t)
		{
			t++;
		}
		ct[i]=t+bt[i];
		t+=ct[i];
		cout<<"nP["<<i+1<<"]"<<ct[i]<<endl;
	}
	//calculating turnaround time
	for (i=0;i<n;i++) {
		tat[i]=ct[i]-at[i];
		avtat+=tat[i];
		cout<<"nP["<<i+1<<"]"<<tat[i]<<endl;
	}
	//waiting tiome
		for (i=0;i<n;i++) 
		{
		    wt[i]=tat[i]-bt[i];
		    avwt+=wt[i];
		    cout<<"nP["<<i+1<<"]"<<wt[i]<<endl;
	}
	avwt=avwt/n;
	avtat=avtat/n;
	cout<<"nnAverage Waiting Time:"<<avwt<<endl;
	cout<<"nAverage Turnaround Time:"<<avtat<<endl;
	return 0;
}














//sjf(prem)

#include <stdio.h>
int main() 
{
 int a[10],b[10],x[10],i,j,smallest,count=0,time,n;
 double avg=0,tt=0,end;
  printf("enter the number of Processes:\n");
  scanf("%d",&n); 
 printf("enter arrival time\n");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 printf("enter burst time\n");
 for(i=0;i<n;i++)
 scanf("%d",&b[i]); 
 for(i=0;i<n;i++)
 x[i]=b[i];

  b[9]=9999;
  
 for(time=0;count!=n;time++)
 {
   smallest=9;
  for(i=0;i<n;i++)
  {
   if(a[i]<=time && b[i]<b[smallest] && b[i]>0 )
   smallest=i;
  }
  b[smallest]--;
  if(b[smallest]==0)
  {
   count++;
   end=time+1;
   avg=avg+end-a[smallest]-x[smallest];
   tt= tt+end-a[smallest];
  }
 }
 printf("\n\nAverage waiting time = %lf\n",avg/n);
    printf("Average Turnaround time = %lf",tt/n);
    return 0;
}


















//sjf(nonprem)



#include<iostream>
using namespace std;
struct process
{
	int at;
	int bt;
	int wt;
	int tat;
	int ct;
	int pid;
};
int main() {
	struct process p[4];
	int x,n=4,ele,t=0,avwt=0,avtat=0;
	struct process temp;
//	int n,at[20],bt[20],wt[20],tat[20],ct[20],t=0,avwt=0,avtat=0,i,j,p;
//	cout<<"Enter total number of processes(maximum 20):";
//	cin>>n;
//	cout<<"nEnter Process<< Burst Timen";
	for (int i=0;i<n;i++) {
		
		cout<<"nEnter Process"<<i+1<<"Burst Timen"<<" ";
		cout<<"P["<<i+1<<"]:";
		cin>>p[i].bt;
	}
	for (int i=0;i<n;i++) {
		
		cout<<"nEnter Process"<<i+1<<"Arriavl Timen"<<" ";
		cout<<"P["<<i+1<<"]:";
		cin>>p[i].at;
	}
	//sorting burst time kisks sabse kam hai
	for(int i=1;i<n;i++)
    {
    	x=i-1;
        ele=p[i].bt;
        temp=p[i];
    	while(x>=0 && p[x].bt>ele)
    	{
    		p[x+1]=p[x];
    		x--;
		}
		p[x+1]=temp;
		p[x+1].pid=i+1;
	}
	//completion time
	for(int i=0;i<n;i++)
	{
		while(p[i].at>t)
		{
			t++;
		}
		p[i].ct=t+p[i].bt;
		t=p[i].ct;
		cout<<"completion time"<<endl;
		cout<<"nP["<<p[i].pid<<"]"<<p[i].ct<<endl;
	}
	//calculating turnaround time
	for (int i=0;i<n;i++) {
		p[i].tat=p[i].ct-p[i].at;
		avtat+=p[i].tat;
		cout<<"turnaroundtime"<<endl;
		cout<<"nP["<<p[i].pid<<"]"<<p[i].tat<<endl;
	}
	
		for (int i=0;i<n;i++) 
		{
		    p[i].wt=p[i].tat-p[i].bt;
		    avwt+=p[i].wt;
		    cout<<"waiting time"<<endl;
		    cout<<"nP["<<p[i].pid<<"]"<<p[i].wt<<endl;
	}
	avwt=avwt/n;
	avtat=avtat/n;
	cout<<"nnAverage Waiting Time:"<<avwt<<endl;
	cout<<"nAverage Turnaround Time:"<<avtat<<endl;
	return 0;
}













//priority prem

#include<stdio.h>
struct process
{
    int WT,AT,BT,TAT,PT;
};

struct process a[10];

int main()
{
    int n,temp[10],t,count=0,short_p;
    float total_WT=0,total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time , burst time and priority of the process\n");
    printf("AT BT PT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].AT,&a[i].BT,&a[i].PT);
        
        // copying the burst time in
        // a temp array fot futher use
        temp[i]=a[i].BT;
    }
    
    // we initialize the burst time
    // of a process with maximum 
    a[9].PT=10000;
    
    for(t=0;count!=n;t++)
    {
        short_p=9;
        for(int i=0;i<n;i++)
        {
            if(a[short_p].PT>a[i].PT && a[i].AT<=t && a[i].BT>0)
            {
                short_p=i;
            }
        }
        
        a[short_p].BT=a[short_p].BT-1;
        
        // if any process is completed
        if(a[short_p].BT==0)
        {
            // one process is completed
            // so count increases by 1
            count++;
            a[short_p].WT=t+1-a[short_p].AT-temp[short_p];
            a[short_p].TAT=t+1-a[short_p].AT;
            
            // total calculation
            total_WT=total_WT+a[short_p].WT;
            total_TAT=total_TAT+a[short_p].TAT;
            
        }
    }
    
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;
    
    // printing of the answer
    printf("ID WT TAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d %d\t%d\n",i+1,a[i].WT,a[i].TAT);
    }
    
    printf("Avg waiting time of the process  is %f\n",Avg_WT);
    printf("Avg turn around time of the process is %f\n",Avg_TAT);
    
    return 0;
}

















//priority non prem

#include<bits/stdc++.h>
using namespace std;

struct Process
{
	int pid; // Process ID
	int bt; // CPU Burst time required
	int priority; // Priority of this process
};

// Function to sort the Process acc. to priority
bool comparison(Process a, Process b)
{
	return (a.priority > b.priority);
}

// Function to find the waiting time for all
// processes
void findWaitingTime(Process proc[], int n,
					int wt[])
{
	// waiting time for first process is 0
	wt[0] = 0;

	// calculating waiting time
	for (int i = 1; i < n ; i++ )
		wt[i] = proc[i-1].bt + wt[i-1] ;
}

// Function to calculate turn around time
void findTurnAroundTime( Process proc[], int n,
						int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n ; i++)
		tat[i] = proc[i].bt + wt[i];
}

//Function to calculate average time
void findavgTime(Process proc[], int n)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	//Function to find waiting time of all processes
	findWaitingTime(proc, n, wt);

	//Function to find turn around time for all processes
	findTurnAroundTime(proc, n, wt, tat);

	//Display processes along with all details
	cout << "\nProcesses "<< " Burst time "
		<< " Waiting time " << " Turn around time\n";

	// Calculate total waiting time and total turn
	// around time
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << proc[i].pid << "\t\t"
			<< proc[i].bt << "\t " << wt[i]
			<< "\t\t " << tat[i] <<endl;
	}

	cout << "\nAverage waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

void priorityScheduling(Process proc[], int n)
{
	// Sort processes by priority
	sort(proc, proc + n, comparison);

	cout<< "Order in which processes gets executed \n";
	for (int i = 0 ; i < n; i++)
		cout << proc[i].pid <<" " ;

	findavgTime(proc, n);
}

// Driver code
int main()
{
	Process proc[] = {{1, 10, 2}, {2, 5, 0}, {3, 8, 1}};
	int n = sizeof proc / sizeof proc[0];
	priorityScheduling(proc, n);
	return 0;
}




























//round robin

// C++ program for implementation of RR scheduling
#include<iostream>
using namespace std;
void findWaitingTime(int processes[], int n,
			int bt[], int wt[], int quantum)
{
	// Make a copy of burst times bt[] to store remaining
	// burst times.
	int rem_bt[n];
	for (int i = 0 ; i < n ; i++)
		rem_bt[i] = bt[i];

	int t = 0; // Current time

	// Keep traversing processes in round robin manner
	// until all of them are not done.
	while (1)
	{
		bool done = true;

		// Traverse all processes one by one repeatedly
		for (int i = 0 ; i < n; i++)
		{
			// If burst time of a process is greater than 0
			// then only need to process further
			if (rem_bt[i] > 0)
			{
				done = false; // There is a pending process

				if (rem_bt[i] > quantum)
				{
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t += quantum;

					// Decrease the burst_time of current process
					// by quantum
					rem_bt[i] -= quantum;
				}

				// If burst time is smaller than or equal to
				// quantum. Last cycle for this process
				else
				{
					// Increase the value of t i.e. shows
					// how much time a process has been processed
					t = t + rem_bt[i];

					// Waiting time is current time minus time
					// used by this process
					wt[i] = t - bt[i];

					// As the process gets fully executed
					// make its remaining burst time = 0
					rem_bt[i] = 0;
				}
			}
		}

		// If all processes are done
		if (done == true)
		break;
	}
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n,
						int bt[], int wt[], int tat[])
{
	// calculating turnaround time by adding
	// bt[i] + wt[i]
	for (int i = 0; i < n ; i++)
		tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[],
									int quantum)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;

	// Function to find waiting time of all processes
	findWaitingTime(processes, n, bt, wt, quantum);

	// Function to find turn around time for all processes
	findTurnAroundTime(processes, n, bt, wt, tat);

	// Display processes along with all details
	cout << "PN\t "<< " \tBT "
		<< " WT " << " \tTAT\n";

	// Calculate total waiting time and total turn
	// around time
	for (int i=0; i<n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
			<< wt[i] <<"\t\t " << tat[i] <<endl;
	}

	cout << "Average waiting time = "
		<< (float)total_wt / (float)n;
	cout << "\nAverage turn around time = "
		<< (float)total_tat / (float)n;
}

// Driver code
int main()
{
	// process id's
	int processes[] = { 1, 2, 3};
	int n = sizeof processes / sizeof processes[0];

	// Burst time of all processes
	int burst_time[] = {10, 5, 8};

	// Time quantum
	int quantum = 2;
	findavgTime(processes, n, burst_time, quantum);
	return 0;
}




















//worst fit

#include<stdio.h>
#include<conio.h>
#define max 25
int main()
{
int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;
static int bf[max],ff[max];
printf("\n\tMemory Management Scheme - Worst Fit");
printf("\nEnter the number of blocks:");
scanf("%d",&nb);
printf("Enter the number of files:");
scanf("%d",&nf);
printf("\nEnter the size of the blocks:-\n");
for(i=1;i<=nb;i++)
{
printf("Block %d:",i);
scanf("%d",&b[i]);
}
printf("Enter the size of the files :-\n");
for(i=1;i<=nf;i++)
{
printf("File %d:",i);
scanf("%d",&f[i]);
}
for(i=1;i<=nf;i++)
{

for(j=1;j<=nb;j++)
{
if(bf[j]!=1) //if bf[j] is not allocated
{
temp=b[j]-f[i];
if(temp>=0)
if(highest<temp)
{
ff[i]=j;
highest=temp;
}
}
}
frag[i]=highest;
bf[ff[i]]=1;
highest=0;
}
printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
for(i=1;i<=nf;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
getch();
}




















//best fit

#include<stdio.h>
#include<conio.h>
#define max 25
int main()
{
int frag[max],b[max],f[max],i,j,nb,nf,temp,lowest=10000;
static int bf[max],ff[max];

printf("\nEnter the number of blocks:");
scanf("%d",&nb);
printf("Enter the number of files:");
scanf("%d",&nf);
printf("\nEnter the size of the blocks:-\n");
for(i=1;i<=nb;i++)
{
printf("Block %d:",i);
scanf("%d",&b[i]);
}
printf("Enter the size of the files :-\n");
for(i=1;i<=nf;i++)
{
printf("File %d:",i);
scanf("%d",&f[i]);
}
for(i=1;i<=nf;i++)
{
for(j=1;j<=nb;j++)
{
if(bf[j]!=1)
{
temp=b[j]-f[i];
if(temp>=0)
if(lowest>temp)
{
ff[i]=j;

lowest=temp;
}
}
}
frag[i]=lowest;
bf[ff[i]]=1;
lowest=10000;
}
printf("\nFile No\tFile Size \tBlock No\tBlock Size\tFragment");
for(i=1;i<=nf && ff[i]!=0;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
getch();
}






















//first fit


#include<stdio.h>
#include<conio.h>
#define max 25
int main()
{
int frag[max],b[max],f[max],i,j,nb,nf,temp;
static int bf[max],ff[max];
printf("\n\tMemory Management Scheme - First Fit");
printf("\nEnter the number of blocks:");
scanf("%d",&nb);
printf("Enter the number of files:");
scanf("%d",&nf);
printf("\nEnter the size of the blocks:-\n");
for(i=1;i<=nb;i++)
{
printf("Block %d:",i);
scanf("%d",&b[i]);
}
printf("Enter the size of the files :-\n");
for(i=1;i<=nf;i++)
{
printf("File %d:",i);
scanf("%d",&f[i]);
}
for(i=1;i<=nf;i++)
{
for(j=1;j<=nb;j++)
{
if(bf[j]!=1)
{
temp=b[j]-f[i];
if(temp>=0)
{
ff[i]=j;
break;
}
}
}
frag[i]=temp;
bf[ff[i]]=1;
}
printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
for(i=1;i<=nf;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
getch();
}















//fcfs disk

#include <iostream>
#include<math.h>
using namespace std;
int main() {
int n, head, st = 0;
cin>>n;
int arr[n];
for(int i=0; i<n; i++) {
cin>>arr[i];
}
cin>>head;
for(int i=0; i<n; i++) {
st += abs(arr[i]-head);
head = arr[i];
}
cout<<st<<endl;
}


















//sstf disc

#include <iostream>
#include<math.h>
using namespace std;
int main() {
int n, head, st = 0, min_idx;
cin>>n;
int arr[n];
for(int i=0; i<n; i++) {
cin>>arr[i];
}
cin>>head;
bool vis[n];
for(int i=0; i<n; i++) {
vis[i] = false;
}
for(int i=0; i<n; i++) {
min_idx = -1;
for(int j=0; j<n; j++) {
if(!vis[j] && (min_idx==-1 || abs(head-arr[j])<abs(head-arr[min_idx]))) {
min_idx = j;
}
}
st += abs(head-arr[min_idx]);
head = arr[min_idx];
vis[min_idx] = true;
}
cout<<st<<endl;
return 0;
}

















//scanfinal

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    printf("Enter total disk size\n");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d",&move);
    
    // logic for Scan disk scheduling
    
        
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp;
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
   
    // if movement is towards high value
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        //  last movement for max size 
        TotalHeadMoment=TotalHeadMoment+abs(size-RQ[i-1]-1);
        initial = size-1;
        for(i=index-1;i>=0;i--)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    // if movement is towards low value
    else
    {
        for(i=index-1;i>=0;i--)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        //  last movement for min size 
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i+1]-0);
        initial =0;
        for(i=index;i<n;i++)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    
    printf("Total head movement is %d",TotalHeadMoment);
    return 0;
}


















//cscan

#include <iostream>
using namespace std;
int main() {
int n, ub, head, st = 0;
cin>>n;
int arr[n];
for(int i=0; i<n; i++) {
cin>>arr[i];
}
cin>>head>>ub;
for(int i=1; i<n; i++) {
int j = i-1, temp = arr[i];
while(j>=0 && arr[j]>temp) {
arr[j+1] = arr[j];
j--;
}
arr[j+1] = temp;
}
int i = 0;
while(i<n && arr[i]<head) {
i++;
}
int flag = i;
while(i<n) {
st += (arr[i]-head);
head = arr[i];
i++;
}
st += (ub-head);
st += ub;
head = 0;
i = 0;
while(i<flag) {
st += arr[i] - head;
head = arr[i];
i++;
}
cout<<st<<endl;
return 0;
}






























//clook

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int RQ[100],i,j,n,TotalHeadMoment=0,initial,size,move;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    printf("Enter total disk size\n");
    scanf("%d",&size);
    printf("Enter the head movement direction for high 1 and for low 0\n");
    scanf("%d",&move);
    
    // logic for C-look disk scheduling
    
    for(i=0;i<n;i++)
    {
        for( j=0;j<n-i-1;j++)
        {
            if(RQ[j]>RQ[j+1])
            {
                int temp;
                temp=RQ[j];
                RQ[j]=RQ[j+1];
                RQ[j+1]=temp;
            }

        }
    }

    int index;
    for(i=0;i<n;i++)
    {
        if(initial<RQ[i])
        {
            index=i;
            break;
        }
    }
   
    // if movement is towards high value
    if(move==1)
    {
        for(i=index;i<n;i++)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        
        for( i=0;i<index;i++)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    // if movement is towards low value
    else
    {
        for(i=index-1;i>=0;i--)
        {
            TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
            initial=RQ[i];
        }
        
        for(i=n-1;i>=index;i--)
        {
             TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
             initial=RQ[i];
            
        }
    }
    
    printf("Total head movement is %d",TotalHeadMoment);
    return 0;
}
*/