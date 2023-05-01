#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

struct Node *create(int numb) {
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp -> data = numb;
    tmp -> left = tmp -> right = NULL;
    return tmp;
}

struct Node *insert(struct Node *root, int key) {
    if (root == NULL) {
        return create(key);
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

struct Node *remove(struct Node *root, int key) {
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

struct Node *next(struct Node *root, int key) {
    struct Node *current = root;
    struct Node *successor = NULL;
    while (current != NULL) {
        if (current -> data > key) {
            successor = current;
            current = current -> left;
        }
        else {
            current = current -> right;
        };
    }
    return successor;
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

int main(){
    Node *bin_tree = NULL;
    string cmd;
    while (cin >> cmd){
        int k;
        cin >> k;
        if (cmd == "insert") {
            if (!bin_tree) bin_tree = insert(bin_tree, k);
            else insert(bin_tree, k);
        }
        if (cmd == "delete"){
            bin_tree = remove(bin_tree, k);
        }
        if (cmd == "exists"){
            if (search(bin_tree, k)){
                cout << "true" << "\n";
            }
            else {
                cout << "false" << "\n";
            }
        }
        if (cmd == "next"){
            struct Node *temp = next(bin_tree, k);
            if (temp == NULL){
                cout << "none" << "\n";
            }
            else {
                cout << temp -> data << "\n";
            }
        }
        if (cmd == "prev"){
            struct Node *temp = previous(bin_tree, k);
            if (temp == NULL){
                cout << "none" << "\n";
            }
            else {
                cout << temp -> data << "\n";
            }
        }
    }
    return 0;
}
