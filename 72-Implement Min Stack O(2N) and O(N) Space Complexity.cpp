/*

Problem Statement: Implement Min Stack | O(2N) and O(N) Space Complexity. Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Examples:

Input Format:["MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"]
[
[ ], [-2], [0], [-3], [ ], [ ], [ ], [ ]
]

Result: [null, null, null, null, -3, null, 0, -2]
Explanation: 
stack < long long > st
st.push(-2); Push element in stack
st.push(0); Push element in stack
st.push(-3); Push element in stack
st.getMin(); Get minimum element fromstack
st.pop(); Pop the topmost element
st.top(); Top element is 0
st.getMin(); Minimum ele ment is -2

*/


----------------------------------------------Inserting Pair--------------------------------

class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        
        for(int i = 0 ; i<q.size()-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int a = q.front();
        q.pop();
        return a;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        
        return (q.size() == 0);
    }
};


-----------------------------------------Modyfying value-------------------------------------

  
class MyStack {
    stack<long long> st;
    long long mini;
public:
    MyStack() {
        mini = INT_MAX;
    }
    
    void push(int x) {
        
        if(st.empty())
        {
            mini = x;
            st.push(x);
        }
        
        else
        {
            if(x<mini)
            {
                mini = x;
                st.push(2 * x * 1LL - mini);
            }
            else
            {
                st.push(x);
            }
        }
        
    }
    
    int pop() {
        
        if(st.empty())
            return -1;
        
        if(st.top()<mini)
        {
            mini = 2 * mini -st.top();
        }
        long long t = st.top();
        st.pop();
        return t;
    }
    
    int top() {
        if(st.empty())
            return -1;
        
        if(st.top()<mini)
        {
            return mini;
        }
        
        return st.top();
    }
    
    bool empty() {
        return st.size() == 0;
    }
};


Time Complexity: O(1)

Space Complexity: O(N