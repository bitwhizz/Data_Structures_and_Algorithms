/*
 * Linear_probing_Open_Addressing.c
 *
 *  Created on: 28-Dec-2019
 *      Author: saif
 */

/*
 * Collision Handling/resolving technique(open addressing) in Hashing
 *
 * In Open Addressing, all elements are stored in the hash table itself.
 *  So at any point, size of the table must be greater than or
 *  equal to the total number of keys
 *
 *   In linear probing, we linearly probe for next slot. For example,
 *   typical gap between two probes is 1 as taken in below example also.
 *   let hash(x) be the slot index computed using hash function and S be the table size

If slot hash(x) % S is full, then we try (hash(x) + 1) % S
If (hash(x) + 1) % S is also full, then we try (hash(x) + 2) % S
If (hash(x) + 2) % S is also full, then we try (hash(x) + 3) % S
 */

#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 20

int hash[TABLE_SIZE]={};
int count;

int CalculateHash(int key)
{
    return key%TABLE_SIZE;
}

void Insert(int element)
{
    if(count==TABLE_SIZE){
        printf("Error.\nTable if FULL\n");
        exit(EXIT_FAILURE);
    }

    int probe=CalculateHash(element);

    while(hash[probe]!=NULL && hash[probe]!=-1)		//elements deleted are marked -1
    {
        probe=(probe+1)%TABLE_SIZE;
    }

    hash[probe]=element;
    count++;
}

int Search(int element)
{
    if(count==0){
        printf("Error.\nTable if EMPTY\n");
        exit(EXIT_FAILURE);
    }
    int probe=CalculateHash(element);
    while(hash[probe]!=0)
    {
        if(hash[probe]==element)
            return probe;
        probe=(probe+1)%TABLE_SIZE;
    }
    printf("\nElement %d not found.\n",element);
    return -1;
}

void Delete(int element)
{
    if(count==0){
        printf("Error.\nTable if EMPTY\n");
        exit(EXIT_FAILURE);
    }
    int loc=Search(element);
    if(loc!=-1)
    {
        hash[loc]=-1;
        count--;
    }
}

void PrintList()
{
    int i;
    for(i=0;i<TABLE_SIZE;i++)
        printf("%d%c",hash[i],' ');
}

int main()
{
    int item;
    printf("Enter Elements to insert in hash table :");
    printf("\nTo STOP, enter 0\n\n");
    do{
        scanf("%d",&item);
        Insert(item);
    }while(item!=0);

    PrintList();

    printf("\nEnter the elements you want to delete :");
    printf("\nTo STOP, enter 0\n\n");
    do
    {
        scanf("%d",&item);
        if(item)
            Delete(item);
    }while(item);

    PrintList();

    printf("\nEnter the elements you want to search :");
    printf("\nTo STOP, enter 0\n\n");
    do
    {
        scanf("%d",&item);
        if(item){
            int loc;
            loc=Search((item));
            if(loc!=-1)
                printf("\nElement %d Found at location %d",item,loc);
        }
    }while(item);

    printf("\nEnter Elements to insert in hash table :");
    printf("\nTo STOP, enter 0\n\n");
    do{
        scanf("%d",&item);
        Insert(item);
    }while(item!=0);

    PrintList();
    return 0;
}

/*
 *
 * Insert(k): Keep probing until an empty slot is found.
 * Once an empty slot is found, insert k.
 *
 *
 *
Search(k): Keep probing until slot’s key doesn’t become equal to k or
 an empty slot is reached.

Delete(k): Delete operation is interesting.
If we simply delete a key, then search may fail.
So slots of deleted keys are marked specially as “deleted”.

 */

/*
 * Clustering: The main problem with linear probing is clustering,
 * many consecutive elements form groups
 * and it starts taking time to find a free slot or to search an element.
 */
