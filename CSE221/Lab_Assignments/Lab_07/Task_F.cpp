#include <bits/stdc++.h>
using namespace std;

int N, M, S, D;
vector<vector<pair<int, int>>> AL;
vector<vector<long long>> dist;



long long djikstra2NDPath(int S, int D){

    dist.assign(N, vector<long long>(2, LLONG_MAX));
    dist[S][0] = 0;
    dist[S][1] = LLONG_MAX;
    
    int count[N] = {0};

    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, -S);

    while (!pq.empty()){
        auto [w_0, u] = pq.top(); pq.pop();
        w_0 = -w_0; u = -u;
        count[u] ++;
        if (u == D && count[D] == 2) return w_0;
        if (count [u] > 2) continue;
        for (auto [v, w] : AL[u]){
            if (w + w_0 < dist[v][0]){
                dist[v][1] = dist[v][0];
                dist[v][0] = w + w_0;
                pq.emplace(-dist[v][0], -v);
            } else if ((w + w_0 > dist[v][0]) && (w + w_0 < dist[v][1])){
                dist[v][1] = w + w_0;
                pq.emplace(-dist[v][1], -v);
            }
        }

    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> S >> D;
    S--; D--;

    AL.resize(N);
    for (int i = 0; i < M; i++){
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        AL[u].push_back({v, w});
        AL[v].push_back({u, w});
    }

    cout << djikstra2NDPath(S, D);


    return 0;
}

