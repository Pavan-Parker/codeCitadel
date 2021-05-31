#include<stdio.h>
#include <stdlib.h>
// #define swap(a) ((a&0xF0)>>4) | ((a&0x0F)<<4)
// int swap(int a)
// {
//     int higherNibble= 0xF0;
//     int lowerNibble= 0xF;
//     int copyOfHigherNibble=(a&higherNibble)>>4;
//     int copyOfLowerNibble=(a&lowerNibble)<<4;
//     return copyOfHigherNibble | copyOfLowerNibble;
// }
int main()
{
    int n;
    scanf("%d",&n);
    int** ptr=(int**)malloc(sizeof(int*)*n);

    for(int i=0;i<n;i++)
    {
        *ptr=(int *)malloc(sizeof(int)*n);
    }

    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
            scanf("%d",(*(ptr+i)+j));
        }
    }


    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
            printf("%d",*(*(ptr+i)+j));
        }
    }
    printf("\ndone\n");
    
    int temp=0;
    for(int i=0;i<n;i++)
    {

        for(int j=0;j<i;j++)
        {
            temp=ptr[i-j][i];
            ptr[i-j][i]=ptr[i][i-j];
            ptr[i][i-j]=temp;
        }
    }
    printf("\nAfterTranspose\n");


    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
            printf("%d",*(*(ptr+i)+j));
        }
    }
    printf("\ndone\n");

    
    // printf("%x",swap(0xAB));
    return 0;
}