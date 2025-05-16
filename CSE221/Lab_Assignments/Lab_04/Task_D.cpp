#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned N, M;
    std::cin >> N >> M;
    unsigned degree[N] = {};
    unsigned temp;
    for (unsigned i = 0; i < 2*M; i++) {
        std::cin >> temp;
        degree[temp-1]++;
    }

    unsigned count = 0;
    for (unsigned int i = 0; i < N; i++) {
        if ((degree[i] % 2) != 0){
            count++;
        }
    }
    if (count == 0 || count == 2){
        std::cout << "YES" << "\n";
    } else {
        std::cout << "NO" << "\n";
    }
    
    return 0;
}