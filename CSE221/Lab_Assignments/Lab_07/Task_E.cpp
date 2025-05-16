#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> AL;
vector<vector<long long>> dist;



long long djikstraPQ(int S, int D){
    if (S == D) return 0;
    dist.assign(N, vector<long long>(2, LLONG_MAX));
    dist[S][0] = 0;
    dist[S][1] = 0;
    bool destiReach[2] = {false, false};
    priority_queue<tuple<long long, int, int>> pq;
    pq.push({-0, -S, -(-1)});
    while(!pq.empty()){
        auto [w_0, u, parity] = pq.top(); pq.pop();
        w_0 = -w_0; u = -u; parity = -parity;
        if (u == D && parity != -1) destiReach[parity] = 1;
        if (destiReach[0] && destiReach[1]) return (min(dist[D][0], dist[D][1]));
        if (parity!=-1 && dist[u][parity] < w_0) continue;
        for(auto [v,w]: AL[u]){
            int edgeParity = w&1;
            if(parity != -1 && parity == edgeParity) continue; 
            if (w_0 + w >= dist[v][edgeParity]) continue;
            dist[v][edgeParity] = w_0 + w;
            pq.push({-dist[v][edgeParity], -v, -edgeParity});
        }
    }
    return (min(dist[D][0], dist[D][1]) == LLONG_MAX ? -1 : min(dist[D][0], dist[D][1]));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    int u[M], v[M], w[M];
    for (int i = 0; i < M; i++) cin >> u[i];
    for (int i = 0; i < M; i++) cin >> v[i];
    for (int i = 0; i < M; i++) cin >> w[i];
    AL.resize(N);
    for (int i = 0; i < M; i++){
        AL[u[i]-1].push_back({v[i]-1, w[i]});
    }

    cout << djikstraPQ(0, N-1);


    return 0;
}

