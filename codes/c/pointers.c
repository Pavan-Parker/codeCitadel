#include <stdio.h>
#define linebreak() printf("+++++++++++++++++++++++++++++\n")

void increment(int *x)
{
    (*x)++;
}

int main()
{
    linebreak();

    //typecasting pointers

    int a = 1025; // 0x0041
    int *ptr = &a;
    char *ptrChar = (char *)&a;

    // ? ptrChar stepsize is 1 Byte. ? //
    printf("ptr at %p is %d\n", ptr, *ptr);
    printf("ptrChar+0 at %p is %d\n", ptrChar + 0, *ptrChar);
    printf("ptrChar+1 at %p is %d\n", ptrChar + 1, *(ptrChar + 1));
    printf("ptrChar+2 at %p is %d\n", ptrChar + 2, *(ptrChar + 2));
    printf("ptrChar+3 at %p is %d\n", ptrChar + 3, *(ptrChar + 3));
    linebreak();

    // ! ptr as function arguments. ! //

    increment(ptr);
    printf("ptr at %d is %d\n", ptr, *ptr);

    return 0;
}