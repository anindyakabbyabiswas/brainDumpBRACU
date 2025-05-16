#include <bits/stdc++.h>
using namespace std;

set<int> AL [26];
short inDegree[26];
bool present[26];
vector<char> res;


void topoSort(){
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < 26; i++)
        if (present[i] && inDegree[i] == 0)
            pq.push(i);
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        res.push_back(x+'a');
        for (int y: AL[x]){
            inDegree[y]--;
            if (inDegree[y] == 0){
                pq.push(y);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    res.reserve(26);

    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    for (int i = 0; i < N; i++) for (char c: S[i]) present[c-'a'] = true;
        
    for (int i = 1; i < N; i++){
        string& s1 = S[i-1];
        string& s2 = S[i];
        int len = min(s1.size(), s2.size());
        bool found = false;
        for (int j = 0; j < len; j++){
            if (s1[j] != s2[j]){
                found = true;
                if (AL[s1[j]-'a'].find(s2[j]-'a') == AL[s1[j]-'a'].end()){
                    inDegree[s2[j]-'a']++;
                    AL[s1[j]-'a'].insert(s2[j]-'a');
                }
                break;
            }
        }
        if (!found && s1.size() > s2.size()){
            cout << "-1";
            return 0;
        }
    }
    topoSort();

    for (int i = 0; i < 26; i++) {
        if (present[i] && inDegree[i] > 0){
            cout << "-1";
            return 0;
        }
    }
    for (char c: res) {
        cout << c;
    }
    return 0;
}