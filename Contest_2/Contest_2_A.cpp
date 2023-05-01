#include <iostream>
using namespace std;

int main()
{
    int n, m[1000], elements, vstavit, place;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m[i];
    }
    cin >> vstavit >> place;
    for(int i = n + 1; i > place - 1; i--) {
        m[i] = m[i - 1];
    }
    m[place - 1] = vstavit;
    for(int i = 0; i < n + 1; i++) {
        cout << m[i] << ' ';
    }
    return 0;
}
