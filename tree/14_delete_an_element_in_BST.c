/*
 *  Created on: 30 june 2026
 *      Author: saif
 * 
Delete a node from a binary Search tree.

Deletion in BST involves three cases:

case 1 . Node with no childeren : Simply remove the node.

case 2. Node with one Child. Remove the node and replace it with its child.

case 3. Node with two children : Find the in order successor (smallest node in the right subtree) or
        in order predecessor (largest node in the left subtree), replace the node with it, and delete the successor / predecessor.

Constraints : 
    * Ensure the tree is correctly restructured if the root node is deleted.
    * Make sure the tree remains a valid BST after deletion.

*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct BinarySearchTreeNode{
    int data;
    struct BinarySearchTreeNode *left;
    struct BinarySearchTreeNode *right;
};


/* createnode() allocates a new node with the given data and NULL left and
   right pointers. */

struct BinarySearchTreeNode* createnode(int data)
{
  // Allocate memory for new node
  struct BinarySearchTreeNode* newNode = (struct BinarySearchTreeNode*)malloc(sizeof(struct BinarySearchTreeNode));

  if (newNode == NULL)
  {
    perror("Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  // Assign data to this node
  newNode->data = data;

  // Initialize left and right children as NULL
  newNode->left = NULL;
  newNode->right = NULL;

  return(newNode);
}

struct BinarySearchTreeNode* deleteNode(struct BinarySearchTreeNode* root, int value)
{
    struct BinarySearchTreeNode* current = root;
    struct BinarySearchTreeNode* parent = NULL;

    //Step 1: Search for the node to be deleted and its parent
    while(current != NULL && current->data != value)
    {
      parent = current;
      if(value < current->data){
        current = current->left;
      }
      else{
        current = current->right;
      }
    }

    //If the value wasn't found in the tree , return unchanged root
    if(current == NULL){
      return root;
    }

    //Step 2: Handle case 3 first(node has two children)
    if(current->left != NULL && current->right != NULL)
    {
      //Find the in order successor and its parent
      struct BinarySearchTreeNode* successorParent = current;
      struct BinarySearchTreeNode* successor = current->right;

      while(successor->left != NULL)
      {
        successorParent = successor;
        successor = successor->left;
      }

      //copy successor's data to the current node
      current->data = successor->data;

      //Now shift out targets : we actually need to deleate the successor node
      parent = successorParent;
      current = successor;
    }

    //Step 3 : Handle case 1 and case 2 (Node has 0 or 1 child)
    struct BinarySearchTreeNode* child = (current->left != NULL) ? current->left : current->right;

    //If the node to be dleted is the root node itself
    if(parent == NULL)
    {
      free(current);
      return child; // The child becomes the new root
    }

    //Link the parent node directly to the child node
    if(current == parent->left)
    {
      parent->left = child;
    }
    else{
      parent->right = child;
    }

    free(current);
    return root;
}
/*************************for verification only **********************************/
struct StackNode{
    struct BinarySearchTreeNode* treeNode;
	  struct StackNode* next;
};

struct StackNode* createStackNode(struct BinarySearchTreeNode* treeNode)
{
  struct StackNode* newStackNode = (struct StackNode*)malloc(sizeof(struct StackNode));

  if(newStackNode == NULL)
  {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }

  newStackNode->treeNode = treeNode;
  newStackNode->next = NULL;
  return newStackNode;
}

/* Given a reference (pointer to pointer) to the head of a list and
   an int, inserts a new node on the front of the list. */
void push(struct StackNode** head_ref, struct BinarySearchTreeNode* treeNode)
{
    struct StackNode* new_node = createStackNode(treeNode);

	//assigning the address of the previous head to new node
	new_node->next=(*head_ref);

	//move the head to point to the new node
	(*head_ref) = new_node;
}

int isEmpty(struct StackNode* head_ref)
{
  return (head_ref == NULL);
}

struct BinarySearchTreeNode* pop(struct StackNode** head_ref){

  if(isEmpty(*head_ref))
  {
    return NULL;
  }

  struct StackNode *temp = *head_ref;
  struct BinarySearchTreeNode* poppedNode = temp->treeNode;

  *head_ref = (*head_ref)->next;
  free(temp);

  return poppedNode;
}

void InOrderNonRecursive(struct BinarySearchTreeNode *root)
{   
  if(root == NULL)
  {
    return;
  }

  struct StackNode* stack = NULL;

  printf("Nodes of the tree would be visited in LDR order : \n");
  
  while(1){
    while(root){
          push(&stack,root);
      //if left subtree node exists ,add to stack
          root = root->left;
    }

    if(isEmpty(stack))
      break;

    root = pop(&stack);
      //process current tree node
    printf("%x -> ",root);
    printf("%d\n", root->data);
      //indicates completion of left subtree nodes and current tree node , now got to right subtree nodes.
    root = root->right;
  }

  printf("\n");
  
}


/*****************************************************************************************/


int main()
{
     /*create root tree Node*/
  struct BinarySearchTreeNode *root = createnode(7);

  root->left        = createnode(4);
  root->right       = createnode(9);
  root->left->left  = createnode(2);
  root->left->right  = createnode(5);




  /* Binary search tree

                 7
             /       \
            4          9
          /   \       /  \
        2     5     NULL  NULL
      /  \   /  \   
  NULL NULL NULL NULL  
*/

  printf("tree node  r: %x -> %d\n",root,root->data);
  printf("tree node  rl: %x -> %d \n",root->left,root->left->data);
  printf("tree node  rll: %x -> %d\n",root->left->left,root->left->left->data);
  printf("tree node  rlr: %x -> %d\n",root->left->right,root->left->right->data);
  printf("tree node  rr: %x -> %d\n",root->right,root->right->data);


  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right->left  = NULL;
  root->left->right->right  = NULL;
  root->right->left =  NULL;
  root->right->right = NULL;

    deleteNode(root,4);

    printf("deleted element in binary search tree\n");
  //getchar();

    InOrderNonRecursive(root);

  free(root->left->right);
  free(root->left->left);
  free(root->right);
  free(root->left);
  free(root);

  return 0;
}


/*
tree node  r: 90f010 -> 7
tree node  rl: 90f030 -> 4 
tree node  rll: 90f070 -> 2
tree node  rlr: 90f090 -> 5
tree node  rr: 90f050 -> 9
deleted element in binary search tree
Nodes of the tree would be visited in LDR order : 
90f070 -> 2
90f030 -> 5
90f010 -> 7
90f050 -> 9

   Binary search tree

                 7
             /       \
            5          9
          /   \       /  \
        2    NULL     NULL  NULL
      /  \     
    NULL NULL  

*/
