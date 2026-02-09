/*
 * double_hashing_technique.c
 *
 *  Created on: 28-Dec-2019
 *      Author: saif
 */

/*
 *
 * Closed Hashing - Double Hashing
 *
 * Double hashing is a collision resolving technique in Open Addressed Hash tables.
    Double hashing is popular hashing technique where the interval between probes is calculated by another hash function.
    It avoids hash collision (two or more data with same hash value).
 *
 *
 ***Double hashing is a probing method that probes according to a
 * constant multiples with another hash function.
 *
 * Double hashing reduces clustering in a better way.
 * The increments for probing sequence are computed by using seconf hash function.
 * 
 *  Double hashing can be done using :
    (hash1(key) + i * hash2(key)) % TABLE_SIZE
    Here hash1() and hash2() are hash functions and TABLE_SIZE
    is size of hash table.
    (We repeat by increasing i when collision occurs)

* we first probe the location hash1(key) . if location is occupied , we probe the location
* hash1(key) + has2(key) , hash1(key)+2*hash2(key) , ...

* Hash Function :
                        hash1(key) = key % 11
                        hash2(key) = 7 - (key % 7)
 */

  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  int tableSz = 0, totElements = 0, subHash = 0;
  struct node *hashBucket = NULL;

  struct node {
        int age, key;
        char name[100];
        int marker;
  };

  void insertIntoHashTable(int key, char *name, int age) {
        /* 1st hashing - finding hash index */
        int hashInd = key % tableSz, hashVal;
        /* 2nd hashing - no of buckets to skip while probing */
        hashVal = subHash - (key % subHash);
        if (tableSz == totElements) {
                printf("Can't perform Insertion..Hash Table is full!!");
                return;
        }
        /* linear probing */
        while (hashBucket[hashInd].marker == 1) {
                hashInd = (hashInd + hashVal)%tableSz;
        }
        hashBucket[hashInd].key = key;
        hashBucket[hashInd].age = age;
        strcpy(hashBucket[hashInd].name, name);
        hashBucket[hashInd].marker = 1;
        totElements++;
        return;
  }

  void deleteFromHashTable(int key) {
        int hashInd = key % tableSz, count = 0, flag = 0, hashVal;

        hashVal = subHash - (key % subHash);
        
        if (totElements == 0) {
                printf("Hash Table is Empty!!\n");
                return;
        }

        while (hashBucket[hashInd].marker != 0 && count <= tableSz) {
                if (hashBucket[hashInd].key == key) {
                        hashBucket[hashInd].key = 0;
                        hashBucket[hashInd].marker = -1;
                        hashBucket[hashInd].age = 0;
                        strcpy(hashBucket[hashInd].name, "\0");
                        totElements--;
                        flag = 1;
                        break;
                }
                hashInd = (hashInd + hashVal)%tableSz;
                count++;
        }

        if (flag)
                printf("Given data deleted from Hash Table\n");
        else
                printf("Given data is not available in Hash Table\n");

        return;
  }

  void searchData(int key) {
        int hashInd = key % tableSz, flag = 0, count = 0, hashVal = 0;

        hashVal = subHash - (key % subHash);

        if (totElements == 0) {
                printf("Hash Table is Empty!!");
                return;
        }
        while (hashBucket[hashInd].marker != 0 && count <= tableSz) {
                if (hashBucket[hashInd].key == key) {
                        printf("Voter ID : %d\n", hashBucket[hashInd].key);
                        printf("Name     : %s\n", hashBucket[hashInd].name);
                        printf("Age      : %d\n", hashBucket[hashInd].age);
                        flag = 1;
                        break;
                }
                hashInd = (hashInd + hashVal) % tableSz;
        }

        if (!flag)
                printf("Given data is not present in hash table\n");
        return;
  }

  void display() {
        int i;
        if (totElements == 0) {
                printf("Hash Table is Empty!!\n");
                return;
        }
        printf("Voter ID     Name           Age    Index \n");
        printf("-----------------------------------------\n");
        for (i = 0; i < tableSz; i++) {
                if (hashBucket[i].marker == 1) {
                        printf("%-13d", hashBucket[i].key);
                        printf("%-15s", hashBucket[i].name);
                        printf("%-7d", hashBucket[i].age);
                        printf("%d\n", i);
                }
        }
        printf("\n");
        return;
  }

  int main() {
        int key, age, ch, i, flag = 0;
        char name[100];
        printf("Enter the no of elements:");
        scanf("%d", &tableSz);

        //check to take table
        while (1) {
                for (i = 2; i < tableSz; i++) {
                        if (tableSz % i == 0) {
                                flag = 1;
                                break;
                        }
                }
                if (!flag && tableSz > 2)
                        break;
                flag = 0;
                tableSz++;
        }
        /* calculating sub-hash value */
        subHash = (tableSz % 2 == 0) ? tableSz / 2 : (tableSz + 1) / 2;

        /* allocating memory for hash bucket */
        hashBucket = (struct node *)calloc(tableSz, sizeof(struct node));

        while (1) {
                printf("1. Insertion\t2. Deletion\n");
                printf("3. Searching\t4. Display\n");
                printf("5. Exit\nEnter ur choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter the key value:");
                                scanf("%d", &key);
                                getchar();
                                printf("Name:");
                                fgets(name, 100, stdin);
                                name[strlen(name) - 1] = '\0';
                                printf("Age:");
                                scanf("%d", &age);
                                insertIntoHashTable(key, name, age);
                                break;
                        case 2:
                                printf("Enter the key value:");
                                scanf("%d", &key);
                                deleteFromHashTable(key);
                                break;
                        case 3:
                                printf("Enter the key value:");
                                scanf("%d", &key);
                                searchData(key);
                                break;
                        case 4:
                                display();
                                break;
                        case 5:
                                exit(0);
                        default:
                                printf("U have entered wrong Option!!\n");
                                break;
                }
        }
        return 0;
  }

