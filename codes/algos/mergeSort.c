#include<stdio.h>
#include<stdbool.h>

void merge(int arr[],int l,int m,int r)
{
    int i,j,k;
    bool skipI=false,skipJ=false;
    bool minI=false;
    int lenL=m-l+1,lenR=r-m;
    int L[lenL],R[lenR];
    for(k=0;k<lenL;k++){L[k]=arr[k+l];}
    for(k=0;k<lenR;k++){R[k]=arr[k+m+1];}
    printf("Merging: \n");
    printf("(l=%d,r=%d)\t",l,r);
    printf("[");

	for(int i=0;i<lenL;i++){printf("%d ",L[i]);}
    printf("] [");

	for(int i=0;i<lenR;i++){printf("%d ",R[i]);}
    printf("]");
    printf("\n");

    i=0;j=0;
    printf("\n\t\tProcessing:");
    for(k=l;k<=r;k++)
    {
        minI=(L[i]<=R[j])?true:false;
        if(i==lenL) {skipI=true;}
        if(j==lenR) {skipJ=true;}
        if(skipJ ||   minI )    {arr[k]=L[i];i++;}
        else if(skipI || !(minI))    {arr[k]=R[j];j++;}
        printf("\n\t\t");

        printf("[");
        for(int i=l;i<=k;i++){printf("%d\t",arr[i]);}
        printf("]");
        printf("\t skipI:%s, skipJ:%s",skipI?"true":"false",skipJ?"true":"false");
        printf("\n");   
    }
    printf("\n");
    printf("Returned: \n");
    printf("(l=%d,r=%d)\t",l,r);
    printf("[");
	for(int i=l;i<=r;i++){printf("%d\t",arr[i]);}
    printf("]");
	printf("\n");

}
void mergeSort(int arr[],int l,int r)
{
	int m=l+(r-l)/2;
	printf("Calling: \n");
    printf("(l=%d,r=%d)\t",l,r);

	for(int i=l;i<=r;i++){printf("%d\t",arr[i]);}
    printf("\n");

    if(r>l)
    {
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

int main()
{
    int arr[] = {64,25,32,2,12,12,22,11};
    // int arr[] = {64,25,32,2};

	int len=sizeof(arr)/sizeof(int);
	printf("len: %d\n",len);

    mergeSort(arr,0,len-1);

	//len=sizeof(arr)/sizeof(int);
	for(int i=0;i<len;i++){printf("%d\t",arr[i]);}
	printf("\n");
	return 0;
}