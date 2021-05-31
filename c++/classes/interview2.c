#include<stdio.h>
int swap(int a)
{
    int higherNibble= 0xF0;
    int lowerNibble= 0xF;
    int copyOfHigherNibble=(a&higherNibble)>>4;
    int copyOfLowerNibble=(a&lowerNibble)<<4;
    return copyOfHigherNibble | copyOfLowerNibble;
}
int main()
{
    printf("%x",swap(0xAB));
    return 0;
}