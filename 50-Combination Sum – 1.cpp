/*

Problem Statement: 

Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Examples:

Example 1:

Input: array = [2,3,6,7], target = 7

Output: [[2,2,3],[7]]

Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
             7 is a candidate, and 7 = 7.
             These are the only two combinations.


Example 2:

Input: array = [2], target = 1

Output: []

Explaination: No combination is pos

*/

//------------------------------------------------------------------------------------------


class Solution {
    private:
    
    void helper(vector<vector<int>> &ans,vector<int>& candidates, int target,int i,vector<int> temp)
    {
        if(i == candidates.size())
        {
            if( target ==0)
            {
              ans.push_back(temp);           
            }
            return;
        }
        
        if(candidates[i] <= target)
        {
            temp.push_back(candidates[i]);
            helper(ans,candidates,target - candidates[i],i,temp);
            temp.pop_back();
        }
        
        helper(ans,candidates,target,i+1,temp);
        return;
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(ans,candidates,target,0,temp);
        return ans;
    }
};






