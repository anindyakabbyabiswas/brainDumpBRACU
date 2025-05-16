#include <bits/stdc++.h>
using namespace std;

#define posChecker(x,y,N) ((x) >= 0 && (x) < (N) && (y) >= 0 && (y) < (N))

vector<vector<int>> board;

int posX[8] = {-2,-2,-1,-1,1,1,2,2};
int posY[8] = {-1,1,-2,2,-2,2,-1,1};

void bfsMod(int x1, int y1, int x2, int y2, int N) {
    queue<pair<int,int>> query;
    board[y1][x1] = 0;
    query.push({x1,y1});
    while(!query.empty()){
        auto [x, y] = query.front(); query.pop();
        if (x == x2 && y == y2) return;
        for (int i = 0; i < 8; i++) {
            int newX = x + posX[i], newY = y + posY[i];
            if (posChecker(newX, newY, N) && board[newY][newX] == -1) {
                board[newY][newX] = board[y][x]+1;
                query.push({newX,newY});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    board.assign(N, vector<int>(N,-1));
    int x1,y1,x2,y2;
    cin >> x1>>y1>>x2>>y2;
    bfsMod(--x1,--y1,--x2,--y2, N);
    cout << board[y2][x2];

    return 0;
}
