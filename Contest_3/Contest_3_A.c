#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct Node
{
    int value;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void print(struct Node *list)
{
    for (struct Node *p = list; p != NULL; p = p -> next)
    {
        printf("%d ", p -> value);
    }
    printf("\n");
}

int pop()
{
    struct Node *tmp = head;
    int res = tmp -> value;
    head = head -> next;
    free(tmp);
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);

    char o[2];
    int d;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", &o);
        if (strcmp(o, "+") == 0)
        {
            scanf("%d", &d);
            struct Node *p = (struct Node*) malloc(sizeof (struct Node));
            p -> value = d;
            p -> next = NULL;
            if (head == NULL)
            {
                head = p;
                tail = p;
            } else
            {
                tail -> next = p;
                tail = p;
            }
        }
        else {
            int x = pop();
            printf("%d\n", x);
        }
    }

    return 0;
}
