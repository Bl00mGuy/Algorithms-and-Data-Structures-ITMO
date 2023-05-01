#include <iostream>
using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    string *arr = new string [n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int rows = n;
    int columns = m;

    int **dynamic_arr = new int* [rows + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dynamic_arr[i] = new int [columns + 1];
    }

    int x;
    int y;
    int max_len = 0;
    int max_x = 0;
    int max_y = 0;
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = columns - 1; j >= 0; j--)
        {
            if (arr[i][j] == '5')
            {
                dynamic_arr[i][j] = min(min(dynamic_arr[i + 1][j], dynamic_arr[i][j + 1]), dynamic_arr[i + 1][j + 1]) + 1;
                if (dynamic_arr[i][j] > max_len)
                {
                    max_len = dynamic_arr[i][j];
                    x = i + 1;
                    y = j + 1;
                }
            }
        }
    }


    cout << max_len << " " << x << " " << y;

    for (int i = 0; i < n; i++)
    {
        delete[] dynamic_arr[i];
    }
    delete[] dynamic_arr;

    return 0;
}
