#include <iostream>
#include <string>
using namespace std;

struct Node_string {
    string data;
    int height;
    Node_string *left, *right;
};

struct Node_symbol {
    char data;
    Node_symbol *left, *right;
};

int hight(Node_string *root) {
    int tmp;
    if (root != NULL) {
        tmp = root -> height;
        return tmp;
    }
    else return 0;
}

int height(Node_string *root) {
    int tmp;
    if (root != NULL) {
        tmp = 1 + max(hight(root -> right), hight(root -> left));
        return tmp;
    }
    else return 0;
}

int diff_height(Node_string *root) {
    int tmp;
    if (root != NULL) {
        tmp = height(root -> right) - height(root -> left);
        return tmp;
    }
    else return 0;
}

struct Node_string *left_rotate(struct Node_string *fir) {
    Node_string *sec = fir -> right, *tmp = sec -> left;
    sec -> left = fir;
    fir -> right = tmp;
    fir -> height = height(fir);
    sec -> height = height(sec);
    return sec;
}

struct Node_string *right_rotate(struct Node_string *sec) {
    Node_string *fir = sec -> left, *tmp = fir -> right;
    fir -> right = sec;
    sec -> left = tmp;
    sec -> height = height(sec);
    fir -> height = height(fir);
    return fir;
}

struct Node_string *create_str(string key) {
    Node_string *tmp = new Node_string;
    tmp -> data = key;
    tmp -> height = 1;
    tmp -> left = tmp -> right = NULL;
    return tmp;
}

struct Node_string *insert_str(struct Node_string *root, string key) {
    if (root == NULL) {
        return root = create_str(key);
    }
    if (root -> data > key) {
        root -> left = insert_str(root -> left, key);
    }
    else if (root -> data < key) {
        root -> right = insert_str(root -> right, key);
    }
    else return root;

    root -> height = height(root);
    int diff = diff_height(root);
    if (diff < -1) {
        if (root -> left -> data > key) return right_rotate(root);
        if (root -> left -> data < key) {
            root -> left = left_rotate(root -> left);
            return right_rotate(root);
        }
    }
    if (diff > 1) {
        if (root -> right -> data < key) return left_rotate(root);
        if (root -> right -> data > key) {
            root -> right = right_rotate(root -> right);
            return left_rotate(root);
        }
    }
    return root;
}

struct Node_symbol *create_chr(char key) {
    Node_symbol *tmp = new Node_symbol;
    tmp -> data = key;
    tmp -> left = tmp -> right = NULL;
    return tmp;
}

struct Node_symbol *insert_chr(struct Node_symbol *root, char key) {
    if (root == NULL) {
        return create_chr(key);
    }
    else if (root -> data == key) {
        return root;
    }
    else if (root -> data > key) {
        root -> left = insert_chr(root -> left, key);
    }
    else if (root -> data < key) {
        root -> right = insert_chr(root -> right, key);
    }
    return root;
}

bool search_str(struct Node_string *root, string key) {
    if (root == NULL) {
        return false;
    }
    if (root -> data == key) {
        return true;
    }
    if (root -> data > key) {
        return search_str(root -> left, key);
    }
    else {
        return search_str(root -> right, key);
    }
}

bool search_chr(struct Node_symbol *root, char key) {
    if (root == NULL) {
        return false;
    }
    if (root -> data == key) {
        return true;
    }
    if (root -> data > key) {
        return search_chr(root -> left, key);
    }
    else {
        return search_chr(root -> right, key);
    }
}

bool cheker = true;

int main() {
    struct Node_string *avl_tree = NULL;
    int n; cin >> n;
    int exclusive = 0;
    string tmp;
    string m[n];
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (!search_str(avl_tree ,tmp)) {
            avl_tree = insert_str(avl_tree, tmp);
        }
        else {
            struct Node_symbol *temp = NULL;
            string inf = tmp;
            int size = tmp.size();
            if (i >= 0) {
                for (int j = 0; j < size; j++) {
                    if (search_chr(temp, inf[j]) == false) {
                        temp = insert_chr(temp, inf[j]);
                        cheker = false;
                        exclusive += 1;
                    }
                }
            }
        }
    }
    cout << exclusive << ' ';
    return 0;
}
