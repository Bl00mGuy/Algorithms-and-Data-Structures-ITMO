#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Node
{
    int value;
    struct Node *next;
};

void print(struct Node *list) //гигачад принт
{
    for (struct Node *p = list; p != NULL; p = p -> next)
    {
        printf("%d ", p -> value);
    }
    printf("\n");
}

void push(struct Node **plist, int number)
{
    struct Node *p = malloc(sizeof (struct Node));
    p -> value = number;
    p -> next = *plist;
    *plist = p;
}

int pop(struct Node **plist)
{
    struct Node *p = *plist;
    int res = p -> value;
    *plist = p -> next;
    free(p);
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);

    char znak[2];
    int m;

    struct Node *list = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", &znak);
        if (strcmp(znak, "+") == 0)
        {
            scanf("%d", &m);
            push(&list, m);
        } else
        {
            int x = pop(&list);
            printf("%d\n", x);
        }
    }
}
