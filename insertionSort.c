
 #include<stdio.h>
void swap(int *p,int *q)
{
	int temp;
	temp=*p;*p=*q;*q=temp;
}
void insertionSort(int arr[],int len)
{
	int  j;
	int k;
	int temp;
	
	printf("Given: \n");
	for(int i=0;i<len;i++){printf("%d\t",arr[i]);}
	printf("\n");
	
	for(int i=1;i<len;i++)
	{
		j=i;
		while(!(arr[j-1]<=arr[i] || j==0)){j--;}
		if(j!=i)
		{
			temp=arr[i];
			for(k=i-1;k>=j;k--){arr[k+1]=arr[k];}
			arr[j]=temp;
			printf("\n for \ti==> %d\t:",i);
			printf("\n \tj==>%d\t: \n\t",j);
			for(int i=0;i<len;i++){printf("%d\t",arr[i]);}
		}
	}
	printf("\n");

}
int main()
{
    int arr[] = {64,25,32,2,12,12,22,11};
	int len=sizeof(arr)/sizeof(int);
	printf("len: %d\n",len);

	insertionSort(arr,len);
	//len=sizeof(arr)/sizeof(int);
	printf("post len: %d\n",len);

	for(int i=0;i<len;i++){printf("%d\t",arr[i]);}
	printf("\n");
	return 0;
}