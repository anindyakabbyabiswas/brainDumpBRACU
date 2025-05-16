#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> AL;
class DisjointSet{
    private:
        int* parent;
        int* size;
    public:
        DisjointSet (int N){
            parent = new int [N];
            size = new int [N];
            for (int i = 0; i < N; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }
        int find(int x){
            if (this->parent[x] == x) return x;
            return this->parent[x] = find(this->parent[x]);
        }
        void unite (int x, int y){
            int x_par = this->find(x);
            int y_par = this->find(y);
            if (x_par == y_par) return;
            if (this->size[x_par] > this->size[y_par]){
                swap(x_par, y_par);
            }
            this->parent[x_par] = y_par;
            this->size[y_par] += this->size[x_par];
        }
        int parentSize(int x){
            return this->size[this->find(x)];
        }
        ~DisjointSet() {
            delete[] parent; 
            delete[] size;
        }

    
};

int dfs(int u, int v, int p, int maxWeight) {
    if (u == v) return maxWeight;

    for (auto [neigh, w] : AL[u]) {
        if (neigh == p) continue; 
        int res = dfs(neigh, v, u, max(maxWeight, w));
        if (res != -1) return res;
    }
    return -1;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin>> N >> K;

    DisjointSet mst(N);
    AL.assign(N, {});

    tuple<int, int, int, bool> edges[K];
    for (int i = 0; i < K; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, --u, --v, 0};
    }
    
    sort(edges, edges+K);
    int count = 0;
    long long bestMST = 0;
    for (int i = 0; i < K; i++){
        auto [w, u, v, truth] = edges[i];
        if (mst.find(u) == mst.find(v)) continue;
        edges[i] = {w, u, v, 1};
        AL[u].push_back({v, w});
        AL[v].push_back({u, w});
        mst.unite(u, v);
        bestMST += w*1LL;
        count += 1;
        if (count == N-1) break;
    }
    if (count != N-1){
        cout << -1;
        return 0; 
    }
    long long secondBestMST = LLONG_MAX;
    for (int i = 0; i < K; i++){
        auto [w, u, v, truth] = edges[i];
        if (!truth){
            int maxWeight = dfs(u, v, -1, -1);
            if (maxWeight != -1 && w > maxWeight){
                secondBestMST = min(secondBestMST, bestMST - (maxWeight - w) * 1LL);
            }
        }
    }
    cout << (secondBestMST == LLONG_MAX ? -1 : secondBestMST);

    return 0;
}

