#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using AL = vector<forward_list<int>>; 

AL graph; 
vi visited;

void dfs(int v) {
    visited[v] = 1;
    cout << v+1 << " ";
    for (int next: graph[v])
        if (visited[next] == 0)
            dfs(next);
}


int main(){
    // Fast IO
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Input the graph (Considering undirected graph)
    int V, E;
    cin >> V >> E;
    graph.resize(V);
    visited.assign(V, false);
    
    int endpoint[2*E];
    for (int i = 0; i < 2*E; i++){
        cin >> endpoint[i];
    }
    for (int i = 0; i < E; i++) {
        int u = endpoint[i] - 1;
        int v = endpoint[E + i] - 1;
        graph[u].push_front(v);
        graph[v].push_front(u); 
    }

    dfs(0);
    return 0;
}