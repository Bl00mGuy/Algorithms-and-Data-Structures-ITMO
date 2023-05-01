#include <iostream>
using namespace std;

int knapSack_solver(int capacity, int *weight, int *value, int n)
{
    int **temp = new int* [n + 1];
    for (int i = 0; i < n + 1; ++i) {
        temp[i] = new int[capacity + 1];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int current = 0; current <= capacity; current++)
        {
            if (i == 0 or current == 0)
            {
                temp[i][current] = 0;
            }
            else if (weight[i - 1] <= current)
            {
                temp[i][current] = max(value[i - 1] + temp[i - 1][current - weight[i - 1]], temp[i - 1][current]);
            }
            else
            {
                temp[i][current] = temp[i - 1][current];
            }
        }
    }
    int ans = temp[n][capacity];

    for (int i = 0; i < n + 1; i++)
    {
        delete[] temp[i];
    }
    delete[] temp;

    return ans;
}

int main()
{
    int s, n;  // s - вместимость рюкзака
    cin >> s >> n;

    int *weight = new int [n];
    int *value = new int [n];

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        value[i] = weight[i];
    }

    int ans = knapSack_solver(s, weight, value, n);
    cout << ans;

    delete[] weight;
    delete[] value;

    return 0;
}
