#include <bits/stdc++.h>
using namespace std;

void djikstraPQ(int S, int N, const vector<vector<pair<int, int>>>& AL, vector<int>& dist){
    dist.assign(N, INT_MAX);
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, S});
    while(!pq.empty()){
        auto [w_0,u] = pq.top(); pq.pop();
        if (dist[u] < w_0) continue;
        for(auto[v,w]: AL[u]){
            int newWeight = max(dist[u],w);
            if (newWeight >= dist[v]) continue;
            dist[v] = newWeight;
            pq.push({dist[v], v});
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> AL(N);
    
    for (int i = 0; i < M; i++){
        int u,v;
        int w;
        cin >> u >> v >> w;
        u--;v--;
        AL[u].push_back({v, w});
        AL[v].push_back({u, w});
    }

    vector<int> dist;
    djikstraPQ(0, N, AL, dist);

    for (auto i: dist) 
        if (i != INT_MAX) cout << i << ' ';
        else cout << -1 << ' ';
    

    return 0;
}

