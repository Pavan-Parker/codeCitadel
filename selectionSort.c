#include<stdio.h>
void swap(int *p,int *q)
{
	int temp;
	temp=*p;*p=*q;*q=temp;
}
void selectionSort(int arr[],int len)
{
	int *p,*q,temp,minIndex;
	for(int i=0;i<len;i++)
	{
		minIndex=i;
		for(int j=i+1;j<len;j++){if(arr[minIndex]>arr[j]){minIndex=j;}}
		swap(&(arr[minIndex]),&(arr[i]));
	}
}
int main()
{
    int arr[] = {64, 25, 12, 12,22, 11};
	int len=sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr,len);
	for(int i=0;i<len;i++){printf("%d\t",arr[i]);}
	return 0;
}