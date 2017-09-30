#include <bits/stdc++.h>
#define lld long long int
#define IZQ (nodo * 2)
#define DER (nodo * 2 + 1)
using namespace std;
const int MAXN = 100002;

int n, m;
lld arr[MAXN];
lld suma[MAXN];
lld dp[MAXN];
pair < int, pair < lld, lld > > recarga[MAXN];

lld sum(lld a, lld b) { return suma[b] - suma[a - 1]; }

lld _min(lld a, lld b) {
    if(a < 0 || b < 0) return a < 0 ? b : a;
    return a < b ? a : b;
}

struct segment_tree {
    int tree[MAXN * 5];

    void init(int nodo = 1, int l = 1, int r = n){
        if(l == r) tree[nodo] = -1;
        else {
            int med = (l + r) / 2;
            init(IZQ, l, med);
            init(DER, med +1, r);
            tree[nodo] = _min(tree[IZQ], tree[DER]);
        }
    }

    void update(int nodo, int ini, int fin, const int &p, const int &v) {
        if(p < ini || p > fin) return;
        if(ini == fin) {
            tree[nodo] = v;
        } else {
            int med = (ini + fin) / 2;
            update(IZQ, ini, med, p, v);
            update(DER, med + 1, fin, p, v);
            tree[nodo] = _min(tree[IZQ], tree[DER]);
        }
    }
    void update(int p, int v) { update(1, 1, n, p, v); }

    int query(int nodo, int ini, int fin, const int &i, const int &j) {
        if(fin < i || ini > j) return -1;
        if(ini >= i && fin <= j) {
            return tree[nodo];
        } else {
            int med = (ini + fin) / 2;
            return _min(query(IZQ, ini, med, i, j), query(DER, med + 1, fin, i, j));
        }
    }
    int query(int i, int j) { return query(1, 1, n, i, j); }
} ST;

int upperBound(int i, lld s) {
    int l = i, r = n + 1;
    while(l < r) {
        int med = (l + r) / 2;
        if(sum(i, med) <= s) l = med + 1;
        else r = med;
    }
    return l;
}

void solve(pair < int, pair < lld, lld > > p) {
    int i = p.first;
    lld s = p.second.first, c = p.second.second;
    if(s < arr[i]) return;
    int l = i + 1;
    int r = upperBound(i, s);
    lld minimo = ST.query(l, r);
    if(r > n) minimo = 0;
    if(minimo == -1) return;
    dp[i] = _min(dp[i], minimo + c);
    ST.update(i, dp[i]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n) {
        cin >> m;
        fill(dp, dp + n + 1, -1);
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            suma[i] = suma[i - 1] + arr[i];
            ST.update(i, -1);
        }
        suma[n + 1] = INT_MAX;
        for(int i = 1; i <= m; i++)
            cin >> recarga[i].first >> recarga[i].second.first >> recarga[i].second.second;
        sort(recarga + 1, recarga + m + 1);
        for(int i = m; i > 0; i--) {
            solve(recarga[i]);
        }
        cout << dp[1] << "\n";
    }
    return 0;
}
