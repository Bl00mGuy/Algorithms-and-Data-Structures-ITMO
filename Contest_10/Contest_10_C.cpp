#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> spisok;
int n;

class Graph {
private:
    vector<bool> visited;
public:
    Graph(const int &n) {
        spisok.resize(n);
        visited.resize(n, false);
    }

    int DFS(int &start, int &end) {
        visited[start] = true;
        if (start == end) {
            return 1;
        }
        for (int i = 0; i < spisok[start].size(); i++) {
            int next = spisok[start][i];
            if (!visited[next]) {
                if (DFS(next, end)) {
                    return 1;
                }
            }
        }
        return 0;
    }

    bool delivery(int &u, int &v) {
        visited.assign(n, false);
        if (DFS(u, v)) {
            return true;
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, q;
    cin >> n >> m >> q;
    Graph graph(n+1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        spisok[u].push_back(v);
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << ((graph.delivery(a, b) and graph.delivery(b, a)) ? "YES" : "NO") << "\n";
    }
    return 0;
}
