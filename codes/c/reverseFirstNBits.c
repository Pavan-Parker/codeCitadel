#include <stdio.h>
#define MASK_LSB (x, i)((x << (i)) >> (i))
#define MASK_MSB (x, i)((x >> (i)) << (i))
int reverseNBits(int x, int N)
{
    int lsb = MASK_LSB(x, 32 - N);
    int msb = MASK_MSB(x, N);

    int result_msb = msb;
    int count = sizeof(int) * 8 - 1;
    while(msb)
    {
        
    }
}
int main()
{
    int given, result, N;
    scanf("%d", &given);
    return 0;
}