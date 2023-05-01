#include <iostream>
#include <vector>
#define INFINITY 100000
using namespace std;

class Graph {
    private:
        struct Edge {
            int from, to, weight;
        };
        int V;
        vector<Edge> edges;
    public:
        Graph(int n): V(n) {}
    
        void addEdge(int from, int to, int weight) {
            edges.push_back({from, to, weight});
        }
    
        bool hasNegativeCycle(int k) {
            vector<int> dist(V, INFINITY);
            dist[0] = 0;
            bool changed;
            for (int i = 0; i < V - 1; i++) {
                changed = false;
                for (const Edge &e : edges) {
                    if (dist[e.from] != INFINITY and dist[e.to] > dist[e.from] + e.weight) {
                        dist[e.to] = dist[e.from] + e.weight;
                        changed = true;
                    }
                }
                if (!changed) {
                    break;
                }
            }
            for (const Edge &e : edges) {
                if (dist[e.from] != INFINITY and dist[e.to] > dist[e.from] + e.weight and dist[e.from] + e.weight < k) {
                    return true;
                }
            }
            return false;
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int vertices, edgesCount;
        cin >> vertices >> edgesCount;
        Graph g(vertices);
        for (int j = 0; j < edgesCount; j++) {
            int from, to, weight;
            cin >> from >> to >> weight;
            g.addEdge(from - 1, to - 1, weight);
        }
        cout << ((g.hasNegativeCycle(k)) ? "NO" : "YES") << "\n";
    }
    return 0;
}
