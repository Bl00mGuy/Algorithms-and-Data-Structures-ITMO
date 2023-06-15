#include <iostream>
#include <vector>
#include <string.h>
#define INFINITY 2147483647
#define ppT pair<pair<int, int>, T>
#define ppI pair<pair<int, int>, int>
using namespace std;

template<typename T>
class Kruskal {
    private:
        int n;
        vector<ppT> edges;
        vector<int> PARENT;
        vector<int> RANK;

        void init(int n) {
            PARENT.resize(n);
            RANK.resize(n, 0);
            for (int i = 0; i < n; i++) {
                PARENT[i] = i;
            }
        }

        int find(int x) {
            if (PARENT[x] == x) {
                return x;
            }
            PARENT[x] = find(PARENT[x]);
            return PARENT[x];
        }

        void merge(int x, int y) {
            int x_root = find(x);
            int y_root = find(y);
            if (x_root == y_root) {
                return;
            }
            if (RANK[x_root] < RANK[y_root]) {
                PARENT[x_root] = y_root;
            } else if (RANK[x_root] > RANK[y_root]) {
                PARENT[y_root] = x_root;
            } else {
                PARENT[x_root] = y_root;
                RANK[y_root]++;
            }
        }

    public:
        Kruskal(int n) : n(n) {}

        void addEdge(int u, int v, T w) {
            edges.push_back(make_pair(make_pair(u, v), w));
        }

        static bool compare(const ppT &a, const ppT &b) {
            return a.second < b.second;
        }

        vector<ppT> kruskal() {
            vector<ppT> result;
            init(n);
            sort(edges.begin(), edges.end(), compare);
            for (ppT edge : edges) {
                if (find(edge.first.first) != find(edge.first.second)) {
                    result.push_back(edge);
                    merge(edge.first.first, edge.first.second);
                }
            }
            return result;
        }

        vector<ppT> kruskal_del(ppT droped) {
            vector<ppT> result;
            init(n);
            sort(edges.begin(), edges.end(), compare);
            for (ppT edge : edges) {
                if (!(edge == droped) and find(edge.first.first) != find(edge.first.second)) {
                    result.push_back(edge);
                    merge(edge.first.first, edge.first.second);
                }
            }
            return result;
        }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    Kruskal<int> kruskal(N);
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        kruskal.addEdge(A-1, B-1, C);
    }
    vector<ppI> MST;
    MST = kruskal.kruskal();
    int MST1 = 0;
    for (vector<ppI>::iterator iterator = MST.begin(); iterator != MST.end(); ++iterator) {
        MST1 += iterator->second;
    }
    int MST2 = INFINITY;
    for (vector<ppI>::iterator iterator = MST.begin(); iterator != MST.end(); ++iterator) {
        vector<pair<pair<int, int>, int>> MST_del_edge = kruskal.kruskal_del(*iterator);
        int tmp = 0;
        for (vector<ppI>::iterator iterator2 = MST_del_edge.begin(); iterator2 != MST_del_edge.end(); ++iterator2) {
            tmp += iterator2->second;
        }
        if (tmp < MST2) {
            MST2 = tmp;
        }
    }
    cout << MST1 << " " << MST2;
    return 0;
}
