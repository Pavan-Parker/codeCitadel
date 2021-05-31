#include<stdio.h>

void allocateArray(int** ptr,int rows,int coloumns)
{
    int** temp=ptr;

    for(int i=0;i<rows;i++)
    {
        *temp=(int *)malloc(sizeof(int)*coloumns);
        temp++;
    }

}

int main()
{
    int rows=10,coloumns=10;
    int arr[rows][coloumns];
    printf("%d\n",sizeof(arr));
    int *ptr=&(**arr);
    printf("%d %d",ptr,arr);
    int ** myPtr;

    allocateArray(myPtr,rows,coloumns);

    return 0;
}