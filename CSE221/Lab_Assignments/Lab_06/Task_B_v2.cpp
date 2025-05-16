#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int visited[N] = {0};

    while(M--){
        int u, v;
        cin >> u >> v;
        u--;v--;
        if (visited[u] == 0 &&  visited[v] == 0){
            visited[u] = -1;
            visited[v] = -2;
        } else if (visited[u] == 0){
            if (visited[v] == -1) visited[u] = -2;
            else visited[u] = -1;
        } else if (visited[v] == 0){
            if (visited[u] == -1) visited[v] = -2;
            else visited[v] = -1;
        }
    }

    int robot = 0, hoomans = 0, nonDetect = 0;

    for (int i = 0; i < N; i++){
        if (visited[i] == -1) robot++;
        else if (visited[i] == -2) hoomans++;
        else nonDetect++;
    }

    cout << max(robot, hoomans)+nonDetect;


}