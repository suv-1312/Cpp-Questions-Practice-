/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

INPUT:
[[1,3],[2,6],[8,10],[15,18]]
[[1,4],[4,5]]

OUTPUT:
[[1,6],[8,10],[15,18]]
[[1,5]]

*/




//Brute Force

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        
        for(int i = 0; i<intervals.size();i++)
        {
            int s = intervals[i][0];
            int e = intervals[i][1];
            
            
            if(ans.size()!=0)
            {
                vector<int> t = ans.back();
                if(s<=t[1])
                    continue;
            }
            
            for(int j = i+1;j<intervals.size();j++)
            {
                if(intervals[j][0]<=e)
                {
                    e = max(intervals[j][1],e);
                }
            }
            ans.push_back({s,e});  
        }
        return ans;
    }
};


//BETTER

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i=0;i<arr.size();i++)
        {
            if(ans.size() == 0 || ans.back()[1]<arr[i][0])
            {
                ans.push_back({arr[i][0],arr[i][1]});
            }
            else
            {
                ans.back()[1] = max(ans.back()[1],arr[i][1]);
            }
        }
        return ans;
    }
};

