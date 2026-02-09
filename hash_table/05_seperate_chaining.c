/*
 * seperate_chaining.c
 *
 *  Created on: 25-Dec-2019
 *      Author: saif
 */


/*
 *
 *Collision Handling/resolving technique in Hashing
 *
 *Seperate chaning:
 The idea is to make each cell of hash table point to a linked list of records
 that have same hash function value.
  Algorithm to insert a value in separate chaining
Hashtable is an array of pointers. All pointers are initialized to NULL  ( head[ TABLE_SIZE] = NULL)
Step1: Read the value to be inserted
step 2: create a new node using malloc function
step 3: Assign the value read to the data field of newnode (newnode -> data =value)
step 4: compute the index
                                        index = value % TABLE_SIZE
step 5: if head[ index] is NULL then
                                        step 5.1: attach the newnode as first node
step 6: else
                                        step 6.1 : attach the newnode as lastnode
 */
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
//#define NULL (void *)0

struct node
{
    int data;
    struct node *next;
};

struct node *head[TABLE_SIZE]={NULL},*current;

void insert()
{
    int index,key;
    printf("\n enter a value to insert into hash table\n");
    scanf("%d",&key);

    index=key%TABLE_SIZE;

    struct node *newnode=(struct node *)malloc(sizeof(struct node));
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
}

void search()
{
    int key,index;
    printf("\nenter the element to be searched\n");
    scanf("%d",&key);

    index=key%TABLE_SIZE;

    if(head[index] == NULL)
        printf("\n Search element not found\n");
    else
    {
        for(current=head[index];current!=NULL;current=current->next)
        {
            if(current->data == key)
                {
                    printf("search element found\n");
                    break;
                }
        }
        if(current==NULL)
            printf("\n Search element not found\n");

    }
}


void display()
{
    int index;
    for(index=0;index<TABLE_SIZE;index++)
          {
           printf("\nentries at index %d\n",index);
               if(head[index] == NULL)
               {
            	   	printf("No Hash Entry");

               }
               else
               {
                    for(current=head[index];current!=NULL;current=current->next)
                    printf("%d->",current->data);
               }
          }
    return;
}

int main(void)
{
    int opt;
    while(1)
    {
        printf("\nPress 1. Insert\t 2. Display \t3. Search \t4.Exit \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:exit(0);

        }
    }
}

/*
Algorithm to search a value in separate chaining
Hash table is an array of pointers. All pointers are initialized to NULL  ( head[ TABLE_SIZE] = NULL)
Step1: Read the value to be searched
step 2: compute the index
                                       index = value % TABLE_SIZE
step 5: if head[ index] is NULL then print “search element not found” and STOP
step 6: else
                                       step 6.1: store the first node address in pointer current (current = head [ index ])
                                       step 6.2 : if value is equal to data in current then print “search element found” and STOP
                                       step 6.3: else move current to next node ( current = current->next)  and if current != NULL go to step 6.2
step 7: if search element is not found in entire linked list (current is NULL) then print “ search element not found”
*/
