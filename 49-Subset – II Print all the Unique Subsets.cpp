/*

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

*/

//-------------------------------------------NAIVE---------------------------------------------

class Solution {
    private:
    void solve(int idx, vector<int> &nums,int n,set<vector<int>> &s,vector<int> temp)
    {
        if(idx == n)
        {
            //sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }
        
        temp.push_back(nums[idx]);
        solve(idx+1,nums,n,s,temp);
        temp.pop_back();
        
        solve(idx+1,nums,n,s,temp);
            
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> temp;
        
        int n = nums.size();
        solve(0,nums,n,s,temp);
        
        ans.assign(s.begin(),s.end());
        
        return ans;
    }
};


//-------------------------------------------OPTIMAL---------------------------------------------


class Solution {
    private:
    void helper(int idx,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans)
    {
        ans.push_back(ds);
        for(int i = idx ; i< nums.size();i++)
        {
            if(i!=idx && nums[i] == nums[i-1])
                continue;
            
            ds.push_back(nums[i]);
            helper(i+1,nums,ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        sort(nums.begin(),nums.end());
        helper(0,nums,ds,ans);
        
        return ans;
    }
};