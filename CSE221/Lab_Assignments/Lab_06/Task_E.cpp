#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<long long int> dist;

void dfs(int u, long long cur_dist) {
    dist[u] = cur_dist;
    for (int i : graph[u]) {
        if (dist[i] == -1){
            dfs(i, cur_dist+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    graph.resize(N);
    dist.assign(N, -1);
    
    for (int i = 0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0, 0);
    int longestPathEnd = max_element(dist.begin(), dist.end()) - dist.begin();

    fill(dist.begin(), dist.end(), -1);
    dfs(longestPathEnd, 0);
    int longestPathStart = max_element(dist.begin(), dist.end()) - dist.begin();

    cout<< dist[longestPathStart] << '\n';
    cout<< longestPathEnd+1 << ' ' << longestPathStart+1;
    cout << "\n";
    

    return 0;
}

