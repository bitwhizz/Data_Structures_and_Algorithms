/*
 * hash_chain_collision_resolution.c
 *
 *  Created on: 03-Jun-2019
 *      Author: saifullab
 */

/*
 * Implement	a	separate	chaining	collision	resolution	technique.
 * Also,	discuss	time complexities	of	each	function
 *
 *To create	a	hash table	of	given	size,	say	n,
 *we	allocate	an	array	of	n/L	(whose	value	is
 *usually	between	5	and	20	pointers	to	list,	initialized	to	NULL.
 *
 *
 *To	perform	Search/Insert/Delete operations,	we	first	compute	the	index
 *of	the	table	from	the	given
 *key	by	using	hash function	and then	do	the	corresponding	operation
 *in	the	linear	list	maintained	at	that	location.
 *
 *To	get	uniform
 * distribution	of	keys	over	a	hash table,	maintain	table	size
 * as	the	prime	number.
 *
 */


#include <stdio.h>
#include <stdlib.h>

#define LOAD_FACTOR 	20		//average keys per slot
//Expected time to insert,delete,search = O(1 + load_factor)

struct ListNode{
	int key;
	int data;
	struct ListNode *next;
};

struct HashTableNode{
	int bcount;				//number elements in block
	struct ListNode *next;
};

struct HashTable{
	int tsize;
	int count;				//number elements in table
	struct HashTableNode **Table;
};

struct HashTable *CreateHashTable(int size){

	struct HashTable *hmain=NULL;

	hmain=(struct HashTable*)malloc(sizeof(struct HashTable));

	if(!hmain)
		return NULL;

	hmain->tsize=size/LOAD_FACTOR;
	hmain->count = 0;
	hmain->Table = (struct HashTableNode**)malloc(sizeof(struct HashTableNode*)* hmain->tsize);

	if(!hmain->Table){
		printf("Memory Error\n");
		return NULL;
	}

	for(int itemp=0;itemp<hmain->tsize;itemp++){
		hmain->Table[itemp]->next= NULL;
		hmain->Table[itemp]->bcount= 0;
	}
	return hmain;
}

int Hash(int data,int size){

	return data%size;
}

int HashSearch(struct HashTable *hmain,int data){
	struct ListNode *temp;
	temp = hmain->Table[Hash(data,hmain->tsize)]->next; //create your own Hash() function
	while(temp){
		if(temp->data == data)
			return 1;
		temp = temp->next;
	}
	return 0;
}

int HashInsert(struct HashTable *hmain,int data){
	int index;
	struct ListNode *temp,*newnode;
	if(HashSearch(hmain,data))
		return 0;
	index=Hash(data,hmain->tsize);			//Assume hash is a built-in function

	temp=hmain->Table[index]->next;
	newnode = (struct ListNode *)malloc(sizeof(struct ListNode));

	if(!newnode){
		printf("out of space\n");
		return -1;
	}

	newnode->key=index;
	newnode->data=data;
	newnode->next=hmain->Table[index]->next;
	hmain->Table[index]->next=newnode;
	hmain->Table[index]->bcount++;
	hmain->count++;

	return 1;
}

int HashDelete(struct HashTable *hmain,int data){
	int index;
	struct ListNode *temp,*prev;

	index=Hash(data,hmain->tsize);			//Assume hash is a built-in function

	for(temp=hmain->Table[index]->next,prev = NULL;temp;prev = temp,temp=temp->next){

		if(temp->data == data){
			if(prev!=NULL)
				prev->next=temp->next;
			free(temp);
			hmain->Table[index]->bcount--;
			hmain->count--;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int opt=0;
	int idata=0;

	struct HashTable *hmain =CreateHashTable(10);

	while(1){

		scanf("%d",&opt);

		if(opt==1){

			scanf("%d",&idata);
			HashInsert(hmain,idata);
			printf("inserted item : %d\n",idata);

		}else if(opt==2){
			scanf("%d",&idata);
			HashDelete(hmain,idata);
			printf("deleted item : %d\n",idata);

		}else if(opt==3){

			scanf("%d",&idata);
			HashSearch(hmain,idata);
			printf("serched element : %d\n",idata);

		}
	}
}
