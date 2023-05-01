#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;

class Graph {
    private:
        vector<vector<int>> graph;
        vector<int> IndexOfNew;
        int IndexOfCurrent;
    public:
        Graph(int n) {
            graph.resize(n);
            IndexOfNew.resize(n);
            visited.resize(n, false);
            IndexOfCurrent = n;
        }

        void addEdge(int u, int v) {
            graph[u-1].push_back(v-1);
        }

        void DFS(int u) {
            visited[u] = true;
            for(int v: graph[u]) {
                if(!visited[v]) {
                    DFS(v);
                }
            }
            IndexOfNew[u] = IndexOfCurrent--;
        }

        void printIndexOfNew() {
            for (int i = 0; i < IndexOfNew.size(); i++) {
                cout << IndexOfNew[i] << " ";
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

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            graph.DFS(i);
        }
    }

    graph.printIndexOfNew();
    return 0;
}
