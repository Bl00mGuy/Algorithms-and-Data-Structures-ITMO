#include <stdio.h>

int main() {
    int n, chisla, end, massive[35];
    scanf("%d", &n);
    if(n >= 1 && n <= 35){
        for(int i = 0; i < n; i++){
            scanf("%d", &chisla);
            massive[i] = chisla;
            if(i == n - 1) end = massive[i];
        }
        for(int i = n; i > 0; i--)
            massive[i] = massive[i - 1];
            massive[0] = end;
        for(int i = 0; i < n; i++)
            printf("%d ", massive[i]);
    }
    return 0;
}
