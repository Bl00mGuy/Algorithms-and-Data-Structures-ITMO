#include <iostream>
using namespace std;

int LeftBinSearch (int numb_to_find, int m[], int n) {
    int start = -1;
    int end = n;
    while (start + 1 < end) {
        int middle = (start + end) / 2;
        if (m[middle] < numb_to_find){
            start = middle;
        }
        else{
            end = middle;
        }
    }
    if (end < n && m[end] == numb_to_find){
        return end;
    }
    else{
        return -2;
    }
}

int RightBinSearch(int numb_to_find, int m[], int n){
    int start = -1;
    int end = n;
    while (start + 1 < end) {
        int middle = (start + end) / 2;
        if (m[middle] <= numb_to_find){
            start = middle;
        }
        else {
            end = middle-1;
        }
    }
    if(m[end] == numb_to_find){
        return end;
    }
    else if (m[start] == numb_to_find){
        return start;
    }
    else {
        return -2;
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;
    int find[m];
    for (int i = 0; i < m; i++) {
        cin >> find[i];
    }
    for (int i = 0; i < m; i++) {
        int temp = LeftBinSearch(find[i], arr, n);
        cout << temp+1 << " ";
        int temp2 = RightBinSearch(find[i], arr, n);
        cout << temp2+1 << "\n";
    }
    return 0;
}
