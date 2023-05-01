#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <float.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int data;
    int height;
    struct Node *left, *right;
};

int hight(struct Node *root) {
    int tmp;
    if (root != NULL) {
        tmp = root -> height;
        return tmp;
    }
    return 0;
}

int height(struct Node *root) {
    int tmp, max;
    if (root != NULL) {
        if (hight(root -> right) > hight(root -> left)) {
            max = hight(root -> right);
        }
        else {
            max = hight(root -> left);
        }
        tmp = 1 + max;
        return tmp;
    }
    return 0;
}

int diff_height(struct Node *root) {
    int tmp;
    if (root != NULL) {
        tmp = height(root -> right) - height(root -> left);
        return tmp;
    }
    return 0;
}

struct Node *right_rotate(struct Node *sec) {
    struct Node *fir = sec -> left, *tmp = fir -> right;
    fir -> right = sec;
    sec -> left = tmp;
    sec -> height = height(sec);
    fir -> height = height(fir);
    return fir;
}

struct Node *left_rotate(struct Node *fir) {
    struct Node *sec = fir -> right, *tmp = sec -> left;
    sec -> left = fir;
    fir -> right = tmp;
    fir -> height = height(fir);
    sec -> height = height(sec);
    return sec;
}

struct Node *create(int key) {
    struct Node *tmp = (struct Node*) malloc(sizeof(struct Node));
    tmp -> data = key;
    tmp -> height = 1;
    tmp -> left = tmp -> right = NULL;
    return tmp;
}

int m[200000][3];

struct Node *insert(struct Node *root, int id) {
    root = create(m[id][0]);

    if (m[id][1] -1 != -1) root -> left = insert(root -> left, m[id][1] - 1);
    if (m[id][2] -1 != -1) root -> right = insert(root -> right, m[id][2] - 1);

    root -> height = height(root);
    int diff = diff_height(root);
    switch (diff) {
        case (-2):
            if (diff_height(root -> left) > 0) {
                root -> left = left_rotate(root -> left);
            }
            return right_rotate(root);
        case (2):
            if (diff_height(root -> right) < 0) {
                root -> right = right_rotate(root -> right);
            }
            return left_rotate(root);
    }
    return root;
}

struct Node *insertion(struct Node *root, int key) {
    if (root == NULL) {
        return root = create(key);
    }
    if (root -> data > key) {
        root -> left = insertion(root -> left, key);
    }
    else if (root -> data < key) {
        root -> right = insertion(root -> right, key);
    }
    else return root;

    root -> height = height(root);
    int diff = diff_height(root);
    switch (diff) {
        case (-2) :
            if (root->left->data > key) return right_rotate(root);
            if (root->left->data < key) {
                root->left = left_rotate(root->left);
                return right_rotate(root);
            }
            break;
        case (2):
            if (root -> right -> data < key) return left_rotate(root);
            if (root -> right -> data > key) {
                root -> right = right_rotate(root -> right);
                return left_rotate(root);
            }
            break;
    }
    return root;
}

bool search(struct Node *root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root -> data == key) {
        return true;
    }
    if (root -> data > key) {
        return search(root -> left, key);
    }
    else {
        return search(root -> right, key);
    }
}

int inf = 2;

void level_order(struct Node *root, int id) {
    if (root == NULL) return;
    if (id == 1) {
        if (root->left != NULL) {
            if (root->right != NULL) {
                printf("%d ", root->data);
                printf("%d ", inf);
                inf += 1;
                printf("%d\n", inf);
                inf += 1;

            }
            // or
            if (root->right == NULL) {
                printf("%d ", root -> data);
                printf("%d ", inf);
                printf("%d\n", 0);
                inf += 1;
            }
        }

        if (root->left == NULL) {
            if (root->right != NULL) {
                printf("%d ", root -> data);
                printf("%d ", 0);
                printf("%d\n", inf);
                inf += 1;
            }
            // or
            if (root->right == NULL) {
                printf("%d ", root -> data);
                printf("%d ", 0);
                printf("%d\n", 0);
            }
        }
    }

    if (id >= 2) {
        level_order(root->left, id - 1);
        level_order(root->right, id - 1);
    }
}

int main() {
    struct Node *avl = NULL;
    unsigned int tmp_height = 1;
    int n;
    scanf("%d", &n);
    bool check_debilny_test;

    if (n == 0) {
        check_debilny_test = true;
    } else if (n != 0) {
        check_debilny_test = false;
    }

    if (check_debilny_test) {
        int K, L, R;
        scanf("%d %d %d", &K, &L, &R);
        printf("%d\n", n+1);
        printf("%d %d %d", K, L, R);
        return 0;
    }

    else if (!check_debilny_test) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &m[i][0], &m[i][1], &m[i][2]);
        }

        avl = insert(avl, 0);

        int put;
        scanf("%d", &put);
        avl = insertion(avl, put);

        printf("%d\n", n+1);
        tmp_height += height(avl);
        for (int i = 0; i < tmp_height; i++) {
            level_order(avl, i);
        }
    }
    return 0;
}
