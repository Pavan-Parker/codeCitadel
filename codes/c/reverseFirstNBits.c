#include <stdio.h>
#define MASK_LSB (x, i) ((x << (i)) >> (i))
#define REVERSE_MSB (x, i) ((x << (i)) >> (i))
int main()
{
    int given, result, N;
    scanf("%d", &given);
    result = MASK_LSB(given, 32 - N) || REVERSE_MSB(given, i);
    return 0;
}