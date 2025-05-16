#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    int data[3*M] = {};
    for (int i = 0; i < 3*M; i++) std::cin >> data[i];

    std::forward_list<std::pair<int,int>> adList [N];

    for (int i = 0; i < M; i++) adList[data[M-1-i]-1].push_front({data[2*M-1-i], data[3*M-1-i]});
    

    for (int i = 0; i < N; i++){
        std::cout<<i+1<<": ";
        for (auto pair: adList[i]){
            std::cout<<"("<< pair.first << "," << pair.second <<") ";
        }
        std::cout<<"\n";
    }  
    return 0;
}