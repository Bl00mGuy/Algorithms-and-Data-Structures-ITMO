#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node *left, *right;
};

struct Node *create(string numb) {
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp -> data = numb;
    tmp -> left = tmp -> right = NULL;
    return tmp;
}

struct Node *insert(struct Node *root, string key) {
    if (root == NULL) {
        root = new Node;
        root -> data = key;
        root -> left = root -> right = NULL;
    }
    else if (root -> data == key) {
        return root;
    }
    else if (root -> data > key) {
        root -> left = insert(root -> left, key);
    }
    else if (root -> data < key) {
        root -> right = insert(root -> right, key);
    }
    return root;
}

struct Node *min(struct Node *x) {
    if (x -> left == NULL) {
        return x;
    }
    return min(x -> left);
}

struct Node *remove(struct Node *root, string key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root -> left = remove(root -> left, key);
    }
    else if (key > root -> data) {
        root -> right = remove(root -> right, key);
    }
    else if(root -> left != NULL and root -> right != NULL){
        root -> data = min(root -> right)->data;
        root -> right = remove(root -> right , root -> data);
    }
    else {
        if (root -> left != NULL){
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }
    return root;
}

bool search(struct Node *root, string key){
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
        if (bin_tree1 != NULL) {
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
        }
        if (bin_tree2 != NULL) {
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
        }
        if (bin_tree3 != NULL) {
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
    }
    cout << st1 << ' ' << st2 << ' ' << st3 << ' ';
    return 0;
}
