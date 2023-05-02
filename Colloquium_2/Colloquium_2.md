# Task A. Утешительная задача про дерево.

Дано двоичное дерево и Sum.
Определите, есть ли в дереве путь от корня до какого-нибудь листа (вершина без детей) такой, что сумма значений вершин на нем равняется Sum.

*Входные данные:*

В первой строке даны 2 числа 1<=n<=9∗10^5, 1<=Sum<=10^9 - количество вершин в дереве и определенная выше переменная Sum.
В следующих n строках задается по три числа.
В i+1 строке файла задается три числа val, l, r - значение в вершине с номером i, номер левого и номер правого ребенка.
0 означает отсутствие ребенка.


*Выходные данные:*

В единственной строке выведите "YES" без кавычек, если искомый путь существует, в противном случае выведите "NO" без кавычек.

<br/>

STDIN:
```
3 15
4 1 0
7 0 2
4 0 0
```

STDOUT:
```
YES
```