/*
There are two singly linked lists in a system.
By some programming error, the end node of one of the linked list got linked to the second list,
 forming an inverted Y shaped list.
 Write a program to get the point where two linked list merge.

 Using Two pointers :

     Initialize two pointers ptr1 and ptr2  at the head1 and  head2.
     Traverse through the lists,one node at a time.
     When ptr1 reaches the end of a list, then redirect it to the head2.
     similarly when ptr2 reaches the end of a list, redirect it the head1.
     Once both of them go through reassigning,hey will be equidistant from
      the collision point
     If at any node ptr1 meets ptr2, then it is the intersection node.
     After second iteration if there is no intersection node it returns NULL.
 */
 /* C Program to remove duplicates from a sorted linked list */
 #include<stdio.h>
 #include<stdlib.h>

 /* Link list node */
 struct Node
 {
     int data;
     struct Node* next;
 };

 // A utility function to return  intersection node
  struct Node* intersectPoint(struct Node* head1,struct Node* head2)
 {
     // Maintaining two pointers ptr1 and ptr2
     // at the head of A and B,
      struct Node* ptr1 = head1;
      struct Node* ptr2 = head2;

     // If any one of head is NULL i.e
     // no Intersection Point
     if (ptr1 == NULL || ptr2 == NULL) {

         return NULL;
     }

     // Traverse through the lists until they
     // reach Intersection node
     while (ptr1 != ptr2) {

         ptr1 = ptr1->next;
         ptr2 = ptr2->next;

         // If at any node ptr1 meets ptr2, then it is
         // intersection node.Return intersection node.

         if (ptr1 == ptr2) {

             return ptr1;
         }
         /* Once both of them go through reassigning,
         they will be equidistant from the collision point.*/

         // When ptr1 reaches the end of a list, then
         // reassign it to the head2.
         if (ptr1 == NULL) {

             ptr1 = head2;
         }
         // When ptr2 reaches the end of a list, then
         // redirect it to the head1.
         if (ptr2 == NULL) {

             ptr2 = head1;
         }
     }

     return ptr1;
 }

 /* UTILITY FUNCTIONS */
 /* Function to insert a node at the beginging of the linked list */
 void push(struct Node** head_ref, int new_data)
 {
     /* allocate node */
     struct Node* new_node =
             (struct Node*) malloc(sizeof(struct Node));

     /* put in the data  */
     new_node->data  = new_data;

     /* link the old list off the new node */
     new_node->next = (*head_ref);

     /* move the head to point to the new node */
     (*head_ref)    = new_node;
 }

 /* Function to print nodes in a given linked list */
 void printList(struct Node *node)
 {
     while (node!=NULL)
     {
        printf("%d ", node->data);
        node = node->next;
     }
 }

 /* Driver program to test above functions*/
 int main()
 {
     /* Start with the empty list */
     struct Node* head1 = NULL;
     struct Node* head2 = NULL;
     struct Node* intersect_node = NULL;

     /*
   Create two linked lists

   1st Linked list is 3->6->9->15->30
   2nd Linked list is 10->15->30

   15 30 are elements in the intersection list
   */

     push(&head1, 8);
     push(&head1, 9);
     push(&head1, 6);

     push(&head2, 30);
     push(&head2, 15);
     push(&head2, 10);
     push(&head2, 20);
     push(&head2, 31);
     push(&head2, 13);

      head1->next->next->next= head2->next->next->next->next;

     printf("\n 1st Linked lists ");
     printList(head1);
     printf("\n");
     printf("\n 2nd Linked lists ");
     printList(head2);
     printf("\n");

     // Find the intersection node of two linked lists
     intersect_node = intersectPoint(head1, head2);

     printf("\n INTERSEPOINT LIST : ");
     printList(intersect_node);
     printf("\n");

     return 0;
 }
