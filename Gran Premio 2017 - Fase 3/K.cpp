#include <bits/stdc++.h>
using namespace std;

int n;
bool adj[12][12];
int color[12];

int check(int a[ ]) {
    int mayor = 0;
    fill(color + 1, color + n + 1, 0);
    for(int i = 0; i < n; i++) {
        int nodo = a[i];
        int nextColor = 0;
        for(int j = 1; j <= n; j++)
            if(adj[nodo][j]) nextColor = max(nextColor, color[j]);
        color[nodo] = ++nextColor;
        mayor = max(mayor, nextColor);
    }
    return mayor;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> n) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                adj[i][j] = false;

        for(int i = 1; i <= n; i++) {
            int m;
            for(cin >> m; m; m--) {
                int x;
                cin >> x;
                adj[i][x] = adj[x][i] = true;
            }
        }
        int arr[n];
        for(int i = 0; i < n; i++) arr[i] = i + 1;
        int r = check(arr);
        while(next_permutation(arr, arr + n)) {
            r = min(r, check(arr));
        }
        cout << r << "\n";
    }
    return 0;
}
