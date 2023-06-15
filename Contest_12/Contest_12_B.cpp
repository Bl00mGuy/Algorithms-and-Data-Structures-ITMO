#include <iostream>
#include <vector>
#define heal long long
using namespace std;

class Kruskal {
    private:
        heal N, M;
        vector<heal> PARENT;
        vector<pair<heal, pair<heal, heal>>> EDGES;
    public:
        Kruskal(heal N, heal M) : N(N), M(M), PARENT(N + 1), EDGES(M) {}

        void input() {
            for (heal i = 0; i < M; i++) {
                heal a, b, c;
                cin >> a >> b >> c;
                EDGES[i] = {c, {a, b}};
            }
        }

        heal find(heal x) {
            if (PARENT[x] == x) {
                return x;
            }
            return PARENT[x] = find(PARENT[x]);
        }

        void merge(heal x, heal y) {
            int x_root = find(x);
            int y_root = find(y);
            if (x_root != y_root) {
                PARENT[y_root] = x_root;
            }
        }

        heal kruskal() {
            heal output = 0;
            for (heal i = 1; i <= N; i++) {
                PARENT[i] = i;
            }
            sort(EDGES.begin(), EDGES.end());
            for (heal i = 0; i < M; i++) {
                heal a = EDGES[i].second.first, b = EDGES[i].second.second, w = EDGES[i].first;
                if (find(a) != find(b)) {
                    merge(a, b);
                    output += w;
                }
            }
            return output;
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    heal N, M;
    cin >> N >> M;
    Kruskal kruskal(N, M);
    kruskal.input();
    cout << kruskal.kruskal();
    return 0;
}
