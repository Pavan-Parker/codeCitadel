#include <stdio.h>
#define MASK_LSB (x, i)((x << (i)) >> (i))
#define MASK_MSB (x, i)((x >> (i)) << (i))
int reverseNBits(int x, int N)
{
    /*
     * 1. Mask and save lsb for later.
     * 2. Mask msb for operation.
     * 3. Shift MSB to rightmost.
     * 4, Copy the last bit of msb to last bit of result.
     * 5. Right shift MSB and left shift result by one.
     * 6. 
     */
    int lsb = MASK_LSB(x, 32 - N);
    int msb = MASK_MSB(x, N);

    int result_msb = msb;
    int count = sizeof(int) * 8 - 1;

    msb >>= 32 - N;

    while (msb)
    {

    }
}
int main()
{
    int given, result, N;
    scanf("%d", &given);
    return 0;
}