/*

Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Examples:

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8

Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]]


Explanation: These are the unique combinations whose sum is equal to target.
 
Example 2:

Input: candidates = [2,5,2,1,2], target = 5

Output: [[1,2,2],[5]]

Explanation: These are the unique combinations whose sum is equal to target.

*/

//------------------------------------------------------------------------------------------



class Solution {
    private:
    void combinationSum2(int idx,int target,vector<int> &candidates,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(target == 0)
        {
            ans.push_back(ds);
                return;
        }
        
        for(int i = idx ; i<candidates.size();i++)
        {
            if(i>idx && candidates[i]==candidates[i-1])
                continue;
            
            if(candidates[i]>target)
                break;
            
            ds.push_back(candidates[i]);
             combinationSum2(i+1,target - candidates[i],candidates,ds,ans);
            ds.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        combinationSum2(0,target,candidates,ds,ans);
        return ans;
    }
};