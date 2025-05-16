#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph; 
vector<int> visit1;
vector<int> visit2;

void bfs (int x, vector<int>& visited){
    queue<int> track;
    track.push(x);
    visited[x] = -1;
    while (!track.empty()){
        x = track.front();
        track.pop();
        for (auto next: graph[x]){
            if (visited[next] == -2){
                track.push(next);
                visited[next] = x;
            }    
        }
    }
}

int main(){
    // Fast IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input the graph (Considering undirected graph)
    int N, M, S, D, K;
    cin >> N >> M >> S >> D >> K;
    S--;
    D--;
    K--;
    graph.resize(N);
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u-1].push_back(v-1);
    }
    for (int i = 0; i < N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    if (D == K){
        visit1.assign(N, -2);
        bfs(S, visit1);
    } else if (S == K) {
        visit2.assign(N, -2);
        bfs(K, visit2);
    } else{
        visit1.assign(N, -2);
        bfs(S, visit1);
        visit2.assign(N, -2);
        bfs(K, visit2);
    }

    if ((D == K) && visit1[K] != -2){
        vector<int> path_left;
        int n = K;
        while (n != -1) {
            path_left.push_back(n + 1);
            n = visit1[n];
        }
        cout << path_left.size() - 1 << "\n";
        for (int i = path_left.size()-1; i >= 0; i--) {
            cout<< path_left[i] << " ";
        }
    } else if ((S == K) && visit2[D] != -2){
        vector<int> path_right;
        int n = D;
        while (n != -1) {
            path_right.push_back(n + 1);
            n = visit2[n];
        }
        cout << path_right.size() - 1 << "\n";
        for (int i = path_right.size()-1; i >= 0; i--) {
            cout<< path_right[i] << " ";
        }
    } else if (visit1[K] != -2 && visit2[D] != -2){
        vector<int> path_left;
        int n = K;
        while (n != -1) {
            path_left.push_back(n + 1);
            n = visit1[n];
        }
        vector<int> path_right;
        n = D;
        while (n != -1) {
            path_right.push_back(n + 1);
            n = visit2[n];
        }
        cout << path_right.size() + path_left.size() - 2 << "\n";
        for (int i = path_left.size()-1; i >= 0; i--) {
            cout<< path_left[i] << " ";
        }
        for (int i = path_right.size()-2; i >= 0; i--) {
            cout<< path_right[i] << " ";
        }
    } else{
        cout <<"-1\n";
    }

    return 0;
}