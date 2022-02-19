#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int value;
    struct Node *next;
};

struct Node *createLL(int *array, int size)
{
    struct Node *head;
    struct Node *temp;
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

    return head;
}

void destroyLL(struct Node *head)
{
    struct Node *temp = head;
    struct Node *past;
    while (temp != NULL)
    {
        past = temp;
        temp = temp->next;
        free(past);
    }
}

void printLL(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{

    int given[] = {1, 24, 12, 9, 24, 25, 10, 3, 2, 2};
    printf("given:%zu bytes", sizeof(given));

    struct Node *head = createLL(given, sizeof(given) / sizeof(int));
    printLL(head);
    destroyLL(head);
    return 0;
}
