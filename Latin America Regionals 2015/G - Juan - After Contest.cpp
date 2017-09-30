#include <bits/stdc++.h>
using namespace std;
typedef long double llf;
const int MAXN = 1002;

int n, m;
vector < pair < int, pair < int, int > > > adj[MAXN];

bool v[MAXN];
llf evaluate(llf t) {
    priority_queue < pair < llf, int > > monti;
    fill(v, v + MAXN, false);
    llf c = 0;
    int nodo = 1;
    monti.push({-c, nodo});
    while(!monti.empty()) {
        tie(c, nodo) = monti.top();
        monti.pop();
        if(v[nodo]) continue;
        v[nodo] = true;
        if(nodo == n) return -c;
        for(int i = 0; i < adj[nodo].size(); i++)
            monti.push({c - (adj[nodo][i].second.first * t + adj[nodo][i].second.second), adj[nodo][i].first});
    }
    return 0;
}

llf maxTax(llf ini, llf fin) {
    llf l, r;
    for(int i = 0; i < 100; i++) {
        l = (2*ini + fin) / 3;
        r = (ini + 2*fin) / 3;
        if(evaluate(l) < evaluate(r)) ini = l;
        else fin = r;
    }
    return (l + r) / 2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n >> m) {
        for(int i = 0; i < m; i++) {
            int u, v, a, b;
            cin >> u >> v >> a >> b;
            adj[u].push_back({v, {a, b}});
            adj[v].push_back({u, {a, b}});
        }
        llf t = maxTax(0, 24 * 60);
        cout << setprecision(5) << fixed << evaluate(t) << "\n";
        for(int i = 1; i <= n; i++) adj[i].clear();
    }
    return 0;
}
