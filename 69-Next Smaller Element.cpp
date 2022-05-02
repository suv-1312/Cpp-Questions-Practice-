/*

Problem Statement
You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.
Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.
If for any array element the next smaller element does not exist, you should print -1 for that array element.
For Example:
If the given array is [ 2, 3, 1], we need to return [1, 1, -1]. Because for  2, 1 is the Next Smaller element. For 3, 1 is the Next Smaller element and for 1, there is no next smaller element hence the answer for this element is -1.

*/


#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &nums, int n)
{
    // Write your code here.
	 vector<int> ans;
        
        stack<int>s;     
        for(int i = n -1;i>=0 ;i--)
        {
             while(!s.empty() && s.top()>=nums[i])
             {
                  s.pop();
             }
            
             s.empty()?ans.push_back(-1):ans.push_back(s.top());
            
            s.push(nums[i]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
}