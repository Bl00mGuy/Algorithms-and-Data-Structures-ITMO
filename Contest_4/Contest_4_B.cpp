#include <iostream>
using namespace std;

void new_heap(int m[], int n, int mother){
    int main = mother;
    int left = 2*mother + 1;
    int right = 2*mother + 2;
    if (left < n && m[left] > m[main]){
        main = left;
    }
    if (right < n && m[right] > m[main]){
        main = right;
    }
    if (main != mother){
        int shadow = m[mother];
        m[mother] = m[main];
        m[main] = shadow;
        new_heap(m, n, main);
    }
}

void heap_sort(int m[], int n){
    for (int i = n/2-1; i >= 0; i--) {
        new_heap(m, n, i);
    }
    for (int i = n-1; i >= 0; i--) {
        int shadow = m[0];
        m[0] = m[i];
        m[i] = shadow;
        new_heap(m, i, 0);
    }
}

int main() {
    int n;
    cin >> n;
    int m[n];
    for (int i = 0; i < n; i++){
        cin >> m[i];
    }
    heap_sort(m, n);
    for (int i = 0; i < n; i++){
        cout << m[i] << ' ';
    }
    return 0;
}
