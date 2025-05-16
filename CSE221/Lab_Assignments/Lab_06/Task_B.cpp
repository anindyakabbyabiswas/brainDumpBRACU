#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<short> visited;
int bfsMOD (int x){
    queue<int> track;
    track.push(x);
    visited[x] = -1;
    
    int playerU = 1;
    int playerV = 0;

    while (!track.empty()){
        x = track.front();
        track.pop();
        for (auto next: AL[x]){
            if (!visited[next]){
                track.push(next);
                if (visited[x] == -1){
                    visited[next] = 1;
                    playerV++;
                } else{
                    visited[next] = -1;
                    playerU++;
                }
            }    
        }
    }
    return max(playerU, playerV);
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    AL.resize(N);
    visited.assign(N, 0);

    for (int i = 0; i < M; i++){
        int A,B;
        cin >> A >> B;
        AL[A-1].push_back(B-1);
        AL[B-1].push_back(A-1);
    }
    int res=0;
    for (int i = 0; i < N; i++){
        if (!visited[i]) res+=bfsMOD(i);
    }
    cout << res;
}