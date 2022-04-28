/*
Given a set of N jobs where each jobi has a deadline and profit associated with it.

Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.

Find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).
*/







struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    bool static comp(Job a,Job b)
    {
        if(a.profit>b.profit)
        return true;
        else
        return false;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        
        int maxi = arr[0].dead;
        for(int i = 1 ; i<n;i++)
        {
            maxi = max(maxi,arr[i].dead);
        }
        
        int slot[maxi+1];
        for(int i = 0;i<=maxi;i++)
        {
            slot[i] = -1;
        }
        
        int jobs = 0,profit =0;
        for(int i = 0;i<n ; i++)
        {
            for(int j = arr[i].dead;j>0;j--)
            {
                if(slot[j] == -1)
                {
                    slot[j] = arr[i].id;
                    jobs++;
                    profit+=arr[i].profit;
                    break;
                }
            }
        }
        
         for(int i = 0;i<=maxi;i++)
        {
            cout<<slot[i]<<" ";
        }
        cout<<endl;
        
        return {jobs,profit};
    } 
};

