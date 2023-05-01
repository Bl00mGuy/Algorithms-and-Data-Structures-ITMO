#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 1666;
        }
        matrix[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        matrix[u][v] = w;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][k] != 1666 && matrix[k][j] != 1666 && abs(k - i) <= k && abs(k - j) <= k) {
                    matrix[i][j] = (matrix[i][j] < matrix[i][k] + matrix[k][j]) ? matrix[i][j] : matrix[i][k] + matrix[k][j];
                }
            }
        }
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        int dist = matrix[u][v];
        printf("%d\n", (dist != 1666) ? dist : -1);
    }
    return 0;
}
