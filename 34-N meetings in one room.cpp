/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
Example 2:

Input:
N = 3
start[] = {10, 12, 20}
end[] = {20, 25, 30}
Output: 
1
Explanation:
Only one meetings can be held
with given start and end timings.
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    struct meeting{
        int start;
        int end;
        int pos;
    };
    
    bool static comparator(struct meeting m1,struct meeting m2)
    {
        if(m1.end<m2.end)
        return true;
        
        else if(m1.end>m2.end)
        return false;
        
        else if(m1.pos<m2.pos)
        return true;
        
        else
        return false;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int s[], int e[], int n)
    {
        // Your code here
        struct meeting meet[n];
        for(int i = 0 ; i< n ; i++)
        {
            meet[i].start = s[i];
            meet[i].end = e[i];
            meet[i].pos = i;
        }
        
        sort(meet,meet+n,comparator);
        
        int ans = 1,limit = meet[0].end;
        for(int i = 1 ; i< n ; i++)
        {
            if(meet[i].start>limit)
            {
                limit = meet[i].end;
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends