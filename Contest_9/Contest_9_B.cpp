#include <iostream>
#include <vector>
#define MAXN 100000
using namespace std;

vector<int> spisok[MAXN];
int color[MAXN];

bool DFS(int current, int parent, int start, int depth) {
    color[current] = 1;
    if (current == start and depth > 2) {
        return true;
    }
    for (int i = 0; i < spisok[current].size(); i++) {
        int v = spisok[current][i];
        if (v != parent) {
            if (color[v] == 0) {
                if (DFS(v, current, start, depth + 1)) {
                    return true;
                }
            } else if (color[v] == 1) {
                return true;
            }
        }
    }
    color[current] = 2;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    for (int k = 0; k < M; k++) {
        int u, v;
        cin >> u >> v;
        spisok[u].push_back(v);
        spisok[v].push_back(u);
    }
    for (int i = 0; i < N; i++) {
        color[i] = 0;
        if (DFS(i, -1, i, 0)) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
