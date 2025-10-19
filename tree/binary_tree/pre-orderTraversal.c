/*
 * new_tree.c
 *
 *  Created on: 19 oct 2025
 *      Author: saif ulla baig

DLR : process the current node data , process left subtree and then process right subtree.

*/


#include <stdio.h>
#include <stdlib.h>


struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct NODE{
    struct BinaryTreeNode* root;
	struct NODE* next;
};

/* newNode() allocates a new node with the given data and NULL left and
   right pointers. */

struct BinaryTreeNode* newNode(int data)
{
  // Allocate memory for new node
  struct BinaryTreeNode* node = (struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));

  // Assign data to this node
  node->data = data;

  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;

  return(node);
}

/* Given a reference (pointer to pointer) to the head of a list and
   an int, inserts a new node on the front of the list. */
void push(struct NODE** head_ref, struct BinaryTreeNode* root)
{
    struct NODE* new_node = (struct NODE*) malloc(sizeof(struct NODE));

    new_node->root = root;
	//assigning the address of the previous head to new node
	new_node->next=(*head_ref);

	//move the head to point to the new node
	(*head_ref) = new_node;
}

struct BinaryTreeNode* pop(struct NODE* head_ref){
	struct NODE *temp=head_ref;

	if(temp!=NULL)
		return temp->root;
	else
		return NULL;
}

/* Function to delete the entire linked list */
void deleteStack(struct NODE** head_ref)
{
   /* deref head_ref to get the real head */
   struct NODE* current = *head_ref;
   struct NODE* next;

   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }

   /* deref head_ref to affect the real head back
      in the caller. */
   *head_ref = NULL;
}

void PreOrderNonRecursive(struct BinaryTreeNode *root)
{   
    struct NODE* head = NULL;

    while(1)
    {
        while(root)
        {
            //Process current node
            printf("%d ",root->data);
            push(&head,root);

            //if left subtree exists , add to stack
            root = root->left;
        }

        if(head == NULL)
        break;

        root = pop(head);
        //indicates completion of left subtree and current node , now go to right subtree.
        root = root->right;
    }
    deleteStack(&head);
}


int main()
{
  /*create root*/
  struct BinaryTreeNode *root = newNode(1);
  /* following is the tree after above statement

        1
      /   \
     NULL  NULL
  */


  root->left        = newNode(2);
  root->right       = newNode(3);
  /* 2 and 3 become left and right children of 1
           1
         /   \
        2      3
     /    \    /  \
    NULL NULL NULL NULL
  */


  root->left->left  = newNode(4);
  /* 4 becomes left child of 2
           1
       /       \
      2          3
    /   \       /  \
   4    NULL  NULL  NULL
  /  \
NULL NULL
*/

  root->left->right  = newNode(5);
  root->right->left  = newNode(6);
  root->right->right = newNode(7);

  /* 4 becomes left child of 2
           1
       /       \
      2          3
    /   \       /  \
   4    5      6    7
*/

  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right->left  = NULL;
  root->left->right->right  = NULL;
  root->right->left->left = NULL;
  root->right->left->right = NULL;
  root->right->right->left = NULL;
  root->right->right->right = NULL;

    PreOrderNonRecursive(root);

  //getchar();

  return 0;
}