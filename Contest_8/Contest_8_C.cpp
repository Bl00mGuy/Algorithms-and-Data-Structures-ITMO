#include <iostream>
#include <string>

using namespace std;

bool Pow2(int number) {
    for (int x = 1; x <= number; x *= 2) {
        if (x == number) {
            return true;
        }
    }
    return false;
}

int search(string &str) {
    int error = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '1') {
            error ^= i + 1;
        }
    }
    return error;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        int errors = search(str);
        if (errors > 0) {
            str[errors - 1] ^= ('0' ^ '1');
        }
        for (int k = 0; k < str.size(); k++) {
            if (Pow2(k+1) == false) {
                cout << str[k];
            }
        }
        cout << "\n";
    }
    return 0;
}
