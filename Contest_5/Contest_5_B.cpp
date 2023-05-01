#include <iostream>
using namespace std;

int bin_tree[200000][3];
int inf = 0;

int search(int previous, int min, int max){
    if (bin_tree[previous][0] <= min or bin_tree[previous][0] >= max){
        inf = 1;
        return 0;
    }
    if (bin_tree[previous][1] != 0){
        search(bin_tree[previous][1], min, bin_tree[previous][0]);
    }
    if (bin_tree[previous][2] != 0){
        search(bin_tree[previous][2], bin_tree[previous][0], max);
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    if (n == 0){
        cout << "YES" << ' ';
        return 0;
    }
    for (int i = 0; i < n; i++){
        cin >> bin_tree[i+1][0] >> bin_tree[i+1][1] >> bin_tree[i+1][2];
    }
    search(1, -2147483647, 2147483647); // дьявольский максимум )
    if (inf == 0){
        cout << "YES" << ' ';
    }
    else {
        cout << "NO" << ' ';
    }
    return 0;
}
