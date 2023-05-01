#include <iostream>
using namespace std;

int main() {
    int inf;
    int n;
    cin >> n;
    int m[n];
    for (int b = 0; b < n; ++b) {
        cin >> m[b];
    }
    for (int b = 1; b < n; b++) {
        int key = m[b];
        int d = b - 1;
        inf = 0;

        while (d >= 0 && m[d] > key) {
            m[d + 1] = m[d];
            m[d] = key;
            d--;
            inf = 1;
        }
        if (inf == 1) {
            for (int k = 0; k < n; k++) {
                printf("%d ", m[k]);
            }
            printf("\n");
        }
    }
    return 0;
}
