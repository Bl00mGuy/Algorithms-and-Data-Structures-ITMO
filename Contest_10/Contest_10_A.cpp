#include <iostream>
#include <vector>
#define MAXN 100000
using namespace std;

class Graph {
private:
    int n;
    vector<int> spisok[MAXN + 1];
    bool trap[MAXN + 1], visited[MAXN + 1];
    int counter = 0;
    int comp[MAXN + 1], trapcomp[MAXN + 1];

public:
    Graph(int size) {
        n = size;
    }

    void add_edge(int a, int b) {
        spisok[a].push_back(b);
        spisok[b].push_back(a);
    }

    void add_trap(int i) {
        trap[i] = true;
    }

    void DFS(int u, int current) {
        visited[u] = true;
        comp[u] = current;
        trapcomp[current] |= trap[u];
        for (int v: spisok[u]) {
            if (!visited[v]) {
                DFS(v, current);
            }
        }
    }

    void find_components() {
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                counter++;
                DFS(i, counter);
            }
        }
    }

    void print_components() {
        cout << counter << "\n";
        for (int i = 1; i <= n; i++) {
            cout << comp[i] << " ";
        }
        cout << "\n";
        for (int i = 1; i <= counter; i++) {
            cout << trapcomp[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    Graph graph(n);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        graph.add_edge(a, b);
    }
    for (int i = 1; i <= n; i++) {
        char symbol;
        cin >> symbol;
        if (symbol == '1') {
            graph.add_trap(i);
        }
    }
    graph.find_components();
    graph.print_components();
    return 0;
}
