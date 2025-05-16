#include <bits/stdc++.h>
using namespace std;

int N, M, S, D;
vector<vector<int>> AL;
vector<int> w;
vector<long long> dist;


long long djikstraPQ(int S, int D){

    dist.assign(N, LLONG_MAX); 
    dist[S] = w[S];

    priority_queue<pair<long long, int>> pq;
    pq.push({-w[S], -S});
    while(!pq.empty()){
        auto [w_0,u] = pq.top(); pq.pop();
        w_0 = -w_0; u = -u;
        if (u == D) return dist[D];
        if (dist[u] < w_0) continue;
        for(auto v: AL[u]){
            if (dist[u] + w[v] >= dist[v]) continue;
            dist[v] = dist[u] + w[v];
            pq.push({-dist[v], -v});
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> S >> D;
    S--; D--;

    w.resize(N);
    for (int i = 0; i < N; i++) cin>>w[i];

    AL.resize(N);
    for (int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        AL[u].push_back(v);
    }

    cout << djikstraPQ(S, D);


    return 0;
}
