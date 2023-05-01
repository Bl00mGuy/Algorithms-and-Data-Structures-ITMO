#include <iostream>
#include <malloc.h>
#include <string>
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
    struct Node *list = NULL;
    string str;

    while(cin >> str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '('){
                push(&list, '(');
            }
            else if (str[i] == '['){
                push(&list, '[');
            }
            else if (str[i] == '(' || str[i] == '[' && list == NULL){
                push(&list, '$'); //кидаю мусор
                break;
            }
            else if (list != NULL && str[i] == ')' && list -> value == '('){
                pop(&list);
            }
            else if (list != NULL && str[i] == ']' && list -> value == '['){
                pop(&list);
            }
            else if (list == NULL && str[i] == ')' || str[i] == ']') {
                push(&list, '$'); //кидаю мусор
                break;
            }
            else if (str[i] == ')' && list -> value != '(' && list != NULL){
                push(&list, '$'); //кидаю мусор
                break;
            }
            else if (str[i] == ']' && list -> value != '[' && list != NULL){
                push(&list, '$'); //кидаю мусор
                break;
            }
        }
        if (list == NULL) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
        list = NULL;
    }
}
