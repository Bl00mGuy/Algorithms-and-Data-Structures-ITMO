#include <iostream>
#include <string>
using namespace std;

int n;

void gray_code_gen(string &str, int i) {
    if (i == n) {
        cout << str << "\n";
        return;
    }
    gray_code_gen(str, i+1);
    if (str[i] == '0') {
        str[i] = '1';
    } else {
        str[i] = '0';
    }
    gray_code_gen(str, i+1);
}

void gray_code() {
    string str(n, '0');
    gray_code_gen(str, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    gray_code();
    return 0;
}
