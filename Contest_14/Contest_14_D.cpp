#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
using ll = long long;

struct Node {
    string value;
    size_t size;
    size_t cnt;
    Node *L;
    Node *R;
    Node *P;
    Node(string &value) : value(value), cnt(1), size(1), P(NULL), L(NULL), R(NULL) {}
};

size_t N;
map<string, Node*> arr;
vector<ll> check_if_included(1e7, -1);

Node* createNode(string &value) {
    Node *node = new Node(value);
    node->size = 1;
    node->cnt = 1;
    node->P = NULL;
    node->L = NULL;
    node->R = NULL;
    return node;
}

ll insertNode(map<string, Node*> &arr, Node *&root, string &str) {
    Node* node = root;
    while (true) {
        ++node->size;
        if (str == node->value) {
            ++node->cnt;
            break;
        } else if (str < node->value) {
            if (node->L == NULL) {
                arr[str] = createNode(str);
                node->L = arr[str];
                arr[str]->P = node;
                break;
            } else {
                node = node->L;
            }
        } else {
            if (node->R == NULL) {
                arr[str] = createNode(str);
                node->R = arr[str];
                arr[str]->P = node;
                break;
            } else {
                node = node->R;
            }
        }
    }
    return 0;
}


ll insert(map<string, Node*> &arr, Node *&root, string &str) {
    if (arr.empty()) {
        arr[str] = createNode(str);
        root = arr[str];
    } else {
        insertNode(arr, root, str);
    }
    return 0;
}


string finder(Node *node, ll indx) {
    ll size_left = node->L != NULL ? node->L->size : 0;
    if (indx < size_left) {
        return finder(node->L, indx);
    } else if (indx - size_left < node->cnt) {
        return node->value;
    } else {
        return finder(node->R, indx - size_left - node->cnt);
    }
}

string find(Node* root, ll index) {
    if (root == NULL) {
        return "";
    }
    return finder(root, index);
}

bool isNumber(const std::string& str) {
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

ll input() {
    cin >> N;
    Node *root = NULL;
    string str;
    for (ll i = 0; i < N; i++) {
        cin >> str;
        if (!isNumber(str)) {
            insert(arr, root, str);
        } else {
            ll tmp = stoi(str) - 1;
            cout << find(root, tmp) << "\n";
        }
    }
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    input();
    return 0;
}
