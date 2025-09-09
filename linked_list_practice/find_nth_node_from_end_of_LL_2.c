/*
Find	n th 	node	from	the	end	of	a	Linked	List.

Method :(Use two pointers)

Efficient	Approach:	Use	two	pointers	pNthNode	and	pTemp.	Initially,	both	point
to	head	node	of	the	list.	pNthNode	starts	moving	only	after	pTemp	has	made	n	moves.
From	 there	 both	 move	 forward	 until	 pTemp	 reaches	 the	 end	 of	 the	 list.	 As	 a	 result	 pNthNode
points	to	n th 	node	from	the	end	of	the	linked	list.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct NODE
{
	int data;
	struct NODE * next;
};

struct NODE* find_nth_node_from_end(struct NODE* head, unsigned int n){
  struct NODE* pNthNode = head,*pTemp = head;
  unsigned int index = 0;

  if(head==NULL)
  return NULL;

  for(index = 0 ;index < n ;index++){
    if(pTemp)
      pTemp = pTemp->next;
  }

  if(pTemp->next==NULL)
  return NULL;

  while(pTemp->next!=NULL){
    pNthNode = pNthNode->next;
    pTemp = pTemp->next;
  }

  if(pNthNode)
  return pNthNode;

return NULL;
}

void front(struct NODE **head_ref,int data) {

	struct NODE *new_node=(struct NODE *)malloc(sizeof(struct NODE));

	new_node->data=data;
	new_node->next=*head_ref;

	*head_ref=new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct NODE *node)
{
    while (node!=NULL)
    {
       printf("%d ", node->data);
       node = node->next;
    }
}


int main(void)
{
	struct NODE *head=NULL,*temp=NULL;

	front(&head,11);
	front(&head,22);
	front(&head,31);
	front(&head,44);
	front(&head,15);
	front(&head,62);
	front(&head,34);
	front(&head,52);
  front(&head,56);
  front(&head,25);
  front(&head,49);

  printf("Linked list created: ");
  printList(head);
  printf("\n");

  temp = find_nth_node_from_end(head,4);

  if(temp != NULL){
    printf("nth Node from end of linked list : ");
    printf("%d\n",temp->data);
  }
  else{
    printf("NULL returned\n");
  }

	return 0;
}
