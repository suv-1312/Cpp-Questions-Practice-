/*

In this article we will solve the most asked coding interview question: ” Merge two sorted Linked Lists “

Problem Statement: Given two singly linked lists that are sorted in increasing order of node values, merge two sorted linked lists and return them as a sorted list. The list should be made by splicing together the nodes of the first two lists.

Example 1:

Input Format :
l1 = {3,7,10}, l2 = {1,2,5,8,10}

Output :
{1,2,3,5,7,8,10,10}
Explanation :

merge two sorted linked list example 1
Merge two sorted linked lists example
These are two lists given. Both lists are sorted. We have to merge both lists and create a list that contains all nodes from the above nodes and it should be sorted.


Example 2:

Input Format :
l1 = {}, l2 = {3,6}

Output :
{3,6}

Explanation :
l1 is an empty list. l2 has two nodes. So, when we merge them, we will have the same list as l2.

*/




class Solution {

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // when list1 is empty then 
        // our output will be same as list2
        if(l1 == NULL) return l2; 

        // when list2 is empty then our output 
        // will be same as list1
        if(l2 == NULL) return l1;

        // pointing l1 and l2 to smallest and greatest one
        if(l1->val > l2->val) std::swap(l1,l2);

        // act as head of resultant merged list
        ListNode* res = l1;

        while(l1 != NULL && l2 != NULL) {
 
            ListNode* temp = NULL;

            while(l1 != NULL && l1->val <= l2->val) {

                temp = l1;//storing last sorted node  
                l1 = l1->next;
            }

            // link previous sorted node with 
            // next larger node in list2
            temp->next = l2;
            std::swap(l1,l2);
        }

        return res;
    }
};
