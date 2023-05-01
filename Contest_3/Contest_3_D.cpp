#include <iostream>
#include <malloc.h>
#include <string>
#include <string.h>
using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

void push(struct Node **plist, int number)
{
    struct Node *p = (struct Node*)malloc(sizeof (struct Node));
    p -> value = number;
    p -> next = *plist;
    *plist = p;
}

void pop(struct Node **plist, char znak)
{
    struct Node *p = *plist;
    int res = p -> value;
    *plist = p -> next;
    free(p);
    struct Node *p2 = *plist;
    if (znak == '+') {
        p2->value = p2->value + res;
    }
    else if (znak == '-') {
        p2 -> value = p2 -> value - res;
    }
    else {
        p2 -> value = p2 -> value * res;
    }
    *plist = p2;
}

int main()
{
    string str;
    struct Node *list;
    getline(cin, str);
    for (int i = 0; i < str.size(); i += 2) {
        if (str[i] != '+' && str[i] != '-' && str[i] != '*') {
            push(&list, str[i]-'0'); //преобразуем char в int
        }
        else {
            pop(&list, str[i]);
        }
    }
    cout << list -> value << ' ';
}
