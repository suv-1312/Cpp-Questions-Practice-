/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
*/

-------------------------------------BRUTE FORCE-------------------------------------------

#include <bits/stdc++.h>

using namespace std;
// Brute Force Approach to find largest rectangle area in Histogram
int largestarea(int arr[], int n) {
  int maxArea = 0;
  for (int i = 0; i < n; i++) {
    int minHeight = INT_MAX;
    for (int j = i; j < n; j++) {
      minHeight = min(minHeight, arr[j]);
      maxArea = max(maxArea, minHeight * (j - i + 1));
    }
  }
  return maxArea;
}
int main() {
  int arr[] = {2, 1, 5, 6, 2, 3, 1};
  int n = 7;
  cout << "The largest area in the histogram is " << largestarea(arr, n); // Printing the largest rectangle area
  return 0;
}


-------------------------------------EXTRA ARRAYS-------------------------------------------

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> st;
        int n = heights.size();
        vector<int> leftSmaller(n),rightSmaller(n);
        
        //Filling left Smaller Array
         for(int i = 0; i<n; i++)
         {
             while(!st.empty() && heights[st.top()]>=heights[i])
                 st.pop();
             
             if(st.empty())
                 leftSmaller[i] = 0;
             else
                 leftSmaller[i] = st.top() + 1;
             
             st.push(i);
         }
        
        //Empty the stack
        
        while(!st.empty())
            st.pop();
        
        //Filling right Smaller Array
        for(int i = n-1 ; i>=0 ; i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            
            if(st.empty())
                rightSmaller[i] = n-1;
            else
                rightSmaller[i] = st.top()-1;
            
            st.push(i);
        }
        
        int ans = INT_MIN;
        for(int i = 0 ; i<n ; i++)
        {
            ans = max(ans,heights[i] * (rightSmaller[i]-leftSmaller[i]+1));
            //cout<<"leftSmaller[i] : "<<leftSmaller[i]<<" rightSmaller[i] : "<<rightSmaller[i]<<endl;
        }
        return ans;
        
    }
};

-------------------------------------BEST ONE-----------------------------------------------



#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int largestRectangleArea(vector < int > & histo) {
      stack < int > st;
      int maxA = 0;
      int n = histo.size();
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
};
int main() {
  vector < int > histo = {2, 1, 5, 6, 2, 3, 1};
  Solution obj;
  cout << "The largest area in the histogram is " << obj.largestRectangleArea(histo) << endl;
  return 0;
}