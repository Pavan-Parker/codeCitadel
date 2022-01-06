#include<stdio.h>

void allocateArray(int*** ptr,int rows,int coloumns)
{
    *ptr=(int **)malloc(sizeof(int *)*rows);
    for(int i=0;i<rows;i++)
    {
        *(*ptr+i)=(int *)malloc(sizeof(int)*coloumns);
    }

}
void allocate1DArray(int** ptr,int length)
{
    *ptr=(int *)(malloc(sizeof(int)*length));
}
void allocate1Dintptrs(int*** ptr,int length)
{
    *ptr=(int **)malloc(sizeof(int *)*length);
}
int main()
{
    int rows=10,coloumns=10;
    int arr[rows][coloumns];
    printf("%d\n",sizeof(arr));
    int *ptr=&(**arr);
    printf("%d %d",ptr,arr);
    int ** myPtr;
    int * ptr1D;
    
    allocateArray(&myPtr,rows,coloumns);
    
    allocate1DArray(&ptr1D,10);
    
    return 0;
}