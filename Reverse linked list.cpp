/* 
Problem Link: https://leetcode.com/problems/reverse-linked-list/

Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []
 

Constraints:
The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 
Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // recursive method
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *rest_head = reverseList(head->next);
        
        ListNode *rest_tail = head->next;                        //it is on the second item
        rest_tail->next = head;
        head->next = NULL;
        
    return rest_head;   

    }
};

//      Iterative method
//         ListNode *curr = head;
//         ListNode *prv = NULL;
        
//         while(curr != NULL){
           
//             ListNode *next = curr->next;
//             curr->next = prv;
            
//             prv = curr;
//             curr = next;
//         }
//      return prv;                          //prv is the new head   

