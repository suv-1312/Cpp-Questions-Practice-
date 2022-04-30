/*

Problem Statement: Given N and K, where N is the sequence of numbers from 1 to N([1,2,3….. N]) find the Kth permutation sequence.

For N = 3  the 3!  Permutation sequences in order would look like this:-



Note: 1<=K<=N! Hence for a given input its Kth permutation always exists

Examples:

Example 1:

Input: N = 3, K = 3
 
Output: “213”

Explanation: The sequence has 3! permutations as illustrated in the figure above. K = 3 corresponds to the third sequence.

Example 2:

Input: N = 3, K = 5 

Result: “312”

Explanation: The sequence has 3! permutations as illustrated in the figure above. K = 5 corresponds to the fifth sequence.

*/

//-------------------------------------------NAIVE---------------------------------------------

class Solution {
  public:
    //function to generate all possible permutations of a string
    void solve(string & s, int index, vector < string > & res) {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        solve(s, index + 1, res);
        swap(s[i], s[index]);
      }
    }

  string getPermutation(int n, int k) {
    string s;
    vector < string > res;
    //create string
    for (int i = 1; i <= n; i++) {
      s.push_back(i + '0');
    }
    solve(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    //make k 0-based indexed to point to kth sequence
    auto it = res.begin() + (k - 1);
    return *it;
  }
};

//-------------------------------------------OPTIMAL---------------------------------------------


class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> nums;
        int fact = 1;
        
        for(int i = 1; i<n;i++)
        {
             fact*=i;
             nums.push_back(i);
        }
        nums.push_back(n);
        string ans = "";
        k = k-1;
        
        while(1)
        {
            ans+=to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            
            if(nums.size() == 0)
                break;
            
            k = k%fact;
            fact = fact/nums.size();
        }
        return ans;
    }
};