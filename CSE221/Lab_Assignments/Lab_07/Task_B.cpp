#include <bits/stdc++.h>
using namespace std;

void djikstraPQ(int S, int N, const vector<vector<pair<int, long long>>>& AL, vector<long long>& dist){
    dist.assign(N, LLONG_MAX);
    dist[S] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, S});
    while(!pq.empty()){
        auto [w_0,u] = pq.top(); pq.pop();
        if (dist[u] < w_0) continue;
        for(auto[v,w]: AL[u]){
            if (dist[u] + w >= dist[v]) continue;
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
    
    for (int i = 0; i < M; i++){
        int u,v;
        long long w;
        cin >> u >> v >> w;
        u--;v--;
        AL[u].push_back({v, w});
    }
    if (S == D){
        cout << "0 " << S+1;
        return 0;
    }
    vector<long long> dist1;
    djikstraPQ(S, N, AL, dist1);

    vector<long long> dist2;
    djikstraPQ(D, N, AL, dist2);

    long long minTime = LLONG_MAX; int minNode = -1;  
    for (int i = 0; i < N; i++){
        if (dist1[i] != LLONG_MAX && dist2[i] != LLONG_MAX){
            long long time = max(dist1[i],dist2[i]);
            if (time < minTime || (time == minTime && i+1 < minNode)){
                minNode = i + 1;
                minTime = time;
            }
        }
    }
    if (minNode != -1) cout << minTime << ' ' << minNode;
    else cout << "-1";

    return 0;
}

