#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m[n];
    for (int b = 0; b < n; ++b) {
        cin >> m[b];
    }
    for (int b = 1; b < n; b++){
        int key = m[b];
        int d = b-1;

        while (d >= 0 && m[d] > key){
            m[d+1] = m[d];
            m[d] = key;
            d--;
        }
    }
    for (int k = 0; k < n; k++){
        cout << m[k] << " ";
    }
    return 0;
}
