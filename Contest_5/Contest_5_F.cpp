#include <iostream>
#include <string>
using namespace std;
int n;
int indx = 0;
bool checker = true;

int postorder(int m[], int minimum, int maximum) {
    if (maximum < m[indx]) { // условия когда мы вылезаем
        checker = false;
        return 0;
    }
    if (minimum > m[indx]) {
        checker = false;
        return 0;
    }
    if (indx == n) {
        checker = false;
        return 0;
    }
    if (m[indx] > minimum) {
        if (m[indx] < maximum) {
            int data = m[indx];
            indx += 1;
            postorder(m, minimum, data);
            postorder(m, data, maximum);
            cout << data << ' ';
        }
    }
    return 0;
}

int detour(int m[]) {
    postorder(m, -1, 200001); //т.к. подаюстя значения 1 <= n <= 200000
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n == 0) {
        return 0;
    }
    int m[n];
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    detour(m);
    return 0;
}
