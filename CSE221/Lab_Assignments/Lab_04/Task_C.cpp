#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    int adMat[N][N] = {};

    for (int i = 0; i < N; i++){
        int inp;
        std::cin >> inp;
        for (int j = 0; j < inp; j++){
            int temp;
            std::cin >> temp;
            adMat[i][temp] = 1;
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            std::cout << adMat[i][j] << " ";
        }
        std::cout << "\n";
    }  
    return 0;
}