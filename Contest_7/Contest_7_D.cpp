#include <iostream>
using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;
    char *arr = new char [m];

    string input;

    int *dynamic_arr = new int [m + 1];

    int rows = n;
    int columns = m;

    int x;
    int y;
    int max_len = 0;
    int max_x = 0;
    int max_y = 0;
    int temp;
    int previous = 0;
    for (int i = 1; i <= rows; i++)
    {
        cin >> input;

        for (int j = 0; j < columns; j++)
        {
            arr[j] = input[j];
        }

        for (int j = 1; j <= columns; j++)
        {

            temp = dynamic_arr[j];

           if (arr[j - 1] == '5')
           {
                dynamic_arr[j] = min(min(dynamic_arr[j - 1], previous), dynamic_arr[j]) + 1;

                if (max_len < dynamic_arr[j])
                {
                    max_len = dynamic_arr[j];
                    x = i - max_len + 1;
                    y = j - max_len + 1;
                }
                else if (max_len == dynamic_arr[j])
                {
                    x = i - max_len + 1;
                    y = j - max_len + 1;
                }
           }
           else
           {
                dynamic_arr[j] = 0;
           }

           previous = temp;
        }
    }

    cout << max_len << " " << x << " " << y;

    return 0;
}
