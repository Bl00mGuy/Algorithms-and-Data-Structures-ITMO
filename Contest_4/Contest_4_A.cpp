#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m[n];
    for (int i = 0; i < n; i++){
        cin >> m[i];
    }
    int inf = 0;
    for (int i = 0; i < n / 2; i++){
        if ((2 * i + 1 < n) && (m[i] > m[2 * i + 1])){
            inf = 1;
            break;
        }
        if ((2 * i + 2 < n) && (m[i] > m[2 * i + 2])){
            inf = 1;
            break;
        }
    }
    if (inf == 1){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
    return 0;
}
