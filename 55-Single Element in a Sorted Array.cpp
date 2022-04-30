/*
Problem Statement: Given a sorted array of N integers, where every element except one appears exactly twice and one element appears only once. Search Single Element in a sorted array.

Example 1:

Input: N = 9, array[] = {1,1,2,3,3,4,4,8,8} 

Output: 2

Explanation: Every element in this sorted array except 2 
appears twice, therefore the answer returned will be 2.
Example 2:

Input: N = 7, array[] = {11,22,22,34,34,57,57} 

Output: 11

Explanation: Every element in this sorted array except 
11 appears twice, therefore the answer returned will be 11.

*/



class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int l = 0,r = nums.size()-1;
        
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            
            int check = (mid - l) % 2;
            
            if(mid>0 && nums[mid] == nums[mid-1])
            {
                if(check)
                    l = mid + 1;
                else
                    r = mid-2;
            }
            
            else if(mid+1<nums.size() && nums[mid] == nums[mid+1])
            {
                if(check)
                    r = mid - 1;
                else
                    l = mid + 2;
            }
            
            else
                return nums[mid];
        }
        return -1;
    }
};