/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> s;
        for(int val : nums)
        s.insert(val);
        int maxLen =0;
        for(int val : nums)
        {
            if(!s.count(val -1))
            {
                int currNum = val;
                int currLen = 1;
                
                while(s.count(currNum+1))
                {
                    currNum+=1;
                    currLen+=1;
                }
                maxLen = max(maxLen,currLen);
            }
        }
        return maxLen;
    }
};