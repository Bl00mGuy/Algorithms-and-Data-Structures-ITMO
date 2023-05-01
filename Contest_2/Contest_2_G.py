i=int(input())
lst_1 = input().split()
r=int(input())
lst_2 = input().split()
if set(lst_1) == set(lst_2):
    print('YES')
else:
    print('NO')
