#include <stdio.h>
#include <limits.h>

int main() {
    int n, position, massive[1000];
    long int droid_number, min_1, min_2;
    min_1 = INT_MAX; 
    min_2 = INT_MAX; 
    scanf("%d", &n); 
    if (n >= 2 && n <= 1000) { 
        for (int i = 0; i < n; i++) {
            scanf("%ld", &droid_number); 
            massive[i] = droid_number; 
             if (massive[i] < min_1) { 
                    min_1 = droid_number; 
                    position = i; 
             }
        }
        for (int i = 0; i < n; i++) {
            if (massive[i] < min_2 && i != position) min_2 = massive[i];
        }
        printf("%ld %ld", min_1, min_2);
    }
    return 0;
}
