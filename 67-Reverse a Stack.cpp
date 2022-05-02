/*

You are given a stack St. You have to reverse the stack using recursion.

 

Example 1:

Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}
 

Example 2:

Input:
St = {4,3,9,6}
Output:
{6,9,3,4}

*/


class Solution{
    private:
    void reverse(stack<int> St,vector<int> &ans)
    {
        if(St.empty())
        return;
        
        ans.push_back(St.top());
        St.pop();
        reverse(St,ans);
    }
public:
    vector<int> Reverse(stack<int> St){
     
     vector<int> ans;
     reverse(St,ans);
     return ans;
    }
};