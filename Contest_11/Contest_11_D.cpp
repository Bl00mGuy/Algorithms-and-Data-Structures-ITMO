#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edges {
    int dist, weight;

    Edges(int dist, int weight) {
        this->dist = dist;
        this->weight = weight;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, q, start;
    cin >> n >> m >> q >> start;

    vector<Edges> graph[n + 1];
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
    }

    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back(Edges(to, weight));
        graph[to].push_back(Edges(from, weight));
    }

    int dist[n + 1];
    fill(dist, dist + n + 1, INT_MAX);
    dist[start] = 0;
    priority_queue<int> queue;
    queue.push(start);
    while (!queue.empty()) {
        int from = queue.top();
        queue.pop();
        for (Edges edge: graph[from]) {
            int it = edge.dist;
            int weight = edge.weight;
            if (dist[it] > dist[from] + weight) {
                dist[it] = dist[from] + weight;
                queue.push(it);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        cout << (dist[query] == INT_MAX ? -1 : dist[query]) << "\n";
    }
    return 0;
}
