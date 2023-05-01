#include <stdio.h>

int main() {
    int massive_razmer, podhodit = 0;
    scanf("%d", &massive_razmer);
    int a[massive_razmer];
    for (int i = 0; i < massive_razmer; i++)
    {
        scanf("%d", &a[i]); 
    }
    for (int i = 1; i < massive_razmer - 1; i++)
    {
        if (a[i] > a[i-1] && a[i] > a[i+1])
        {
            podhodit += 1;
        }
    }
    printf("%d", podhodit);

    return 0;
}
