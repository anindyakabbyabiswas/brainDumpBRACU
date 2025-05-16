#include <bits/stdc++.h>
using namespace std;

void djikstraPQ(int S, int D, int N, const vector<vector<pair<int, long long>>>& AL, vector<int>& visited, vector<long long>& dist){
    visited.assign(N,-1);
    dist.assign(N, LLONG_MAX);
    dist[S] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, S});
    while(!pq.empty()){
        auto [w_0,u] = pq.top(); pq.pop();
        if (u==D) return;
        if (dist[u] < w_0) continue;
        for(auto[v,w]: AL[u]){
            if (dist[u] + w >= dist[v]) continue;
            visited[v] = u;
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, S, D;
    cin >> N >> M >> S >> D;
    S--;D--;

    vector<vector<pair<int, long long>>> AL(N);

    int u[M], v[M];
    long long w[M];

    for (int i = 0; i < M; i++) cin >> u[i];
    for (int i = 0; i < M; i++) cin >> v[i];
    for (int i = 0; i < M; i++) cin >> w[i];

    for (int i = 0; i < M; i++){
        AL[u[i]-1].push_back({v[i]-1, w[i]});
    }
    
    vector<int> visited;
    vector<long long> dist;
    djikstraPQ(S, D, N, AL, visited, dist);


    if (visited[D] == -1 && S!=D) {
        cout << "-1\n";
    } else {
        cout << dist[D] << "\n";

        vector<int> route;
        route.reserve(N);
        for (int i = D; i!=-1; i = visited[i]) route.push_back(i+1);
        reverse(route.begin(), route.end());

        for (auto i: route) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}

