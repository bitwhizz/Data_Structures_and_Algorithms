/*
In	binary	search	trees,	all	the	left	subtree	elements	should	be	less	than	root	data	and	all	the	right
subtree	elements	should	be	greater	than	root	data.	This	is	called	binary	search	tree	property.	Note
that,	this	property	should	be	satisfied	at	every	node	in	the	tree.

*   The	left	subtree	of	a	node	contains	only	nodes	with	keys	less	than	the	nodes	key.
*   The	right	subtree	of	a	node	contains	only	nodes	with	keys	greater	than	the	nodes	key.
*   Both	the	left	and	right	subtrees	must	also	be	binary	search	trees.
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

struct BinarySearchTreeNode *Find(struct BinarySearchTreeNode *root,int data){
    if(root == NULL)
        return NULL;

    while(root){
        if(data == root->data)
            return root;
        else if (data > root->data)
            root = root->right;        
        else
            root = root->left;
    }
    return NULL;
}
/*
In	 BSTs,	 the	 minimum	 element	 is	 the	 left-most	 node,	 which	 does	 not	 has	 left	 child.	 In	 the	 BST
below,	the	minimum	element	is	2.
*/
struct BinarySearchTreeNode *FindMin(struct BinarySearchTreeNode *root){
    if(root == NULL)
        return NULL;

    while(root->left != NULL)
            root = root->left;
    
    return root;
}

/*
In	BSTs,	the	maximum	element	is	the	right-most	node,	which	does	not	have	right	child.	In	the	BST
below,	the	maximum	element	is	9.
*/

struct BinarySearchTreeNode *FindMax(struct BinarySearchTreeNode *root){
    if(root == NULL)
        return NULL;

    while(root->right != NULL)
            root = root->right;   

    return root;
}


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

  printf("tree node  r: %x \n",root);
  printf("tree node  rl: %x \n",root->left);
  printf("tree node  rll: %x \n",root->left->left);
  printf("tree node  rlr: %x \n",root->left->right);
  printf("tree node  rr: %x \n",root->right);


  root->left->left->left = NULL;
  root->left->left->right = NULL;
  root->left->right->left  = NULL;
  root->left->right->right  = NULL;
  root->right->left =  NULL;
  root->right->right = NULL;

  if(Find(root,5) != NULL)
  {
    printf("\n the element %d is present in binary search tree \n",5);
    printf("\n the Minimum element %d is present in binary search tree \n",(struct BinarySearchTreeNode *)FindMin(root)->data);
    printf("\n the Maximum element %d is present in binary search tree \n",(struct BinarySearchTreeNode *)FindMax(root)->data);
  }
  else{
     printf("\n the element %d is not present in binary search tree \n",5);   
  }

  //getchar();

  free(root->left->right);
  free(root->left->left);
  free(root->right);
  free(root->left);
  free(root);

  return 0;
}
/*
Important	Notes	on	Binary	Search	Trees

    *Since	 root	 data	 is	 always	 between	 left	 subtree	 data	 and	 right	 subtree	 data,
    performing	inorder	traversal	on	binary	search	tree	produces	a	sorted	list.
    
    *While	 solving	 problems	 on	 binary	 search	 trees,	 first	 we	 process	 left	 subtree,	 then
    root	 data,	 and	 finally	 we	 process	 right	 subtree.	 This	 means,	 depending	 on	 the
    problem,	only	the	intermediate	step	(processing	root	data)	changes	and	we	do	not
    touch	the	first	and	third	steps.
    
    *If	 we	 are	 searching	 for	 an	 element	 and	 if	 the	 left	 subtree	 root	 data	 is	 less	 than	 the
    element	we	want	to	search,	then	skip	it.	The	same	is	the	case	with	the	right	subtree..
    Because	 of	 this,	 binary	 search	 trees	 take	 less	 time	 for	 searching	 an	 element	 than
    regular	binary	trees.	In	other	words,	the	binary	search	trees	consider	either	left	or
    right	subtrees	for	searching	an	element	but	not	both.
    
    *The	 basic	 operations	 that	 can	 be	 performed	 on	 binary	 search	 tree	 (BST)	 are
    insertion	 of	 element,	 deletion	 of	 element,	 and	 searching	 for	 an	 element.	 While
    performing	these	operations	on	BST	the	height	of	the	tree	gets	changed	each	time.
    Hence	there	exists	variations	in	time	complexities	of	best	case,	average	case,	and
    worst	case.
    
    *The	basic	operations	on	a	binary	search	tree	take	time	proportional	to	the	height	of
    the	 tree.	 For	 a	 complete	 binary	 tree	 with	 node	 n,	 such	 operations	 runs	 in	 O(lgn)
    worst-case	time.	If	the	tree	is	a	linear	chain	of	n	nodes	(skew-tree),	however,	the
    same	operations	takes	O(n)	worst-case	time.
*/