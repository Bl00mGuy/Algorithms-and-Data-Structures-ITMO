#include <stdio.h>

int main() {
    int n, iskomoe, psevdo_minimum = -666666666, psevdo_maximum = 666666666;
    scanf("%d", &n);
    int massive[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &massive[i]);
    }
    scanf("%d", &iskomoe);
    for (int i = 0; i < n; i++) {
        if (massive[i] == iskomoe) {
            psevdo_minimum = massive[i];
            break;
        }
        else if (massive[i] < iskomoe && massive[i] > psevdo_minimum) {
            psevdo_minimum = massive[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (massive[i] > iskomoe && massive[i] < psevdo_maximum) {
            psevdo_maximum = massive[i];
        }
    }
    if (psevdo_maximum - iskomoe < iskomoe - psevdo_minimum) {
        printf("%d", psevdo_maximum);
    }
    else {
        printf("%d", psevdo_minimum);
    }
    return 0;
}
