#include <bits/stdc++.h>

std::bitset<2001> adjMattrix[2001];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, Q;
    std::cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; ++j) {
            if (std::__gcd(i, j) == 1) {
                adjMattrix[i][j] = adjMattrix[j][i] = true;
            }
        }
    }
    while (Q--) {
        int x, k;
        std::cin >> x >> k;
        if (k < N){
            for (int i = 1; i <= N; i++){
                if (adjMattrix[x][i]){
                    k--;
                    if (k == 0){
                        std::cout<< i << "\n";
                        break;
                    }
                }
            }
            if (k > 0){
                std::cout<< -1 << "\n";
            }
        } else {
            std::cout<< -1 << "\n";
        }
    }
    return 0;
}