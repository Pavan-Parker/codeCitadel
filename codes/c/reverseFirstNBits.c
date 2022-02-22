#include <stdio.h>
#define MASK_LSB (x, i)((x << (i)) >> (i))
#define MASK_MSB (x, i)((x >> (i)) << (i))
int reverseNBits(int x, int i)
{
    int lsb = MASK_LSB(x, 32 - i);
    int msb = MASK_MSB(x, i);
    
    int result_msb = msb;
    int count = 
}
int main()
{
    int given, result, N;
    scanf("%d", &given);
    return 0;
}