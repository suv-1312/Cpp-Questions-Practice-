/*


Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

Example 1 :

Input format: Arr[] = {1,3,2}

Output: Arr[] = {2,1,3}

Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.
Example 2:

Input format: Arr[] = {3,2,1}

Output: Arr[] = {1,2,3}

Explanation: As we see all permutations of {1,2,3}, we find {3,2,1} at the last position. So, we have to return the topmost permutation.

*/


//------------------------------------------------------------------------------------------


class Solution {
    private :
    void reverse(vector<int> &arr,int l,int h)
    {
        while(l<h)
        {
            swap(arr[l],arr[h]);
                l++;
            h--;
        }
    }
public:
    void nextPermutation(vector<int>& a) {
        
        int n = a.size();
        int idx1 = -1,idx2 = -1;
        for(int i = n-2 ;i>=0;i--)
        {
            if(a[i]<a[i+1])
            {
                idx1 = i;
                break;
            }
        }
        
        if(idx1<0)
        {
            reverse(a,idx1+1,n-1);
        }
        else
        {
         for(int i = n-1 ;i>=0;i--)
        {
            if(a[i]>a[idx1])
            {
                idx2 = i;
                break;
            }
        }
        swap(a[idx1],a[idx2]);
        reverse(a,idx1+1,n-1);
        }
    }
};

