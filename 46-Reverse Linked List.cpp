/*

Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

Examples:

Input Format: 
head = [3,6,8,10]
This means the given linked list is 3->6->8->10 with head pointer at node 3.

Result:
Output = [10,6,8,3]
This means, after reversal, the list should be 10->6->8->3 with the head pointer at node 10.

*/


//----------------------------------------RECURSIVE-------------------------------


 ListNode* reverseList(ListNode* &head) {

        if (head == NULL||head->next==NULL)
            return head;

        ListNode* nnode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nnode;
    }


//----------------------------------------ITERATIVE-------------------------------


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL || head -> next == NULL)
            return head;
        
        ListNode * curr = head;
        ListNode *prev = NULL;
        while(curr)
        {
            ListNode * next = curr -> next;
            curr -> next = prev;
            
            prev = curr;
            curr = next;
         }
        return prev;
    }
};