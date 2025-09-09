/*
Algorithm:
We traverse the link list from head to end.
For every newly encountered element,
we check whether it is in the hash table: if yes, we remove it;
otherwise we put it in the hash table.
*/

/* C Program to remove duplicates from a Unsorted linked list */
#include<stdio.h>
#include<stdlib.h>

/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};

#define TABLE_SIZE 10
//#define NULL (void *)0

struct Node *head[TABLE_SIZE]={NULL};
struct Node *current;

void insert(int key)
{
    int index;
    index=key%TABLE_SIZE;

    struct Node * newnode=(struct Node *)malloc(sizeof(struct Node));

    newnode->data=key;
    newnode->next = NULL;

    if(head[index] == NULL)
        head[index] = newnode;
    else
    {
        current=head[index];
        while(current->next != NULL)
        {
           current=current->next;
        }
        current->next=newnode;
    }
    return;
}

int search(int key)
{
    int index;

    index=key%TABLE_SIZE;

    if(head[index] == NULL){
        return 0;
    }
    else
    {
        for(current=head[index];current!=NULL;current=current->next)
        {
            if(current->data == key)
            {
              return 1;
            }
        }

        if(current==NULL)
            return 0;
    }
return 0;
}

/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

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

/* Function to remove duplicates from a
   unsorted linked list */
void removeDuplicates(struct Node *head_ref)
{
    /* Pick elements one by one */
    struct Node *curr = head_ref;
    struct Node *prev = NULL;

    while (curr != NULL)
    {
        // If current value is seen before
        if (search(curr->data) != 0)
        {
           prev->next = curr->next;
           free(curr);
        }
        else
        {
           insert(curr->data);
           prev = curr;
        }
        curr = prev->next;
    }
}

/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    /* The constructed linked list is:
       10->12->11->11->12->11->10*/
    push(&head, 10);
    push(&head, 12);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);
    push(&head, 12);
    push(&head, 11);
    push(&head, 10);
    push(&head, 44);
    push(&head, 45);
    push(&head, 44);

    printf("\n Linked list before duplicate removal  ");
    printList(head);

    /* Remove duplicates from linked list */
    removeDuplicates(head);

    printf("\n Linked list after duplicate removal ");
    printList(head);
    printf("\n");

    return 0;
}

//Time Complexity: O(n) on average (assuming that hash table access time is O(1) on average).  
