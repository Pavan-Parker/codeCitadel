#include<stdio.h>
#include<string.h>

/*Truth always wins*/
void main()
{
	char given[9999]="5110115019112351112179911801792340161171141148";	
	int givenLength=strlen(given);
	int i=0,j=0,k=0;
	int temp=0,count=0;
	for(i=givenLength-1;i>=0;)
	{
		temp=0;
		count=0;

		if((given[i]-'0')==1){count=3;}
		else{count=2;}
		for (j=0; j < count; j++)
		{
			temp*=10;
			temp+=(given[i]-'0');
			i--;
		}
		printf("%d %c\n",temp,temp);
		
	}

}
