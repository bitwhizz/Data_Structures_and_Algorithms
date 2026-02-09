/*
 * hash_lookups.c
 *
 *  Created on: 28-May-2019
 *      Author: saifullab
 */


/*
 * A useful data structure for doing lookups is a hash table. In this problem, you will be
 * imple­menting a hash table with chaining to store the frequency of words in a file.
 * The hash table is implemented as an array of linked lists.
 * The hash function specifies the index of the linked list to follow for a given word.
 * The word can be found by following this linked list. Optionally, the word
 * can be appended to this linked list.

for this problem. You are required to do the following
•	 The function lookup() returns a pointer to the record having the required string.
If not found it returns NULL or optionally creates a new record at the correct location.
Please
complete the rest of the code.
•	 Complete the function cleartable() to reclaim memory. Make sure each call to malloc()
is matched with a free()
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUCKETS 1000
#define MULTIPLIER 31
#define MAX_LEN 2

struct wordrec
{
  char* word;
  unsigned long count;
  struct wordrec* next;
};

/*hash bucket*/
struct wordrec* table[MAX_BUCKETS];

/*
  @function walloc
  @desc     produces a new node
*/
struct wordrec* walloc(const char* str)
{
  struct wordrec* p=(struct wordrec*)malloc(sizeof(struct wordrec));
  if(p!=NULL)
  {
      p->count=0;
      p->word=strdup(str); /*creates a duplicate*/
      p->next=NULL;
  }
  return p;
}

/*
  @function hashstring
  @desc     produces hash code for a string
            multipliers 31,35 have been found to work well
*/
unsigned long hashstring(const char* str)
{
  unsigned long hash=0;

  while(*str)
    {
      hash= hash*MULTIPLIER+*str;
      str++;
    }
  return hash%MAX_BUCKETS;
}


/*
  @function lookup
  @desc     returns a pointer to the word or creates
            it if required
*/
struct wordrec*  lookup(const char* str,int create)
{
  unsigned long hash=hashstring(str);/*starting point*/
  struct wordrec* wp=table[hash];

  struct wordrec* curr=NULL;

  /*TODO: write code to
  follow the linked list to find str
  if found return pointer*/

  for(curr=wp;curr!=NULL;curr=curr->next){

	  if(strcmp(curr->word,str)==0){//found word
		  curr->count++;
		  return curr;
	  }
  }

  /*if not found and create specified*/
   if(create)
    {
      /*TODO:write code to create new node
      update linked list*/
	   curr=(struct wordrec*)malloc(sizeof(struct wordrec));

	   curr->word=strdup(str); /*creates a duplicate*/
	   curr->count=1;

	   curr->next=table[hash];
	   table[hash]=curr;
    }
  return curr;
}

/*
  @function cleartable()
  @desc     reclaims memory
*/
void cleartable()
{
  struct wordrec* wp=NULL,*p=NULL;
  int i=0;
  /*TODO: write code to
    reclaim memory
  */

  for(i=0;i<MAX_BUCKETS;i++){
	  wp=table[i];

	  while(wp){
		  p=wp;
		  wp=wp->next;

		  free(p->word);
		  free(p);
	  }
  }
}

int main(int argc,char* argv[])
{
  char  word[1024]; /*big enough*/

  struct wordrec* wp=NULL;
  int i=0;

  memset(table,0,sizeof(table));

  	strcpy(word,"hello");
    wp=lookup(word,1); /*create if doesn't exist*/

  	strcpy(word,"hello");
    wp=lookup(word,1); /*create if doesn't exist*/

  	strcpy(word,"hello");
    wp=lookup(word,1); /*create if doesn't exist*/

  	strcpy(word,"hello");
    wp=lookup(word,1); /*create if doesn't exist*/

  	strcpy(word,"hello");
    wp=lookup(word,1); /*create if doesn't exist*/

  	strcpy(word,"world");
    wp=lookup(word,1); /*create if doesn't exist*/

  	strcpy(word,"world");
    wp=lookup(word,1); /*create if doesn't exist*/

  	strcpy(word,"world");
    wp=lookup(word,1); /*create if doesn't exist*/

  /*
    print all words have frequency>MAX_LEN
   */
  for(i=0;i<MAX_BUCKETS;i++)
    {
		  for(wp=table[i];wp!=NULL;wp=wp->next)
		{
		  if(wp->count>0)
			{
			  printf("%s-->%ld\n",wp->word,wp->count);
			}
		}
    }

  cleartable();
  return 0;
}
