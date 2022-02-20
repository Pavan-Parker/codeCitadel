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
        {
            temp->next = new;
            temp = temp->next;
        }
        else
        {
            temp = new;
            head = new;
        }
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
    printf("NULL\n");
}

int getSize(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void *quickSort(struct Node *head, int size)
{
    /*
     * 0. temp = head->next
     * 1. Compare head with temp if less than head pop it into start of LL.
     * 2. temp = temp->next
     * 3. Repat 1 if temp != NULL
     * 3. Call Sort on both halves.
     */
    struct Node *pivot = head;
    struct Node *leftHalf = pivot;
    struct Node *current = pivot->next;
    while (current != NULL)
    {
        if (current->value <= pivot->value)
        {
            int currentVal = current->value;
            current->value = leftHalf->value;
            leftHalf->value = currentVal;
        }
    }
    quickSort()
}

int main()
{
    int given[] = {1, 24, 12, 9, 24, 25, 10, 3, 2, 2};
    printf("given:%zu bytes\n", sizeof(given));
    struct Node *head = createLL(given, sizeof(given) / sizeof(int));
    printLL(head);
    quickSort(head, getSize(head));
    destroyLL(head);
    return 0;
}
