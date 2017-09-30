#include <bits/stdc++.h>
#define lld long long int

using namespace std;

struct tile{
    int a, b, c, d;
    lld p;

    tile(){
    }

    tile(int a, int b, int c, int d, lld p){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->p = p;
    }

    bool operator<(const tile o) const{
        if(a != o.a)
            return a < o.a;
        else if(b != o.b)
            return b < o.b;
        else if(c != o.c)
            return c < o.c;
        else if(d != o.d)
            return d < o.d;
        return p > o.p;
    }
};

tile rotateTile(tile t){
    return tile(t.b, t.c, t.d, t.a, t.p);
}

tile minTile(tile t){
    tile aux = rotateTile(t);
    t = min(t, aux);
    aux = rotateTile(aux);
    t = min(t, aux);
    aux = rotateTile(aux);
    t = min(t, aux);
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    int i, j;

    cin >> n >> k;
    while(n != 0){

        tile t;
        int **A = new int * [n];
        multiset<tile> S;

        for(i = 0; i < k; i++){
            cin >> t.a >> t.b >> t.d >> t.c >> t.p;
            t = minTile(t);
            S.insert(t);
        }

        for(i = 0; i < n; i++){
            A[i] = new int[n];
            for(j = 0; j < n; j++)
                cin >> A[i][j];
        }

        lld ans = 0;
        for(i = 0; i < n; i+= 2)
            for(j = 0; j < n; j+= 2){
                t = tile(A[i][j], A[i][j+1], A[i+1][j+1], A[i+1][j], INT_MAX);
                t = minTile(t);

                multiset<tile>::iterator it = S.lower_bound(t);
                if(it == S.end() || it->a != t.a || it->b != t.b || it->c != t.c || it->d != t.d){
                    ans = -1;
                    i = n;
                    break;
                }

                ans += it->p;
                S.erase(it);
            }

        cout << ans << "\n";

        cin >> n >> k;
    }

    return 0;
}
