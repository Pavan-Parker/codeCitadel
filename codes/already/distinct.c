#include <stdio.h>
#include <math.h>
int main() {
	int t,size,diff,req,reqcount,totalcount;
	int done[100];
	int donelen;
	
	int i,j,k,l;
	scanf("%d",&t);
	int a[100];
	for(i=0;i<t;i++)
	{
	    donelen=0;
	    totalcount=0;
	    
	    //SCANNING
	    scanf("%d",&size);
	    
	    for(j=0;j<size;j++)
	    {
	        scanf("%d",&a[j]);
	    }
	    scanf("%d",&diff);
	    
	   //REAL STUFF
	    for(j=0;j<size;j++)
	    {
	        int checkrepeat=0;
	        for(l=0;l<donelen;l++)
	        {
	            if(done[l]==a[j])
	            {
	                checkrepeat=1;
	                break;
	            }
	        }
	        req=a[j]-diff;
	        reqcount=0;
	        if((req>=0)&&(!checkrepeat))
	        {
	            for(k=0;k<size;k++)
	            {
	                if((a[k]==req)&&(k!=j))
	                {
	                    //printf("%d,%d\n",a[j],a[k]);
    	                done[donelen]=a[j];
    	                donelen++;
    	                reqcount++;
    	                break;
    	            }
	           
	            }
	            totalcount+=reqcount;
	        }
	    }
	    printf("%d\n",totalcount);
	}
	return 0;
}
