/*

find count of an element in a sorted list

Time complexity - o(logn)

*/



#include<stdio.h>
#include <stdbool.h>


int BinarySearch(int A[],int n,int x,bool searchfirst)
{
    int low = 0, high = n-1,result = -1;

    while(low<=high){
        int mid = (low + high)/2;

        if(A[mid]==x)
        {
            result = mid;

            if(searchfirst)
                high = mid -1;      //Go on Searching towards left (lower indices)
            else
                low = mid + 1;      //Go on searching towards right (higher indices)
        }
        else if(x < A[mid])
            high = mid -1;
        else
            low = mid + 1;
    }
    return result;
}

int main()
{
    int Sorted_Array[] = {1,1,3,3,5,5,5,5,5,9,9,11};
    int x;
    printf("Enter a number : ");
    scanf("%d",&x);

    int firstIndex = BinarySearch(Sorted_Array,sizeof(Sorted_Array)/sizeof(Sorted_Array[0]),x,true);

    if(firstIndex == -1)
    {
        printf("count of %d is %d\n",x,0);
    }
    else{
        int lastIndex = BinarySearch(Sorted_Array,sizeof(Sorted_Array)/sizeof(Sorted_Array[0]),x,false);
        printf("count of %d is %d\n",x,lastIndex - firstIndex + 1);
    }
}

