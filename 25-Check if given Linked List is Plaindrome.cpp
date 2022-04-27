/*
Problem Statement: Given the head of a singly linked list, return true if it is a palindrome.

Examples:

Example 1:
Input: head = [1,2,3,3,2,1] 
Output:
 true
Explanation: If we read elements from left to right, we get [1,2,3,3,2,1]. When we read elements from right to left, we get [1,2,3,3,2,1]. Both ways list remains same and hence, the given linked list is palindrome.

Example 2:
Input:
 head = [1,2]
Output:
 false
Explanation: When we read elements from left to right, we get [1,2]. Reading from right to left, we get a list as [2,1]. Both are different and hence, the given linked list is not palindrome.

 
*/

node* reverse(node* ptr) {
    node* pre=NULL;
    node* nex=NULL;
    while(ptr!=NULL) {
        nex = ptr->next;
        ptr->next = pre;
        pre=ptr;
        ptr=nex;
    }
    return pre;
}


bool isPalindrome(node* head) {
    if(head==NULL||head->next==NULL) return true;
        
    node* slow = head;
    node* fast = head;
        
    while(fast->next!=NULL&&fast->next->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
        
    slow->next = reverse(slow->next);
    slow = slow->next;
    node* dummy = head;
        
    while(slow!=NULL) {
        if(dummy->num != slow->num) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}