(1)  What is the difference between (node == null) and (node->next == null)?

Assuming you are talking about a node of a data structure like linked list , stack or queue etc .
then,

    if(node->next==NULL){} //in c or cpp
    if(node.next==null){} // in java

This statement is used to check whether the current node in the linked list is last node or not .
 i.e. to check whether the element or node is last in the list .
(when to traverse the whole list and to find the last node or say element)

    if(node ==NULL or null){};
    //in c,cpp- NULL and in java null

This condition is used to check 2 cases mainly

To check whether the list is empty or not and to count or display the whole list .

    //if head is the head pointer of the list then to write a function to count the nodes in a list
    int countlist(struct node* head)
    {
    if(head==NULL)
      count=0;
    else
    { while(head!=NULL)
        {
             count++;
             head=head->next;
        }
    }
     return count;
    }

Thus,
node == null comes true meaning the previous node was the last node and currently your pointer is pointing to null

node-> next == null means your pointer is pointing to the last element of list .


(2) Malloc function (dynamic memory allocation) resulting in an error when it is used globally

#include<stdio.h>
#include<string.h>
char *y;
y=(char *)malloc(40); // gives an error here
int main()
{
    strcpy(y,"hello world");
}

You cannot use a function call when initializing a static or global variable. In the following code sequence,
we declare a static variable and then attempt to initialize it using malloc:

static int *pi = malloc(sizeof(int));

This will generate a compile-time error message.

The same thing happens with global variables but can be avoided for static variables by using a separate statement to allocate memory to the variable as follows.
We cannot use a separate assignment statement with global variables because global variables are declared outside of a function and executable code,
such as the assignment statement, must be inside of a function: static int *pi;
pi = malloc(sizeof(int));

From the compiler standpoint, there is a difference between using the initialization operator, =, and using the assignment operator, =.

Right approach:

#include<stdio.h>
#include<string.h>
char *y;
int main()
{
    y=(char *)malloc(40);
    strcpy(y,"hello world");
}
