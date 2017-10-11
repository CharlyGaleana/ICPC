#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100002;
typedef pair < int, int > pii;

int n, m, A, B;
vector < int > adj[MAXN];
int degree[MAXN];
set < pii > S;

void erase(int nodo) {
    S.erase({degree[nodo], nodo});
    degree[nodo] = -1;
    for(int i = 0; i < adj[nodo].size(); i++) {
        if(degree[adj[nodo][i]] == -1) continue;
        S.erase({degree[adj[nodo][i]], adj[nodo][i]});
        degree[adj[nodo][i]]--;
        S.insert({degree[adj[nodo][i]], adj[nodo][i]});
    }
}

void clear() {
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        degree[i] = 0;
    }
    S.clear();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n >> m >> A >> B) {
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        for(int i = 1; i <= n; i++) S.insert({degree[i], i});
        do {
            set < pii > :: iterator it;
            it = S.begin();
            if(it -> first < A) {
                erase(it -> second);
            } else {
                it = S.end();
                it--;
                if(S.size() - it -> first - 1 < B) {
                    erase(it -> second);
                } else break;
            }
        } while(S.size() >= 1);
        
        cout << S.size() << "\n";
        clear();
    }    
    return 0;
}

