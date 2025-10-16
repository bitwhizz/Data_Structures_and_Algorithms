/*

find count of an element in a sorted list

Time complexity - o(n)

*/


#include <stdio.h>

int linearSearch(int array[],int size,int x)
{
    int count = 0, index = 0;

    for(index=0; index < size ; index++)
    {
        if(array[index]==x)
            count++;
        else if(array[index]>x)
            break;
    }
    return count;
}


int main(void)
{
    int Sorted_Array[] = {1,1,3,3,5,5,5,5,5,9,9,11};

    int x;
    printf("Enter a number :");
    scanf("%d",&x);

    int count = linearSearch(Sorted_Array,sizeof(Sorted_Array)/sizeof(Sorted_Array[0]),x);
    printf("count of an element %d is %d\n",x,count);
}
