/*
Problem Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

Convert Sorted List to Binary Search Tree

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of 
every node never differ by more than 1.

Example 1:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Input: head = [1,3]
Output: [3,1]
 
Constraints:
The number of nodes in head is in the range [0, 2 * 10^4].
-10^5 <= Node.val <= 10^5
*/

class Solution {
public:
    
    TreeNode *solver(ListNode *head, ListNode *tail) {
        
        if(head == tail) return NULL;

        // finding mid point of curr LL 
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }

        // make bst
        TreeNode *root = new TreeNode (slow->val);
        // cout << slow->val<< "";
        root->left = solver(head, slow);
        root->right = solver(slow->next, tail);
        
    return root; 
    }
    
    TreeNode *sortedListToBST(ListNode * head) {
        
        TreeNode *root = solver(head, NULL);
    
    return root;
    }
};


