/*
To insert data into binary search tree , first we need to find the location for that element.
we can find the location of insertion by the following the same mechanism s that of find operation.
while finding the location , if the data is already there we can simply neglect and come out.
Otherwise , insert the data at last location on the path traversed.

Iterative approach :

* Use a loop to find the correct position iteratively.
* insert the new node when a null position is found.

*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct BinarySearchTreeNode{
    int data;
    struct BinarySearchTreeNode *left;
    struct BinarySearchTreeNode *right;
};


struct Qnode{
    struct BinarySearchTreeNode* treeNode;
	struct Qnode* next;
};

struct Queue{
	struct Qnode* front,*rear;
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

struct Qnode* new_node(struct BinarySearchTreeNode* treeNode){
    struct Qnode *temp = (struct Qnode*)malloc(sizeof(struct Qnode));
    temp->treeNode = treeNode;
    temp->next = NULL;
    return temp;
}

struct Queue *createQueue(){
	struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=q->rear=NULL;
	return q;
}

bool isEmptyQueue(struct Queue *q)
{
    //if the condition is true then 1 is returned else 0 is returned
    return (q->front == NULL);
}

void enqueue(struct Queue* q,struct BinarySearchTreeNode* treeNode){

	struct Qnode* temp=new_node(treeNode);

	if(q->rear==NULL)
	{
		q->rear=q->front=temp;
		return;
	}

	q->rear->next=temp;
	q->rear=temp;
}

struct Qnode* dequeue(struct Queue*q){

	if(q->front==NULL)
	   return NULL;

	struct Qnode*temp=q->front;
	q->front=q->front->next;

	if(q->front==NULL)
		q->rear=NULL;

	return temp;
}

void DeleteQueue(struct Queue* q)
{
    struct Qnode* temp;
    while(q->front!=NULL){
        temp = q->front;
        q->front=q->front->next;
        free(temp);
    }
    free(q);
}

// Returns the (potentially updated) root of the BST
struct BinarySearchTreeNode* InsertInBST(struct BinarySearchTreeNode* root, int data) 
{
    // 1. Create the new node up front
    struct BinarySearchTreeNode* newNode = (struct BinarySearchTreeNode*)malloc(sizeof(struct BinarySearchTreeNode));
    if (newNode == NULL) {
        printf("Memory Error\n");
        return root; // Return unchanged tree if malloc fails
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    // 2. Handle the empty tree case
    if (root == NULL) {
        return newNode; 
    }

    // 3. Traverse the tree with two pointers
    struct BinarySearchTreeNode* current = root;
    struct BinarySearchTreeNode* parent = NULL;

    while (current != NULL) {
        parent = current; // Keep track of the current node before moving down
        
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else {
            // Duplicate data found; handle according to your requirements
            free(newNode); // Deallocate since we aren't inserting it
            return root; 
        }
    }

    // 4. Link the parent to the new node
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

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

    InsertInBST(root,8);

    printf("Inserted element in binary search tree\n");
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
tree node  r: 740010 -> 7
tree node  rl: 740030 -> 4 
tree node  rll: 740070 -> 2
tree node  rlr: 740090 -> 5
tree node  rr: 740050 -> 9
Inserted element in binary search tree
Nodes of the tree would be visited in LDR order : 
740070 -> 2
740030 -> 4
740090 -> 5
740010 -> 7
7410c0 -> 8
740050 -> 9

   Binary search tree

                  7
             /         \
            4             8
          /   \         /    \
        2     5         9      NULL
      /  \   /  \      /  \
  NULL NULL NULL NULL NULL NULL 


*/
