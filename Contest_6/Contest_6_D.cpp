#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Node {
    string data;
    int height;
    Node *left, *right;
};

int hight(Node *root) {
    int tmp;
    if (root != NULL) {
        tmp = root -> height;
        return tmp;
    }
    else return 0;
}

int height(Node *root) {
    int tmp;
    if (root != NULL) {
        tmp = 1 + max(hight(root -> right), hight(root -> left));
        return tmp;
    }
    else return 0;
}

int diff_height(Node *root) {
    int tmp;
    if (root != NULL) {
        tmp = height(root -> right) - height(root -> left);
        return tmp;
    }
    else return 0;
}

Node *left_rotate(Node *fir) {
    Node *sec = fir -> right, *tmp = sec -> left;
    sec -> left = fir;
    fir -> right = tmp;
    fir -> height = height(fir);
    sec -> height = height(sec);
    return sec;
}

Node *right_rotate(Node *sec) {
    Node *fir = sec -> left, *tmp = fir -> right;
    fir -> right = sec;
    sec -> left = tmp;
    sec -> height = height(sec);
    fir -> height = height(fir);
    return fir;
}

Node *create(string key) {
    Node *tmp = new Node;
    tmp -> data = key;
    tmp -> height = 1;
    tmp -> left = tmp -> right = NULL;
    return tmp;
}

Node *insert(Node *root, string key) {
    if (root == NULL) {
        return root = create(key);
    }
    if (root -> data > key) {
        root -> left = insert(root -> left, key);
    }
    else if (root -> data < key) {
        root -> right = insert(root -> right, key);
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

bool search(struct Node *root, string key) {
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

int main() {
    Node *bin_tree1 = NULL;
    Node *bin_tree2 = NULL;
    Node *bin_tree3 = NULL;
    int n;
    cin >> n;
    string m[3][n];
    int st1 = 0, st2 = 0, st3 = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
            if (i == 0) {
                bin_tree1 = insert(bin_tree1, m[i][j]);
            }
            if (i == 1) {
                bin_tree2 = insert(bin_tree2, m[i][j]);
            }
            if (i == 2) {
                bin_tree3 = insert(bin_tree3, m[i][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!search(bin_tree2, m[0][i]) and !search(bin_tree3, m[0][i])) {
            st1 += 3;
        }
        if ((search(bin_tree2, m[0][i]) and !search(bin_tree3, m[0][i])) or (!search(bin_tree2, m[0][i]) and search(bin_tree3, m[0][i]))) {
            st1 += 1;
        }
        if (search(bin_tree2, m[0][i]) and search(bin_tree3, m[0][i])) {
            st1 += 0;
            st2 += 0;
            st3 += 0;
        }

        if (!search(bin_tree1, m[1][i]) and !search(bin_tree3, m[1][i])) {
            st2 += 3;
        }
        if ((search(bin_tree1, m[1][i]) and !search(bin_tree3, m[1][i])) or (!search(bin_tree1, m[1][i]) and search(bin_tree3, m[1][i]))) {
            st2 += 1;
        }
        if (search(bin_tree1, m[1][i]) and search(bin_tree3, m[1][i])) {
            st1 += 0;
            st2 += 0;
            st3 += 0;
        }

        if (!search(bin_tree1, m[2][i]) and !search(bin_tree2, m[2][i])) {
            st3 += 3;
        }
        if ((search(bin_tree1, m[2][i]) and !search(bin_tree2, m[2][i])) or (!search(bin_tree1, m[2][i]) and search(bin_tree2, m[2][i]))) {
            st3 += 1;
        }
        if (search(bin_tree1, m[2][i]) and search(bin_tree2, m[2][i])) {
            st1 += 0;
            st2 += 0;
            st3 += 0;
        }
    }
    cout << st1 << ' ' << st2 << ' ' << st3 << ' ';
    return 0;
}
