#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node *next;
};

Node *createLL(int *array, int size)
{
    struct Node *head;
    struct Node *temp = head;
    for (int i = 0; i < size; i++)
    {
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        new->value = array[i];
        new->next = NULL;
        if (i)
            temp->next = new;
        else
        {
            temp = new;
            head = new;
        }
        temp = temp->next;
    }
}

int main()
{
    int given[] = {1, 24, 12, 9, 24, 25, 10, 3, 2, 2};
    printf("given:%zu bytes", sizeof(given));

    return 0;
}
