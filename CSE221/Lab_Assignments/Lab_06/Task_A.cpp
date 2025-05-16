#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<short> visited;
deque<int> res;
bool cycleDetection;

void dfs(int V){
    visited[V] = -1;
    for(auto i: AL[V]){
        if (visited[i] == 0) dfs(i);
        else if (visited[i] == -1){
            cycleDetection = true;
            return;
        }
    }
    visited[V] = -2;
    res.push_front(V+1);
}

void topoSort(int N){
    for (int i = 0; i < N; i++){
        if (!visited[i]) dfs(i);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    AL.resize(N);
    visited.assign(N, false);

    for (int i = 0; i < M; i++){
        int A,B;
        cin >> A >> B;
        AL[A-1].push_back(B-1);
    }
    topoSort(N);

    if (cycleDetection) {
        cout << -1;
    } else {
        for (int i : res) {
            cout << i << ' '; 
        }
    }
    return 0;
}