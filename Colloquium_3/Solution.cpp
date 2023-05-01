#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6;

int n, m, k, q, parent[N];
vector<pair<int, pair<int, int>>> edges;

int find(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[x] = y;
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < m; i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;
        if (w > k) {
            continue;
        }
        merge(u, v);
    }
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
