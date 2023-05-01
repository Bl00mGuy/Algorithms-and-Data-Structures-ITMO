# include <stdio.h>

int main()
{
    int number_of_elements, key1, key2;
    scanf("%d", &number_of_elements);
    int array[number_of_elements];
    for (int i = 1; i <= number_of_elements; i ++)
    {
        array[i - 1] = i;
    }
    key1 = array[1];
    key2 = array[2];
    array[1] = key2;
    array[2] = key1;
    for (int n = 3; n < number_of_elements; n ++)
    {
        key1 = array[n / 2];
        key2 = array[n];
        array[n / 2] = key2;
        array[n] = key1;
    }
    for (int i = 0; i < number_of_elements; i ++)
    {
        if (i == number_of_elements - 1)
        {
            printf("%d\n", array[i]);
        }
        else
        {
            printf("%d ", array[i]);
        }
    }
    return 0;
}
