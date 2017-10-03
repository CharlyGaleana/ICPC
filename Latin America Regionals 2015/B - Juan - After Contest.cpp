#include <bits/stdc++.h>
using namespace std;
const int MAXN = 202;

vector < int > adj[MAXN];
bool v[MAXN];
int match[MAXN];

bool alternating(int u) {
    if(v[u]) return false;
    v[u] = true;
    for(int i = 0; i < adj[u].size(); i++) {
        if(match[adj[u][i]] == -1 || alternating(match[adj[u][i]])) {
            match[adj[u][i]] = u;
            return true;
        }
    }
    return false;
}

int kuhn(int n) {
    fill(match, match + MAXN, -1);
    int s = 0;
    for(int i = 0; i < n; i++) {
        fill(v, v + n, false);
        if(alternating(i)) s++;
    }
    return s;
}

bool matchBloodGroup(vector < int > arr, vector < int > bg[ ], int n) {
    //Construimos grafo
    for(int i = 0; i < n; i++) adj[i].clear();
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < bg[j].size(); k++) {
                if(bg[j][k] == arr[i])
                    adj[j].push_back(i);
            }
        }
    }
    return kuhn(n) == arr.size();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    while(cin >> n >> m) {
        vector < int > arr[n];
        char conjuntoVacioPosible = 'Y';
        for(int i = 0; i < n; i++) {
            int k;
            cin >> k;
            if(k == n) conjuntoVacioPosible = 'N';
            for(int j = 0; j < k; j++) {
                int x;
                cin >> x;
                arr[i].push_back(x);
            }
        }
        for(int i = 0; i < m; i++) {
            int k;
            cin >> k;
            vector < int > test;
            if(!k) cout << conjuntoVacioPosible << "\n";
            else {
                for(int j = 0; j < k; j++) {
                    int x;
                    cin >> x;
                    test.push_back(x);
                }
                if(matchBloodGroup(test, arr, n)) cout << "Y\n";
                else cout << "N\n";
            }
        }
    }
    return 0;
}
