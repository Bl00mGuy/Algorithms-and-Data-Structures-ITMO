#include <iostream>
using namespace std;
int bin_tree[200000][2];
int bin_tree_key[200000];
int x = 1;

void search(int i) {
    if (bin_tree[i][0] == 0) {
        if (bin_tree[i][1] == 0) {
            if (bin_tree_key[i] == 0) {
                bin_tree_key[i] = x;
                x += 1;
            }
            return;
        }
        else {
            if (bin_tree_key[i] == 0){
                bin_tree_key[i] = x;
                x += 1;
            }
        }
    }
    if (bin_tree[i][0] != 0) {
        search(bin_tree[i][0] - 1);
        bin_tree_key[i] = x;
        x += 1;
    }
    if (bin_tree[i][1] != 0) {
        search(bin_tree[i][1] - 1);
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> bin_tree[i][0] >> bin_tree[i][1];
    }
    search(0);
    for (int i = 0; i < n; i++) {
        cout << bin_tree_key[i] << ' ';
    }
    return 0;
}
