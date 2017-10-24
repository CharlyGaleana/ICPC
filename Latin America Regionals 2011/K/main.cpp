#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int g[3];
    while(cin >> g[0] >> g[1] >> g[2]) {
        if(g[0] == 0) break;
        sort(g, g + 3);
        if(g[0] == g[1] && g[1] == g[2]) {
            // Tercia
            if(g[0] == 13) cout << "*\n";
            else cout << g[0]+1 << " " << g[0]+1 << " " << g[0]+1 << "\n";
        } else {
            if(g[0] == g[1] || g[1] == g[2]) {
                //Par
                if(g[0] == g[1]) swap(g[0], g[2]);
                //g0 es distinto
                if(g[0] == 13) {
                    g[1] = ++g[2];
                    g[0] = 1;
                } else {
                    g[0]++;
                    if(g[0] == g[1]) {
                        if(g[0] == 13) g[0] = g[1] = g[2] = 1;
                        else g[0]++;
                    }
                }
                sort(g, g + 3);
                cout << g[0] << " " << g[1] << " " << g[2] << "\n";
            } else {
                //Nada
                cout << "1 1 2\n";
            }
        }
    }
    return 0;
}
