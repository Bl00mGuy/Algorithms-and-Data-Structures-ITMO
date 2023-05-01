#include <iostream>
using namespace std;

int bin_tree[200000][3];
int hight;

void search(int previous, int h){
    if (hight < h){
        hight = h;
    }
    if (bin_tree[previous][1] > 0){
        search(bin_tree[previous][1], h + 1);
    }
    if (bin_tree[previous][2] > 0){
        search(bin_tree[previous][2], h + 1);
    }
}

int main(){
    int n;
    cin >> n;
    hight = 0;
    if (n == 0){
        cout << 0 << ' ';
        return 0;
    }
    for (int i = 0; i < n; i++){
        cin >> bin_tree[i+1][0] >> bin_tree[i+1][1] >> bin_tree[i+1][2];
    }
    search(1, 1);
    cout << hight << ' ';
    return 0;
}
