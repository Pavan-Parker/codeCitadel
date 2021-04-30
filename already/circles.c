#include <stdio.h>
#include <math.h>
float getdistance(int x1, int y1,int x2, int y2)
{
    return sqrt((float)(pow(x1-x2,2)+pow(y1-y2,2)));
}
int main() {
	int t,x1,x2,y1,y2,r1,r2;
	int i,j;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
	    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&r1,&r2);
	   // printf("%d %d %d %d %d %d\n",x1,y1,x2,y2,r1,r2,r1+r2);
      //  printf("%f\n",getdistance(x1,y1,x2,y2));
        if((r1+r2)>=getdistance(x1,y1,x2,y2)) {printf("1\n");}
        else{printf("0\n");}
	}
	return 0;
}
