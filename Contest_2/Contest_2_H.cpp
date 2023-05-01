#include <stdio.h>

void merge(int *mass_first, int *mass_second, int left, int mid, int right)
{
    int it1 = 0, it2 = 0;

    int tmp1[right - left];
    int tmp2[(right - left)];

    while ((left + it1 < mid) && (mid + it2 < right))
    {
        if (mass_first[left + it1] < mass_first[mid + it2])
        {
            tmp1[it1 + it2] = mass_first[left + it1];
            tmp2[it1 + it2] = mass_second[left + it1];
            it1++;
        }
        else
        {
            tmp1[it1 + it2] = mass_first[mid + it2];
            tmp2[it1 + it2] = mass_second[mid + it2];
            it2++;
        }
    }

    while (left + it1 < mid)
    {
        tmp1[it1 + it2] = mass_first[left + it1];
        tmp2[it1 + it2] = mass_second[left + it1];
        it1++;
    }

    while (mid + it2 < right)
    {
        tmp1[it1 + it2] = mass_first[mid + it2];
        tmp2[it1 + it2] = mass_second[mid + it2];
        it2++;
    }

    for(int i = 0; i < it1 + it2; i++)
    {
        mass_first[left + i] = tmp1[i];
        mass_second[left + i] = tmp2[i];
    }

}

void mergeRecursive(int *mass_first, int *mass_second, int left, int right) {
    
    if(left + 1 >= right) return;

    int mid = (left + right) / 2;

    mergeRecursive(mass_first, mass_second, left, mid);
    mergeRecursive(mass_first, mass_second, mid, right);
    merge(mass_first, mass_second, left, mid, right);
}

int main()
{
    int number_of_elements, element1, element2, count, before, before1;
    scanf("%d", &number_of_elements);
    int array[number_of_elements][2];
    int array1[number_of_elements];
    int array2[number_of_elements];
    for (int i = 0; i < number_of_elements; i ++)
    {
        scanf("%d %d", &element1, &element2);
        array[i][0] = element1;
        array[i][1] = element2;
    }
    for (int i = 0; i < number_of_elements; i ++)
    {
        array1[i] = array[i][0];
        array2[i] = array[i][1];
    }
    mergeRecursive(array1, array2, 0, number_of_elements);
    for (int i = 0; i < number_of_elements; i ++)
    {
        array[i][0] = array1[i];
        array[i][1] = array2[i];
    }
    count = array[0][1] - array[0][0] + 1;
    before = array[0][1];
    before1 = array[0][0];
        for (int i = 0; i < number_of_elements; i ++)
            {
                if (array[i][0] > before && array[i][1] > before)
                {
                    count += array[i][1] - array[i][0] + 1;
                    before1 = array[i][0];
                    before = array[i][1];
                    
                }
                else if (array[i][1] > before && array[i][0] >= before1)
                {
                    count += array[i][1] - before;
                    before1 = array[i][0];
                    before = array[i][1];
                    
                }
            }
    
    printf("%d\n", count);
    return 0;
}
