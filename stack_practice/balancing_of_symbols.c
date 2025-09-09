/*

Problem-1  Discuss	how	stacks	can	be	used	for	checking	balancing	of	symbols.
Solution:	Stacks	can	be	used	to	check	whether	the	given	expression	has	balanced	symbols.	This
algorithm	is	very	useful	in	compilers.	Each	time	the	parser	reads	one	character	at	a	time.	If	the
character	is	an	opening	delimiter	such	as	(,	{,	or	[-	then	it	is	written	to	the	stack.	When	a	closing
delimiter	is	encountered	like	),	},	or	]-the	stack	is	popped.
The	 opening	 and	 closing	 delimiters	 are	 then	 compared.	 If	 they	 match,	 the	 parsing	 of	 the	 string
continues.	If	they	do	not	match,	the	parser	indicates	that	there	is	an	error	on	the	line.	A	linear-time
O(n)	algorithm	based	on	stack	can	be	given	as:
Algorithm:
a) Create	a	stack.
b) while	(end	of	input	is	not	reached)	{
1) If	the	character	read	is	not	a	symbol	to	be	balanced,	ignore	it.
2) If	the	character	is	an	opening	symbol	like	(,	[,	{,	push	it	onto	the	stack
3) If	 it	 is	 a	 closing	 symbol	 like	 ),],},	 then	 if	 the	 stack	 is	 empty	 report	 an
error.	Otherwise	pop	the	stack.
4) If	the	symbol	popped	is	not	the	corresponding	opening	symbol,	report	an
error.
}
c) At	end	of	input,	if	the	stack	is	not	empty	report	an	error

*/

#include<stdio.h>
#include<stdlib.h>

struct NODE{
	char delimeter;
	struct NODE* next;
};


/* Given a reference (pointer to pointer) to the head of a list and
   an int, inserts a new node on the front of the list. */
void push(struct NODE** head_ref, char ch_delimeter)
{
    struct NODE* new_node = (struct NODE*) malloc(sizeof(struct NODE));

	new_node->delimeter=ch_delimeter;

	//assigning the address of the previous head to new node
	new_node->next=(*head_ref);

	//move the head to point to the new node
	(*head_ref)=new_node;
}

void pop(struct NODE** head_ref)
{
	struct NODE *temp=*head_ref;

	*head_ref=temp->next;

	free(temp);
}

char peek(struct NODE* head_ref){
	struct NODE *temp=head_ref;

	if(temp!=NULL)
		return temp->delimeter;
	else
		return 0;
}

int main(){

	struct NODE *top=NULL;
  char expression[] = "[(A+B)+(C+D)]";
  unsigned int index = 0;
  unsigned int push_count =0, pop_count = 0;

  while(expression[index]!= '\0'){

    if((expression[index] == '[') || (expression[index] == '(') || (expression[index] == '{')){
      push(&top,expression[index]);
      printf(" %c ",peek(top));
      push_count++;
    }

    if((expression[index] == ']') || (expression[index] == ')') || (expression[index] == '}')){
          printf(" %c ",expression[index]);

          if((expression[index] == ']') && (peek(top) == '[')){
              pop(&top);
          }
          else if ((expression[index] == ')') && (peek(top) == '(')) {
              pop(&top);
          }
          else if ((expression[index] == '}') && (peek(top) == '{')) {
              pop(&top);
          }
          else{
              printf("\nDelimeters are not in order the expression\n");
          }
      pop_count++;
    }
    index++;
  }

  if((top == NULL) && (peek(top) == 0) && (push_count == pop_count))
  {
    printf("\nDelimeters are balanced in the expression\n");
  }
  else{
      printf("\nDelimeters are not balanced in the expression\n");
  }

return 0;
}
