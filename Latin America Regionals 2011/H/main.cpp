#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10002;

int n, m, q;
vector < int > adj[MAXN];

bool uniquePath(int nodo, int fin) {
    int t[n + 1] = {0};
    int cnt[n + 1] = {0};

    queue < int > cola;
    cola.push(nodo);
    cnt[nodo] = 1;
    t[nodo] = 1;
    while(!cola.empty()) {
        nodo = cola.front();
        cola.pop();
        if(nodo == fin) return cnt[nodo] == 1;
        for(int i = 0; i < adj[nodo].size(); i++) {
            if(!t[adj[nodo][i]] || t[adj[nodo][i]] == t[nodo] + 1) {
                if(!t[adj[nodo][i]]) {
                    cola.push(adj[nodo][i]);
                    t[adj[nodo][i]] = t[nodo] + 1;
                }
                cnt[adj[nodo][i]] += cnt[nodo];
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n >> m >> q) {
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            cout << (uniquePath(a, b) ? 'Y' : 'N') << "\n";
        }
        cout << "-\n";
    }
    return 0;
}
