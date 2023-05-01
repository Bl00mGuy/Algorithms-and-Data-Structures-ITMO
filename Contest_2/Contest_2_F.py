def merge(array, start, end, middle):
    left = array[start:middle + 1]
    right = array[middle+1:end+1]

    left_copy_index = 0
    right_copy_index = 0
    sorted_index = start

    while left_copy_index < len(left) and right_copy_index < len(right):
        if left[left_copy_index] <= right[right_copy_index]:
            array[sorted_index] = left[left_copy_index]
            left_copy_index += 1
        else:
            array[sorted_index] = right[right_copy_index]
            right_copy_index += 1
        
        sorted_index += 1

    while left_copy_index < len(left):
        array[sorted_index] = left[left_copy_index]
        left_copy_index += 1
        sorted_index += 1

    while right_copy_index < len(right):
        array[sorted_index] = right[right_copy_index]
        right_copy_index += 1
        sorted_index += 1

def merge_sort(array, start, end):
    if start < end:
        middle = (start + end)//2
        merge_sort(array, start, middle)
        merge_sort(array, middle + 1, end)
        merge(array, start, end, middle)

n = int(input())
m = [int(x) for x in input().split(maxsplit = n)]
merge_sort(m, 0, len(m)-1)
for i in m:
    print(i,end = ' ')
