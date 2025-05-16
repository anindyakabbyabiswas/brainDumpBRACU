#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, S, D;
    cin >> N >> M >> S >> D;

    vector<vector<int>> graph(N);

    vector<int> u(M), v(M);
    for (int i = 0; i < M; i++) cin >> u[i];
    for (int i = 0; i < M; i++) cin >> v[i];

    for (int i = 0; i < M; i++) {
        graph[u[i] - 1].push_back(v[i] - 1);
        graph[v[i] - 1].push_back(u[i] - 1);
    }

    for (int i = 0; i < N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> visited(N, false);
    vector<int> parent(N, -1);

    queue<int> q;
    int src = S - 1, dest = D - 1;
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }

    if (!visited[dest]) {
        cout << "-1\n";
        return 0;
    }
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v])
        path.push_back(v + 1);
    
    reverse(path.begin(), path.end());

    cout << path.size() - 1 << "\n";
    for (int node : path) cout << node << " ";
    cout << "\n";

    return 0;
}
