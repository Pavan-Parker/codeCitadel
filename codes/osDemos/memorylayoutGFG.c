#include <stdio.h>
 
int global; /* Uninitialized variable stored in bss*/
 
int main(void)
{
    static int local; /* Uninitialized static variable stored in bss */
    return 0;
}
