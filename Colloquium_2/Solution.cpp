#include <iostream>
using namespace std;

int summa = 0;
bool flag = false;

void finder(int **arr, int index, long long local_sum) {
    summa += arr[index][0];
    if (arr[index][1] == 0 and arr[index][2] == 0) {
        if (local_sum == summa) {
            flag = true;
        }
        return;
    }
    if (arr[index][1] != 0) {
        finder(arr, arr[index][1], local_sum);
    }
    if (arr[index][2] != 0) {
        finder(arr, arr[index][2], local_sum);
    }
}

int main() {
    int n, local_sum;
    cin >> n >> local_sum;
    int **arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[3];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    finder(arr, 0, local_sum);
    if (flag) cout << "YES";
    else cout << "NO";
    for (int i = 0; i < n; ++i) {
        delete []arr[i];
    }
    delete []arr;
    return 0;
}
