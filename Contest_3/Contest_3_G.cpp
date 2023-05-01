#include <iostream>
using namespace std;

void BinSearch(int n, double A){
    double left = 0;
    double right= A;
    double checker = -100;
    while ((right - left) > 0.001 / (n-1)){
        double middle = (left + right) / 2;
        double previous = A;
        double current = middle;
        bool not_on_the_ground = current > 0;
        for (int i = 3; i <= n; i++){
            double next = 2 * current - previous + 2;
            not_on_the_ground &= next > 0;
            previous = current;
            current = next;
        }
        if (not_on_the_ground){
            right = middle;
            checker = current;
        }
        else {
            left = middle;
        };
    }
    if (checker != -100) {
        printf("%.2f", checker);
    }
}

int main() {
    int n;
    double A;
    cin >> n >> A;
    BinSearch(n, A);
    return 0;
}
