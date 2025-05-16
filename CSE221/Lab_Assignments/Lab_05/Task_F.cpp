#include <bits/stdc++.h>
using namespace std;

#define posChecker(x,y,W,H) ((x) >= 0 && (x) < (W) && (y) >= 0 && (y) < (H))

vector<vector<int>> graph;

int posX[4] = {-1,0,0,1};
int posY[4] = {0,1,-1,0};

int solve(int x, int y, int W, int H) {
    queue<pair<int,int>> query;
    int maxDiamonds = graph[y][x];
    graph[y][x] = -1;
    query.push({x,y});
    while(!query.empty()){
        auto [x, y] = query.front(); query.pop();
        for (int i = 0; i < 4; i++) {
            int newX = x + posX[i], newY = y + posY[i];
            if (posChecker(newX, newY, W, H) && graph[newY][newX] != -1) {
                maxDiamonds += graph[newY][newX];
                graph[newY][newX] = -1;
                query.push({newX,newY});
            }
        }
    }
    return maxDiamonds;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;
    graph.assign(H, vector<int>(W,-1));

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            char alp;
            cin >> alp;
            if (alp == '.'){
                graph[y][x] = 0;
            } else if (alp == 'D'){
                graph[y][x] = 1;
            }
        }
    }

    int maxDiamonds = 0;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (graph[y][x] != -1) {
                maxDiamonds = max(maxDiamonds, solve(x, y, W, H));
            }
        }
    }
    cout<<maxDiamonds;
    return 0;
