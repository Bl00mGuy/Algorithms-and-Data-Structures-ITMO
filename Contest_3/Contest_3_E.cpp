#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;

struct Node {
    int value;
    int maximum;
    struct Node *next;
};

void push(struct Node **plist, int number) {
    struct Node *p = (struct Node*)malloc(sizeof (struct Node));
    struct Node *temp = *plist;   //запомнил предыдущий узел в temp'е
    if (temp == NULL){
        p -> value = number;
        p -> maximum = number;
        p -> next = *plist;
    }
    else if (temp != NULL && number > temp -> maximum) {
        p -> value = number;
        p -> maximum = number;
        p -> next = *plist;
    }
    else if (temp != NULL && number < temp -> maximum) {
        p -> value = number;
        p -> maximum = temp -> maximum;
        p -> next = *plist;
    }
    else if (temp != NULL && number == temp -> maximum) {
        p -> value = number;
        p -> maximum = number;
        p -> next = *plist;
    }
    *plist = p;
}

void pop(struct Node **plist) {
    struct Node *p = *plist;
    *plist = p -> next;
    free(p);
}

int max(struct Node **plist) {
    struct Node *p = *plist;
    int n = p -> maximum;
    return n;
}

int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    struct Node *list = NULL;
    int n;
    cin >> n;
    char znak[10];
    int numb;
    for (int i = 0; i < n; i++) {
        cin >> znak;
        if (znak[0] == '+'){
            cin >> numb;
            push(&list, numb);
        }
        else if (znak[0] == '-') {
            pop(&list);
        }
        else {
            int result = max(&list);
            cout << result << "\n";
        }
    }
    return 0;
}