/*
  A good second Hash function is:

      It must never evaluate to zero
      Must make sure that all cells can be probed
*/

/*
/*

saif@saif-Inspiron-5547:~/programmer/Data_Structures_and_Algorithms $ ./exe
Enter the no of elements:11
1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:1
Enter the key value:14
Name:dilla
Age:45
1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:1
Enter the key value:25
Name:kavi
Age:12
1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:1
Enter the key value:91
Name:fsdad
Age:20
1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:1
Enter the key value:25
Name:svhj 
Age:56
1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:1
Enter the key value:58
Name:chavi
Age:44
1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:1
Enter the key value:15
Name:bondu
Age:8
1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:1
Enter the key value:66
Name:hhsg
Age:45
1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:1
Enter the key value:73 
Name:fgds
Age:32
1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:4
Voter ID     Name           Age    Index 
-----------------------------------------
66           hhsg           45     0
73           fgds           32     1
91           fsdad           20     2
14           dilla          45     3
15           bondu          8      4
58           chavi          44     5
25           svhj           56     7
25           kavi           12     8

1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:1
Enter the key value:47
Name:djldfj
Age:67
1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:1
Enter the key value:43
Name:gjhh
Age:34
1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:1
Enter the key value:22
Name:njhkh 
Age:29
1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:4
Voter ID     Name           Age    Index 
-----------------------------------------
66           hhsg           45     0
73           fgds           32     1
91           fsdad           20     2
14           dilla          45     3
15           bondu          8      4
58           chavi          44     5
47           djldfj         67     6
25           svhj           56     7
25           kavi           12     8
22           njhkh          29     9
43           gjhh           34     10

1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:1
Enter the key value:64
Name:uggd
Age:76
Can't perform Insertion..Hash Table is full!!1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit
Enter ur choice:4
Voter ID     Name           Age    Index 
-----------------------------------------
66           hhsg           45     0
73           fgds           32     1
91           fsdad           20     2
14           dilla          45     3
15           bondu          8      4
58           chavi          44     5
47           djldfj         67     6
25           svhj           56     7
25           kavi           12     8
22           njhkh          29     9
43           gjhh           34     10

1. Insertion	2. Deletion
3. Searching	4. Display
5. Exit

*/
