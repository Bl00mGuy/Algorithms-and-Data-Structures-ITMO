# include <stdio.h>
# include <mm_malloc.h>

int k;

int Sortt(int *arr, int start, int end)
{
    int i = start;
    int j = end;
    int pivot = arr[(start + end) / 2];

    do
    {
        while (arr[i] < pivot)
        {
            i ++;
        }
        while (arr[j] > pivot)
        {
            j --;
        }
        if (i <= j)
        {
            int key = arr[i];
            arr[i] = arr[j];
            arr[j] = key;
            i ++;
            j --;
        }
    } while (i <= j);

    if (end >= k && i <= k)
    {
        Sortt(arr, i, end);
    }
    else if (start <= k && k <= j)
    {
        Sortt(arr, start, j);
    }

    return arr[k];
}


int main()
{
    int number_of_elements, element, A, B, C, res;
    scanf("%d %d", &number_of_elements, &k);
    k --;
    int array_of_input_elements[5];
    for (int i = 0; i < 5; i ++)
    {
        scanf("%d", &element);
        array_of_input_elements[i] = element;
    }
    A = array_of_input_elements[0];
    B = array_of_input_elements[1];
    C = array_of_input_elements[2];
    int *array = (int*) malloc(number_of_elements * sizeof(int));
    array[0] = array_of_input_elements[3];
    array[1] = array_of_input_elements[4];
    for (int i = 2; i < number_of_elements; i++)
    {
        array[i] = A * array[i - 2] + B * array[i - 1] + C;
    }
    res = Sortt(array, 0, number_of_elements - 1);
    printf("%d\n", res);
    return 0;
}
