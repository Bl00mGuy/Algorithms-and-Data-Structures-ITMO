#include <iostream>
#include <vector>
using namespace std;

void DFS(int current, int start, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[current] = true;
    if (current == start) {
        return;
    }
    for (int i = 0; i < graph[current].size(); i++) {
        int next = graph[current][i];
        if (!visited[next]) {
            DFS(next, start, graph, visited);
        }
    }
}

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> graph(N+1);
    vector<bool> visited(N+1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < Q; i++) {
        char symbol;
        int a, b;
        cin >> symbol >> a >> b;
        if (symbol == '-') {
            graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
            graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());
        }
        else if (symbol == '?') {
            visited.assign(N+1, false); //reset visited
            DFS(b, a, graph, visited);
            cout << ((visited[a]) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
