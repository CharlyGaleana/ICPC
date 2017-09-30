#include <bits/stdc++.h>
using namespace std;

int n, m;
pair < int, pair < int, int > > E[10002];
int padre[102];

int root(int nodo) {
    if(padre[nodo] == nodo) return nodo;
    return padre[nodo] = root(padre[nodo]);
}

bool join(pair < int, int > p) {
    int a = root(p.first), b = root(p.second);
    if(a == b) return false;
    padre[a] = b;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    for(int caso = 1; caso <= T; caso++) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) padre[i] = i;
        for(int i = 0; i < m; i++)
            cin >> E[i].second.first >> E[i].second.second >> E[i].first;
        sort(E, E + m);
        reverse(E, E + m);
        int menor = INT_MAX;
        for(int i = 0; i < m; i++)
            if(join(E[i].second)) menor = E[i].first;
        if(menor == INT_MAX) menor = 0;
        cout << "Case #" << caso << ": " << menor << "\n";
    }
    return 0;
}
