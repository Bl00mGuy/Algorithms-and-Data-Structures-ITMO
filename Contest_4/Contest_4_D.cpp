#include <iostream>
#include <string.h>
#include <string>
using namespace std;

void CountingSort(int n, int k, string arr[]) {
    int counter[256];
    memset(counter, 0 , 1024);

    for (int i = 0; i < n; i++) {
        counter[arr[i][k]]++;
    }
    for (int i = 1; i < 256; i++) {
        counter[i] += counter[i-1];
    }

    string sorted[n];
    for (int i = n-1; i >= 0; i --) {
        sorted[counter[arr[i][k]]-1] = arr[i];
        counter[arr[i][k]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sorted[i];
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    string str[n];
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    
    int inf = 0;
    for (int j = m-1; j >= 0; j--) {
        if (inf == k){
            break;
        }
        inf += 1;
        CountingSort(n, j,str);
    }
    
    for (int i = 0; i < n; i++) {
        cout << str[i] << ' ';
        cout << "\n";
    }
    return 0;
}
