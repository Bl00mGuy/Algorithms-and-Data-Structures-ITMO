#include <iostream>
#include <vector>
#include <queue>
#define INFINITY 100000
using namespace std;

class Graph {
private:
    int n; // количество вершин
    int s; // начальная вершина
    int t; // конечная вершина
    vector<vector<int>> adjacencyList; // список смежности графа
    vector<vector<int>> weights; // матрица весов рёбер
public:
    Graph(int n, int s, int t) {
        this->n = n;
        this->s = s;
        this->t = t;
        adjacencyList.resize(n + 1);
        weights.resize(n + 1, vector<int>(n + 1, INFINITY));
    }

    void addEdge(int a, int b, int w) {
        adjacencyList[a].push_back(b);
        weights[a][b] = w;
    }

    int dijkstra() {
        vector<int> distance(n + 1, INFINITY);
        distance[s] = 0;
        priority_queue<int> pq;
        pq.push(s);
        while (!pq.empty()) {
            int u = pq.top();
            pq.pop();
            for (int i = 0; i < adjacencyList[u].size(); i++) {
                int v = adjacencyList[u][i];
                int w = weights[u][v];
                if (distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    pq.push(v);
                }
            }
        }
        return distance[t];
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    Graph g(n, s, t);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g.addEdge(a, b, w);
    }
    int distance = g.dijkstra();
    cout << ((distance != INFINITY) ? distance : -1) << "\n";
    return 0;
}
