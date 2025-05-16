#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<int> treeSize;

int dfs(int V){
    treeSize[V] = 1;
    for(auto i: AL[V]){
        if (treeSize[i] == -1)
            treeSize[V] += dfs(i);
    }
    return treeSize[V];
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, R;
    cin >> N >> R;
    AL.resize(N);


    for (int i = 0; i < N-1; i++){
        int u,v;
        cin >> u >> v;
        AL[u-1].push_back(v-1);
        AL[v-1].push_back(u-1);
    }
    
    treeSize.assign(N, -1);
    dfs(R-1);

    int Q;
    cin>>Q;
    while(Q--){
        int X;
        cin >> X;
        cout << treeSize[--X] << '\n';
    }

    return 0;
}