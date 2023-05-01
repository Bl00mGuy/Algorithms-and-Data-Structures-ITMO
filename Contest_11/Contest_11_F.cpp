#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> PARENT;
vector<int> RANK;

struct request {
    bool symbol; // ? = 1   - = 0
    pair<int, int> edge;
};

void make_sets(int n) {
    PARENT.resize(n);
    RANK.resize(n);
    for (int i = 0; i < n; i++) {
        PARENT[i] = i;
        RANK[i] = 0;
    }
}

int find(int x) {
    if (PARENT[x] == x) {
        return x;
    }
    return PARENT[x] = find(PARENT[x]);
}

void merge(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);
    if (root_x != root_y) {
        if (RANK[root_x] < RANK[root_y]) {
            swap(root_x, root_y);
        }
        PARENT[root_y] = root_x;
        if (RANK[root_x] == RANK[root_y]) {
            RANK[root_x]++;
        }
    }
}

void filter_graph(vector<pair<int, int>> &graph, vector<pair<int, int>> &need_to_delete, vector<pair<int, int>> &copy) {
    for (int i = 0; i < graph.size(); i++) {
        if (!std::binary_search(need_to_delete.begin(), need_to_delete.end(), graph[i])) {
            if (!std::binary_search(copy.begin(), copy.end(), graph[i])) {
                copy.push_back(graph[i]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;

    make_sets(N);

    vector<pair<int, int>> graph(M);
    vector<request> memory(Q);
    vector<pair<int, int>> need_to_delete;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph[i].first = min(a, b);
        graph[i].second = max(a, b);
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        char symbol;
        cin >> symbol;
        cin >> a >> b;
        --a, --b;
        if (symbol == '?') {
            memory[i].symbol = 1;
            memory[i].edge.first = a;
            memory[i].edge.second = b;
        } else if (symbol == '-') {
            (a < b) ? need_to_delete.emplace_back(a, b) : need_to_delete.emplace_back(b, a);
            memory[i].symbol = 0;
            memory[i].edge.first = (a < b) ? a : b;
            memory[i].edge.second = (a < b) ? b : a;
        }
    }

    vector<pair<int, int>> copy;
    sort(graph.begin(), graph.end());
    sort(need_to_delete.begin(), need_to_delete.end());
    filter_graph(graph, need_to_delete, copy);

    for (pair<int, int> i: copy) {
        merge(i.first, i.second);
    }

    stack<string> output;
    for (int i = Q - 1; i >= 0; i--) {
        if (memory[i].symbol == 1) {
            output.emplace(find(memory[i].edge.first) == find(memory[i].edge.second) ? "YES" : "NO");
        }
        if (memory[i].symbol == 0) {
            merge(memory[i].edge.first, memory[i].edge.second);
        }
    }
    while (!output.empty()) {
        cout << output.top() << "\n";
        output.pop();
    }
}
