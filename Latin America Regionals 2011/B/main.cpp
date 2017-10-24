#include <bits/stdc++.h>
#define DER (nodo * 2 + 1)
#define IZQ (nodo * 2)
using namespace std;
const int MAXN = 1002;

set < int > S, C;// SET y COMPLEMENT;
set < int > :: iterator it;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q;
    while(cin >> n >> q) {
        if(n == 0 && q == 0) break;
        S.clear();
        for(int i = 1; i <= n + 1; i++) {
            S.insert(i);
            C.insert((n + 1) - i);
        }
        for(int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;
            for(int j = a; j <= b; j++) {
                S.erase(j);
                C.erase((n + 1) - j);
            }

            it = C.upper_bound((n + 1) - a);
            if((n + 1) - *it < a) cout << (n + 1) - *it << " ";
            else cout << "* ";

            it = S.upper_bound(b);
            if(*it <= n) cout << *it << "\n";
            else cout << "*\n";
        }
        cout << "-\n";
    }
    return 0;
}
