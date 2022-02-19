#include <stdio.h>

struct Node
{
    int value;
    struct Node *next = NULL;
};

Node *createLL(int *array, int size)
{
    struct Node *head;
    struct Node *current=head;
    struct Node *temp;
    for (int i = 0; i < size; i++)
    {
        temp->value = array[i];
        temp->next
    }
}

int main()
{
    int given[] = {1, 24, 12, 9, 24, 25, 10, 3, 2, 2};
    printf("given:%zu bytes", sizeof(given));

    return 0;
}
