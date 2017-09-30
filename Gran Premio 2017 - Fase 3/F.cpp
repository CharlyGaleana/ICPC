#include <bits/stdc++.h>
using namespace std;

int T;

int n, m;
int v[32][32];
char arr[32][32];

void busqueda(int i, int j, int &c) {
    if(i <= 0 || j <= 0 || i > n || j > m) return;
    if(v[i][j] == T || arr[i][j] == '1') return;
    v[i][j] = T;
    c++;
    busqueda(i + 1, j, c);
    busqueda(i - 1, j, c);
    busqueda(i, j + 1, c);
    busqueda(i, j - 1, c);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 32; i++) fill(v[i], v[i]+32, -1);
    for(cin >> T; T; T--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> arr[i][j];
            }
        }
        int r = 0;
        for(int i = 1; i <= n; i++) {
            busqueda(i, 1, r);
            busqueda(i, m, r);
        }
        for(int j = 1; j <= m; j++) {
            busqueda(1, j, r);
            busqueda(n, j, r);
        }
        cout << r << "\n";
    }
    return 0;
}
