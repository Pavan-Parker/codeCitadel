#include<stdio.h>
void swap(int *p,int *q)
{
	int temp;
	temp=*p;*p=*q;*q=temp;
}
void insertionSort(int arr[],int len)
{
	int  j=0;
	int k=0;
	
	printf("Given: \n");
	for(int i=0;i<len;i++){printf("%d\t",arr[i]);}
	printf("\n");
	
	for(int i=1;i<len;i++)
	{
		j=i-1;
		while(!(arr[j]<=arr[i] || j==0)){j--;}
		for(k=i;k>=0 || k>=j;k--){swap(&arr[k],&arr[k-1]);}
		printf("\n for i==> %d\t:",i);
		for(int i=0;i<len;i++){printf("%d\t",arr[i]);}
	}
	printf("\n");

}
int main()
{
    int arr[] = {64,25,12,12,22,11};
	int len=sizeof(arr)/sizeof(int);
	printf("len: %d\n",len);

	insertionSort(arr,len);
	//len=sizeof(arr)/sizeof(int);
	printf("post len: %d\n",len);

	for(int i=0;i<len;i++){printf("%d\t",arr[i]);}
	printf("\n");
	return 0;
}