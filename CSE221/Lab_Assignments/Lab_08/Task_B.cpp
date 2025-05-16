#include <bits/stdc++.h>
using namespace std;

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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,K;
    cin>> N >> K;

    DisjointSet helpingKingforNoReason(N);

    tuple<int, int, int> edges[K];
    for (int i = 0; i < K; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, --u, --v};
    }
    
    sort(edges, edges+K);
    int count = 0;
    long long cost = 0;
    for (int i = 0; i < K; i++){
        auto [w, u, v] = edges[i];
        if (helpingKingforNoReason.find(u) == helpingKingforNoReason.find(v)) continue;
        helpingKingforNoReason.unite(u, v);
        cost += w*1LL;
        count += 1;
        if (count == N-1){
            cout << cost;
            return 0;
        }
    }

    return 0;
}

