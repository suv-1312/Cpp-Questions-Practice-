/*
Problem Statement: Given an array of non-negative integers representation elevation of ground. Your task is to find the water that can be trapped after raining.

Examples:

Example 1:

Input: height= [0,1,0,2,1,0,1,3,2,1,2,1]

Output: 6

Explanation: As seen from the diagram 1+1+2+1+1=6 unit of water can be trapped



Example 2:

Input:  [4,2,0,3,2,5]

Output:9
*/


class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size(),water =0;
        int lmax = 0,rmax = 0;
        int l = 0,r = n-1;
        
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>lmax)
                    lmax = height[l];
                
                else
                    water+=lmax - height[l];
                
                l++;
            }
            else
            {
                if(height[r]>rmax)
                    rmax = height[r];
                
                else
                    water+=rmax - height[r];
                
                r--;
            }
        }
        return water;
    }
};