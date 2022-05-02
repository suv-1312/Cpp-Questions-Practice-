/*

Given a stack, sort it using recursion. Use of any loop constructs like while, for..etc is not allowed. We can only use the following ADT functions on Stack S: 

is_empty(S)  : Tests whether stack is empty or not.
push(S)         : Adds new element to the stack.
pop(S)         : Removes top element from the stack.
top(S)         : Returns value of the top element. Note that this
               function does not remove element from the stack.
Example: 

Input:  -3  <--- Top
        14 
        18 
        -5 
        30 

Output: 30  <--- Top
        18 
        14 
        -3 
        -5 

*/




void insert(stack<int> &st,int val)
{
	if(st.empty() || val > st.top())
		st.push(val);
	
	else
	{
		int t = st.top();
		st.pop();
		insert(st,val);
		st.push(t);
	}
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(!stack.empty())
	{
		int t = stack.top();
		stack.pop();
		
		sortStack(stack);
		insert(stack,t);
	}
}