#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    int height;
    Node *left, *right;
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
    int tmp;
    if (root != NULL) {
        tmp = 1 + max(hight(root->right), hight(root->left));
        return tmp;
    } else return 0;
}

int diff_height(struct Node *root) {
    int tmp;
    tmp = height(root->right) - height(root->left);
    return tmp;
}

struct Node *right_rotate(struct Node *sec) {
    struct Node *fir = sec -> left;
    struct Node *tmp = fir -> right;
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

Node *rebalance(Node *root) {
    root -> height = height(root);
    if (diff_height(root) >= 2) {
        if (diff_height(root -> right) < 0) {
            root -> right = right_rotate(root -> right);
        }
        return left_rotate(root);
    }
    if (diff_height(root) <= -2) {
        if (diff_height(root -> left) > 0) {
            root -> left = left_rotate(root -> left);
        }
        return right_rotate(root);
    }
    return root;
}

struct Node *create(int numb) {
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp -> data = numb;
    tmp -> height = 1;
    tmp -> left = tmp -> right = NULL;
    return tmp;
}

struct Node *insert(struct Node *root, int key) {
    if (root == NULL) {
        return create(key);
    }
    else if (root -> data > key) {
        root -> left = insert(root -> left, key);
    }
    else if (root -> data < key) {
        root -> right = insert(root -> right, key);
    }
    return rebalance(root);
}

struct Node *previous(struct Node *root, int key) {
    struct Node *current = root;
    struct Node *successor = NULL;
    while (current != NULL) {
        if (current -> data < key) {
            successor = current;
            current = current -> right;
        }
        else {
            current = current -> left;
        };
    }
    return successor;
}

struct Node *remove(struct Node *root, int key) {
    if (root == NULL) {
        return root;
    }
    if (root -> data > key) {
        root -> left = remove(root -> left, key);
    }
    else if (root -> data < key) {
        root -> right = remove(root -> right, key);
    }
    else if (root -> left != NULL and root -> right != NULL) {
        root->data = previous(root->left, key)->data;
        root->left = remove(root->left, root->data);
    }
    else {
        //first case
        if (root -> right != NULL) {
            root = root -> right;
            rebalance(root);
        }
            // second case
        else if (root -> left != NULL) {
            root = root -> left;
            return rebalance(root);
        }
        else {
            root = NULL;
            return NULL;
        }
    }
    return rebalance(root);
}

bool search(struct Node *root, int key){
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Node *avl = NULL;
    int n;
    cin >> n;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "A") {
            int k;
            cin >> k;
            if (!search(avl, k)) {
                avl = insert(avl, k);
                cout << diff_height(avl) << "\n";
            } else {
                cout << diff_height(avl) << "\n";
            }
        }
        if (cmd == "D") {
            int k;
            cin >> k;
            if (search(avl, k)) {
                avl = remove(avl, k);
            }
            if (avl != NULL) {
                cout << diff_height(avl) << "\n";
            }
            if (avl == NULL) {
                cout << 0 << "\n";
            }
        }
        if (cmd == "C") {
            int k;
            cin >> k;
            if (search(avl, k)) {
                cout << "Y" << "\n";
            } else {
                cout << "N" << "\n";
            }
        }
    }
    return 0;
}
