/*
Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

Examples:

Input Format: 
(Pointer/Access to the head of the two linked lists)

num1  = 342, num2 = 564

l1 = [2,4,3]
l2 = [5,6,4]

Result: sum = 807; L = [7,0,8]

Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the or                                                original number and then add them as → 342 + 465 = 807. Refer to the image below.
  



Input Format: 
(Pointer/Access to the head of the two linked lists)

l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]

Result: [8,9,9,9,0,0,0,1]

Explanation: Since the digits are stored in reverse order, reverse the numbers first to get the     original number and then add them as → 9999999 + 9999 = 8999001. Refer to the image below.


*/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        
        int carry = 0;
        
        while((l1 || l2)||carry)
        {
            int sum = 0;
           if(l1)
           {
               sum+=l1->val;
               l1 = l1 -> next;
           }
            
           if(l2)
           {
               sum+=l2->val;
               l2 = l2 -> next;
           }
                  
           sum += carry;
           carry = sum/10;
           ListNode *node = new ListNode(sum%10);
           temp -> next = node;
           temp = temp -> next;
        }
        return dummy -> next;
    }
};
