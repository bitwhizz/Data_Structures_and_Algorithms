/*
 * first_repeated_char_hash.c
 *
 *  Created on: 03-Jun-2019
 *      Author: saifullab
 */

/*

  Creating	a	huge	array	and
  storing	 the	 counters	 is	 not	 possible.
  That	 means	 there	 are	 a	 set	 of	 universal	 keys	 and	 limited
  locations	 in	 the	 memory.


  As	a	result	using
  simple	arrays	is	not	the	correct	choice	for	solving	the	problems
  where	the	possible	keys	are	very
  big.	The	process	of	mapping	the	keys	to	locations	is	called	hashing.

 */

#include <stdio.h>
#include <string.h>

#define ASCII_MAX	256		//for simplicity take ASCII max

char first_repeated_char(char *string){

	int i=0,len=strlen(string);

	int count[ASCII_MAX];  //additional array

	for(i=0;i<ASCII_MAX;i++)
		count[i]=0;

	for(i=0;i<len;i++){

		if(count[(int)string[i]]==1){
			printf("%c\n",string[i]);
			break;
		}
		else count[(int)string[i]]++;
	}

	if(len==i)
	{
		printf("No repeated characters");
	}

	return 0;
}

int main()
{

	first_repeated_char("SAIF ULLA BAIG");

	first_repeated_char("HAPPY");
	return 0;
}
