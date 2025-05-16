#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    int adMat[N][N] = {};

    for (int i = 0; i < M; i++){
        int x,y;
        std::cin >> x >> y;
        std::cin >> adMat[x-1][y-1];
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            std::cout << adMat[i][j] << " ";
        }
        std::cout << "\n";
    }  
    return 0;
}