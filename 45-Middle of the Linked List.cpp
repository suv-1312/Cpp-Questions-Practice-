/*
Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.

Examples:

Input Format: 
( Pointer / Access to the head of a Linked list )
head = [1,2,3,4,5]

Result: [3,4,5]
( As we will return the middle of Linked list the further linked list will be still available )

Explanation: The middle node of the list is node 3 as in the below image.

Input Format: 
Input: head = [1,2,3,4,5,6]

Result: [4,5,6]

Explanation: 
Since the list has two middle nodes with values 3 and 4, we return the second one.

*/



class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        if(head == NULL || head -> next== NULL )
            return head;
        
        ListNode * slow = head;
        ListNode * fast = head;
        
        while(fast !=NULL && fast->next  != NULL)
        {
            slow = slow ->next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};