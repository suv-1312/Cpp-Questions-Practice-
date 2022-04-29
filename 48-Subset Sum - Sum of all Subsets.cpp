/*

Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.

Examples:

Example 1:

Input: N = 3, arr[] = {5,2,1}

Output: 0,1,2,3,5,6,7,8

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [5], [5,1], [5,2]. [5,2,1],so the sums we get will be  0,1,2,3,5,6,7,8


Input: N=3,arr[]= {3,1,2}

Output: 0,1,2,3,3,4,5,6

Explanation: We have to find all the subset’s sum and print them.in this case the generated subsets are [ [], [1], [2], [2,1], [3], [3,1], [3,2]. [3,2,1],so the sums we get will be  0,1,2,3,3,4,5,6


*/

class Solution {
  public:
    void solve(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      //element is picked
      solve(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      solve(ind + 1, arr, n, ans, sum);
    }
  vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    solve(0, arr, n, ans, 0);
    return ans;
  }
};
