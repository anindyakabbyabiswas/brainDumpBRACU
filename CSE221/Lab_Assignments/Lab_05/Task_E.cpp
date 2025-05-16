#include <bits/stdc++.h>
using namespace std;
using AL = vector<forward_list<int>>; 

AL graph; 
vector<bool> visited;
vector<bool> stackVisit;

bool dfs_Cycle_detector (int x){
    visited[x] = true;
    stackVisit[x] = true;
    for (int next: graph[x]){
        if (visited[next] == false){
            if (dfs_Cycle_detector(next)){
                return true;
            }
        } else if (stackVisit[next]){
            return true;
        }
    }
    stackVisit[x] = false;
    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;
    graph.resize(V);
    visited.assign(V, false);
    stackVisit.assign(V, false);
    
    for (int i = 0; i < E; i++){
        int x,y;
        cin >> x >> y;
        graph[x-1].push_front(y-1);
    }

    for (int i = 0; i < V; i++){
        if (!visited[i]){
            if (dfs_Cycle_detector(i)){
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
    return 0;

}