/*

Problem Statement: Check Balanced Parentheses. Given string str containing just the characters ‘(‘, ‘)’, ‘{‘, ‘}’, ‘[‘ and ‘]’, check if the input string is valid and return true if the string is balanced otherwise return false.

Note: string str is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Example 1:

Input: str = “( )[ { } ( ) ]”

Output: True

Explanation: As every open bracket has its corresponding 
close bracket. Match parentheses are in correct order 
hence they are balanced.
Example 2:

Input: str = “[ ( )”

Output: False

Explanation: As ‘[‘ does not have ‘]’ hence it is 
not valid and will return false.

*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0 ; i< s.size();i++)
        {
          if(s[i] == '(' || s[i]=='[' || s[i]=='{')
              st.push(s[i]);
          else
          {
              if(st.empty())
                  return false;
              
              char ch = st.top();
              if(((ch == '(' && s[i] !=')') ||(ch == '{' && s[i] != '}') || (ch == '[' && s[i] != ']') ))
              {
                  return false;
              }
              else
              {
                  st.pop();
              }
          }
        }
        
        return st.size()==0;
    
    }
};