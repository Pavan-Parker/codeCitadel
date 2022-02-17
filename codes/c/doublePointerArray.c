#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLUMNS 9

int main()
{
    // Allocation of 10 * 10 array
    int **p = (int **)malloc(ROWS * sizeof(int *));
    for (int i = 0; i < COLUMNS; i++)
        p[i] = malloc(COLUMNS * sizeof(int));

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            p[i][j] = 10 * i + j;
            printf("p[%d][%d] = %d\n", i, j, p[i][j]);
        }
    }
    printf("size of p = %d\n", sizeof(p));
    printf("size of p[0] = %d\n", sizeof(p[0]));
    printf("size of p[0] = %d\n", sizeof(p[0]));

    for (int i = 0; i < COLUMNS; i++)
        free(p[i]);
    free(p);
    return 0;
}