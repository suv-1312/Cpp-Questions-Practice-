/*
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head -> next == NULL || k ==0)
            return head;
        
        ListNode *temp = head;
        int length = 1;
        while(temp->next!=NULL)
        {
            length++;
            temp = temp-> next;
        }
        
        temp->next = head;
        k = k%length;
        int end = length-k;
        
        while(end--)
            temp = temp-> next;
        
        head = temp -> next;
        temp ->next = NULL;
        
        return head;
    }
};