#include <iostream>
using namespace std;

void insertion_sort(int size_of_array, int array[]){
    for (int i = 1; i < size_of_array; i++){
        for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
            swap(array[j - 1], array[j]);
    }
}

int main() {
    int n, m, jo1, jo2;
    cin >> n >> m;
    int boat[n * m];
    for (int i = 0; i < n * m; i++) {
        cin >> boat[i];
    }
    int k;
    cin >> k;
    int people[k];
    for (int i = 0; i < k; i++) {
        cin >> people[i];
    }

    insertion_sort(n * m, boat);
    insertion_sort(k, people);

    jo1 = 0;
    jo2 = 0;
    while (jo1 < n * m && jo2 < k) {
        if (boat[jo1] >= people[jo2]) {
            jo2++;
            jo1++;
        }
        else {
            jo1++;
        }
    }
    cout << jo2 << ' ';
    return 0;
}
