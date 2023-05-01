#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int first = -1, last = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) {
            if (first == -1) {
                first = i - 1;
            }
            last = i;
        }
    }
    if (first == -1) {
        cout << "yes\n";
        return 0;
    }
    reverse(a.begin() + first, a.begin() + last + 1);
    if (is_sorted(a.begin(), a.end())) {
        cout << "yes\n";
        cout << first + 1 << " " << last + 1 << "\n";
    } else {
        cout << "no\n";
    }
    return 0;
}
