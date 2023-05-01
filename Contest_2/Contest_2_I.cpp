#include <iostream>
#include <stack>
using namespace std;

void quicksort(int n, int m[]) {
    int i, j, left, right, pivot;
    left = 0;
    right = n-1;

    stack <int> tiff;
    tiff.push(left); //стек будет хранить левую и правую границы
    tiff.push(right);

    do {
        right = tiff.top();
        tiff.pop();
        left = tiff.top();
        tiff.pop();

        i = left;
        j = right;
        pivot = (i + j) / 2; //элемент в середине массива, привет Хоар
        int pivot_memory = m[pivot];

        do {
            //находим эл-т больше pivot
            while (m[i] < pivot_memory) {
                i++;
            }
            //находим эл-т меньше pivot
            while (m[j] > pivot_memory) {
                j--;
            }
            if (i <= j) { //<= для того чтобы индексы встали на нужные места для вставки их в стек
                swap(m[i], m[j]);
                i++;
                j--;
            }
        } while (i <= j);

        if (left < j) {
            tiff.push(left);
            tiff.push(j);
        }

        if (i < right) {
            tiff.push(i);
            tiff.push(right);
        }

    } while (!tiff.empty());
}

int main() {
    int n;
    cin >> n;
    int m[n];
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    quicksort(n, m);

    for (int k = 0; k < n; k++) {
        cout << m[k] << ' ';
    }

    return 0;
}
