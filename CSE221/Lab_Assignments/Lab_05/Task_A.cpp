#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using AL = vector<forward_list<int>>; 

AL graph; 
vector<bool> visited;


void bfs (int x){
    queue<int> track;
    track.push(x);
    visited[x] = true;

    while (!track.empty()){
        x = track.front();
        track.pop();
        cout << x+1 << " ";
        for (auto next: graph[x]){
            if (visited[next] == false){
                track.push(next);
                visited[next] = true;
            }    
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;
    graph.resize(V);
    visited.assign(V, false);
    
    for (int i = 0; i < E; i++){
        int x,y;
        cin >> x >> y;
        graph[x-1].push_front(y-1);
        graph[y-1].push_front(x-1);
    }
    bfs(0);
    return 0;

}