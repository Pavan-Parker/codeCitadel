#include<stdio.h>
#include <stdbool.h>
void swap(int *p,int *q)
{
	int temp;
	temp=*p;*p=*q;*q=temp;
}
void bubbleSort(int arr[],int len)
{
	bool finishFlag=false;
	while(!finishFlag)
	{
		finishFlag=true;
		for(int i=0;i<len-1;i++)
		{
			if(arr[i]>arr[i+1]){swap(&arr[i],&arr[i+1]);finishFlag=false;}
		}
	}
}
int main()
{
    int arr[] = {64, 25, 12, 12,22, 11};
	int len=sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr,len);
	for(int i=0;i<len;i++){printf("%d\t",arr[i]);}
	return 0;
}