/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        
        vector<int> ans;
        int n = arr.size();
        int first =-1,second =-1,fcount =0,scount =0;
        for(int i =0;i<n;i++)
        {
            if(first == arr[i])
            {
               fcount++;
            }
            else if(second == arr[i])
            {
                scount++;
            }
            else if(fcount == 0)
            {
                first = arr[i];
                fcount =1;
            }
            else if(scount == 0)
            {
                second = arr[i];
                scount =1;
            }
            else
            {
                fcount--;
                scount--;
            }
        }
        
        fcount = scount =0;
        for(auto it : arr)
        {
            if(it == first)
                fcount++;
            
            else if(it == second)
                scount++;
        }
        
        if(fcount>n/3)
            ans.push_back(first);
        if(scount>n/3)
            ans.push_back(second);
        
        return ans;
    }
};