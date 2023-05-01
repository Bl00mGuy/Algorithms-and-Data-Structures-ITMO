#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> plan;
vector<vector<bool>> visited;

void DFS(const int &N, const int &M, int i, int j) {
    visited[i][j] = true;
    if (i > 0 and !visited[i - 1][j] and plan[i - 1][j] == '.') {
        DFS(N, M, i - 1, j);
    }
    if (i < N and !visited[i + 1][j] and plan[i + 1][j] == '.') {
        DFS(N, M, i + 1, j);
    }
    if (j > 0 and !visited[i][j - 1] and plan[i][j - 1] == '.') {
        DFS(N, M, i, j - 1);
    }
    if (j < M and !visited[i][j + 1] and plan[i][j + 1] == '.') {
        DFS(N, M, i, j + 1);
    }
}

int count_rooms(const int &N, const int &M, int &rooms) {
    visited.resize(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] and plan[i][j] == '.') {
                DFS(N, M, i, j);
                rooms++;
            }
        }
    }
    return rooms;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, rooms = 0;
    cin >> N >> M;
    plan.resize(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> plan[i][j];
        }
    }
    cout << count_rooms(N, M, rooms);
    return 0;
}
