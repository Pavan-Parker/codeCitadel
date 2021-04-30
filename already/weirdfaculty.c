#include<stdio.h>
int main()
{	
	int myResult=0,FriendResult=0;
	int sum,size;
	int i,j,k;
	int v[100];
	scanf("%d",&size);
	for(i=0;i<size;i++){scanf("%d",&v[i]);if(v[i]==0){v[i]=-1;}}
	for(j=0;j<size;j++){sum+=v[j];}
	myResult=0;FriendResult=sum;
	for(k=0;k<size;k++)
	{
		if(k==0 && sum<0){printf("%d\n",k);break;return 0;}
		else{
			myResult+=v[k];FriendResult-=v[k];
			if(myResult>FriendResult){printf("%d\n",k);break;return 0;}
		}
			
	}
	printf("NOT FOUND");
	return 0;
}
