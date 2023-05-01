#include <iostream>
#include <vector>
#include <queue>
#define INFINITY INT_MAX
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, S, F;

    cin >> N >> M;

    vector<vector<int>> table(N+1);
    vector<int> dist(N+1, INFINITY);
    queue<int> q;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        table[u].push_back(v);
        table[v].push_back(u);
    }

    cin >> S >> F;

    dist[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j = 0; j < table[u].size(); j++) {
            int v = table[u][j];
            if (dist[v] == INFINITY) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    if (dist[F] == INFINITY) {
        cout << "-1";
    } else {
        cout << dist[F] << endl;
    }
    return 0;
}
