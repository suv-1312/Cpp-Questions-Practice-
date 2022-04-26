/*

 Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
*/



class Solution {
    private:
    
    int merge(vector<int>& nums,int l,int m, int h)
    {
        int pairs = 0;
        int j = m+1;
        
        for(int i = l ;i<=m;i++)
        {
            while(j<=h && (long(nums[i]) > 2  * long(nums[j])))
            {
                j++;
            }
            pairs+=(j-(m+1));
        }
        
        //MERGING
        
        vector<int> t;
        int left = l,right = m+1;
        
        while(left<=m && right<=h)
        {
              if(nums[left]<=nums[right])
                  t.push_back(nums[left++]);
            else
                t.push_back(nums[right++]);
        }
        
        while(left<=m)
            t.push_back(nums[left++]);
        
        while(right<=h)
            t.push_back(nums[right++]);
        
        
        for(int i = l ;i<=h;i++)
        {
          nums[i] = t[i-l];
        }
        
        return pairs;
    }
    
    int mergeSort(vector<int>& nums,int low,int high)
    {
        
        if(low>=high)
            return 0;
            
            
            int mid = low+(high-low)/2;
            int count = mergeSort(nums,low,mid);
            count+=mergeSort(nums,mid+1,high);
            count+=merge(nums,low,mid,high);
            return count;
        
        
    }
public:
    int reversePairs(vector<int>& nums) {
        
        return mergeSort(nums,0,nums.size()-1);
    }
};