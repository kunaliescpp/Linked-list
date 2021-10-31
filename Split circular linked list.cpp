/*
Problem Link: https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1

Split a Circular Linked List into two halves 

Given a Cirular Linked List of size N, split it into two halves circular lists. If there are odd number of nodes in the 
given circular linked list then out of the resulting two halved lists, first list should have one node more than the second
list. The resultant lists should also be circular lists and not linear lists.

Example 1:
Input: Circular LinkedList: 1->5->7
Output:
1 5
7
 
Example 2:
Input: Circular LinkedList: 2->6->1->5
Output:
2 6
1 5

Constraints:
1 <= N <= 100

/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref){
     Node *fast = head->next;
     Node *slow = head;
     while(fast != head && (fast->next) != head){
         slow = slow->next;
         fast = fast->next->next;
     }
     
    *head1_ref = head;
    *head2_ref = slow->next;
     slow->next = *head1_ref;
     
     Node *curr = *head2_ref;
     while(curr->next != head) curr = curr->next;
      
      curr->next = *head2_ref;
}


