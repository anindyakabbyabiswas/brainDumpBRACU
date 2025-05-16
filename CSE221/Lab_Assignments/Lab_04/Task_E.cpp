#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    int diff [N] = {};
    int temp;
    for (int i = 0; i < M; i++) {
        std::cin >> temp;
        diff[temp-1]--;
    }
    for (int i = 0; i < M; i++) {
        std::cin >> temp;
        diff[temp-1]++;
    }
    
    for (int i = 0; i < N; i++) {
        std::cout << diff[i] << " ";
    }
    std::cout << "\n";
    return 0;
}