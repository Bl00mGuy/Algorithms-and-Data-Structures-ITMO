#include <iostream>
#include <vector>
using namespace std;

void insertion_sort_up(int size_of_array, int array[][2]){
    for (int i = 1; i < size_of_array; i++){
        for (int j = i; j > 0 && array[j - 1][0] > array[j][0]; j--) {
            swap(array[j - 1][0], array[j][0]);
            swap(array[j - 1][1], array[j][1]);
        }
    }
}

void insertion_sort_down(int size_of_array, int array[][2]){
    for (int i = 1; i < size_of_array; i++){
        for (int j = i; j > 0 && array[j - 1][1] < array[j][1]; j--) {
            swap(array[j - 1][0], array[j][0]);
            swap(array[j - 1][1], array[j][1]);
        }
    }
}


int main() {
    int n;
    cin >> n;

    int arr[n][2];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2;j++) {
            cin >> arr[i][j];
        }
    }

    insertion_sort_up(n, arr);
    insertion_sort_down(n, arr);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2;j++) {
            cout << arr[i][j] << " ";
            if (j == 1)
                cout << "\n";
        }
    }

    return 0;
}
