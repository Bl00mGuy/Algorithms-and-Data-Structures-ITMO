#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> spisok;
vector<bool> visited;

bool DFS(const int &N, int current, int count) {
    visited[current] = true;
    count++;
    if (count == N) {
        return true;
    }
    for (int i = 0; i < spisok[current].size(); i++) {
        int u = spisok[current][i];
        if (!visited[u] and DFS(N, u, count)) {
            return true;
        }
    }
    return false;
}

int BFS(const int &N, int start) {
    visited.assign(N, false);
    vector<int> dist(N, -1);
    dist[start] = 0;
    visited[start] = true;
    queue<int> q;
    q.push(start);
    int farthest = start;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < spisok[u].size(); i++) {
            int v = spisok[u][i];
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                if (dist[v] > dist[farthest]) {
                    farthest = v;
                }
                q.push(v);
            }
        }
    }
    return farthest;
}

bool HamiltonPath(const int &N) {
    int farthest = BFS(N, 0);
    visited.assign(N, false);
    if (DFS(N, farthest, 0)) {
        return true;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    spisok.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        spisok[u-1].push_back(v-1);
        spisok[v-1].push_back(u-1);
    }
    cout << (HamiltonPath(N) ? "YES" : "NO");
    return 0;
}
