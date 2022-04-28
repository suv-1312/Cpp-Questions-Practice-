/*

Problem Statement: Given a linked list, and a number N. Find the Nth node from the end of this linkedlist, and delete it. Return the head of the new modified linked list.

Example 1 : 

Input: head = [1,2,3,4,5], n = 2

Output: [1,2,3,5]

Explanation: Refer Below Image

Example 2:

Input: head = [7,6,9,4,13,2,8], n = 6

Output: [7,9,4,13,2,8]

Explanation: Refer Below Image

Example 3:

Input: head = [1,2,3], n = 3

Output: [2,3]

*/


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(head == NULL)
            return head;
        
        ListNode * start = new ListNode();
        start->next = head;
        
        ListNode* slw = start;
        ListNode* fst = start;
        
        for(int i =0;i<n;i++)
            fst = fst->next;
        
        while(fst ->next != NULL)
        {
            fst = fst->next;
            slw = slw -> next;
        }
        slw ->next = slw ->next -> next;
        return start -> next;
    }
};


