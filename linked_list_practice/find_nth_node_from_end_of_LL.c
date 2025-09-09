/*
Find	n th 	node	from	the	end	of	a	Linked	List.

Using lenght of linked list approach :

We can	find	the	length	of	the	linked	list	just	by	starting	at	the	head	node	and	traversing	the	list.
say M is the lenght of linked list we got by traversing.

After	 finding	 the	 length,
compute	M	–	n	+	1	and	with	one	more	scan	we	can	get	the	M	–	n+	1 th 	node	from	the	beginning.

This	solution	needs	two	scans:	one	for	finding	the	length	of	the	list	and	the	other	for	finding	M–n+1 th 	node	from	the	beginning.

Time	Complexity:	Time	for	finding	the	length	+	Time	for	finding	the	M	–	n	+	1 th 	 node	 from	 the
beginning.	 Therefore,	 T(n)	 =	 O(n)	 +	 O(n)	 ≈	 O(n).	 Space	 Complexity:	 O(1).

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
  struct NODE* temp = head;
  unsigned int lenght = 0;
  unsigned int index = 0;

  if(head == NULL){
    return NULL;
  }

  while(temp->next != NULL)
  {
    temp = temp->next;
    lenght++;
  }

  if(n > lenght){
      return NULL;
  }

  temp = head;
  for(index = 1;index < lenght - n + 1;index++){
    temp = temp->next;
  }

  return temp;
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

  printf("Linked list created");
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
