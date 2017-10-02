#include <bits/stdc++.h>
#define lli long long int
using namespace std;

struct PT {
    lli x, y;
    PT(){};
    PT(lli x, lli y) : x(x), y(y) {};
    PT operator - (const PT &p) const { return PT(x - p.x, y - p.y); }
};

lli crossP(PT x, PT y){
    return (x.x * y.y) - (x.y * y.x);
}

lli triangleArea(PT x, PT y, PT z){
    return abs( crossP(x - y, z - y) );
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    int i, j;

    while(cin >> n){
        vector<PT> pts;
        pts.resize(n);
        lli ans = 0;

        for(i = 0; i < n; i++)
            cin >> pts[i].x >> pts[i].y;

        double area = 0;
        lli areaT;
        //calcular area total
        for(i = 1; i < n - 1; i++)
            area += triangleArea(pts[0], pts[i], pts[i + 1]);
        areaT = area;
        area /= 2;

        //barrido
        lli areaAct = 0, areaAnt;
        //pair<lli, lli> optimo = make_pair(0, 1);
        j = 1;
        for(i = 0; i < n; i++){
            while((double)areaAct < area){
                areaAnt = areaAct;
                areaAct += triangleArea(pts[i], pts[j], pts[ (j + 1) % n ]);
                j++;
                j %= n;
            }

            if( abs(area - (double)areaAct) < abs(area - (double)areaAnt) )
                ans = max( ans, max( areaAct, areaT - areaAct ) );
            else {
                ans = max( ans, max( areaAnt, areaT - areaAnt ) );
                areaAct = areaAnt;
                j = (j - 1 + n) % n;
            }

            areaAct -= triangleArea(pts[i], pts[(i + 1) % n], pts[j]);
        }

        cout << ans << " " << areaT - ans << "\n";
    }
    return 0;
}
