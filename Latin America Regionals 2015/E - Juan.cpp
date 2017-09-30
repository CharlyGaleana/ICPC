#include <bits/stdc++.h>
using namespace std;
const int MAXN = 202;

int N;
int nA, nB, m, b;
int costo[MAXN];

int padre[MAXN];
int raiz(int nodo) {
    if(!padre[nodo]) return nodo;
    return padre[nodo] = raiz(padre[nodo]);
}

void join(int a, int b) {
    if(raiz(a) == raiz(b)) return;
    padre[raiz(a)] = raiz(b);
}

pair < int, pair < int, int > > arr[MAXN];

int dp[MAXN][10002];

int maxGroup(int i, int d) {
    if(i <= 0) return 0;
    if(dp[i][d] == -1) {
        dp[i][d] = maxGroup(i - 1, d) + arr[i].second.first;
        if(arr[i].first <= d)
            dp[i][d] = max(dp[i][d], maxGroup(i - 1, d - arr[i].first) + arr[i].second.second);
    }
    return dp[i][d];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> nA >> nB >> m >> b) {
        fill(padre, padre + nA + nB + 1, 0);
        for(int i = 1; i <= nA; i++) cin >> costo[i];
        for(int i = 1; i <= nB; i++) cin >> costo[i + nA];
        for(int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            b += nA;
            join(a, b);
        }
        N = nA + nB;
        for(int i = 1; i <= N; i++) arr[i] = {0, {0, 0}};
        for(int i = 1; i <= N; i++) {
            arr[raiz(i)].first += costo[i];
            if(i <= nA) arr[raiz(i)].second.first++;
            else arr[raiz(i)].second.second++;
        }
        for(int i = 0; i <= N; i++) fill(dp[i], dp[i] + b + 1, -1);
        cout << maxGroup(N, b) << " ";
        for(int i = 0; i <= N; i++) {
            fill(dp[i], dp[i] + b + 1, -1);
            swap(arr[i].second.first, arr[i].second.second);
        }
        cout << maxGroup(N, b) << "\n";
    }
    return 0;
}
