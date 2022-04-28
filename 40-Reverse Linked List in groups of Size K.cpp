/*
Problem Statement: Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Examples:

Example 1:
Input:
 head = [1,2,3,4,5,6,7,8] k=3
Output:
 head = [3,2,1,6,5,4,7,8]
Explanation:


Example 2:
Input:
 head = [1,2,3,4,5,6,7,8] k=2
Output:
 head = [2,1,4,3,6,5,8,7]
Explanation:


*/


class Solution {
    private:
    int length(ListNode * head)
    {
        ListNode *temp = head;
        int count = 0;
         while(temp!= NULL)
         {
             count++;
             temp = temp->next;
         }
        return count;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        if(head == NULL || k ==1 )
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *curr = dummy,*prev = dummy,*nex = dummy;
        
        int count = length(head);
        
        while(count >= k)
        {
            curr = prev -> next;
            nex = curr -> next;
            
            for(int i = 1; i<k ; i++)
            {
                curr -> next = nex -> next;
                nex -> next = prev -> next;
                prev -> next = nex;
                nex = curr -> next;
            }
            prev = curr;
            count-=k;
        }
        return dummy -> next;
    }
};


