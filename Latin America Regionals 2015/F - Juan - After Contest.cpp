#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long int lld;
const int MAXN = 100002;

int n, m;
pair < int, int > plantas[MAXN];
pair < int, int > poligono[MAXN];

vector < pair < pair < int, int >, int > > ptos;
vector < pair < int, pair < int, int > > > lineas;

struct bit {
    int tree[MAXN * 2];
    map < int, int > mapYs;

    void init() {
        vector < int > arr;
        for(int i = 0; i < n; i++) arr.push_back(plantas[i].y);
        for(int i = 0; i < m; i++) arr.push_back(poligono[i].y);
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++) mapYs[arr[i]] = i + 1;
    }

    void update(int pos, int v) {
        for(; pos < MAXN * 2; pos += pos&(-pos)) tree[pos] += v;
    }
    void update(int i, int j, int v) {
        i = mapYs[i];
        j = mapYs[j];
        update(i, 1);
        update(j, -1);
    }

    int query(int pos) {
        int c = 0;
        for(; pos; pos -= pos&(-pos)) c += tree[pos];
        return c;
    }
    int cnt(int y) { return query(mapYs[y]); }

} BIT;

void insertRange(pair < int, int > p) { BIT.update(p.first, p.second, 1); }
void eraseRange(pair < int, int > p) { BIT.update(p.first, p.second, -1); }

lld sweep_line() {
    lld res = 0;
    int i = 0, j = 0;
    int x; // x a procesar
    while(i < ptos.size() || j < lineas.size()) {
  	x = INT_MAX;
      	if(i < ptos.size()) x = min(x, ptos[i].first.x);
      	if(j < lineas.size()) x = min(x, lineas[j].x);
      	//Procesa Lineas
      	while(j < lineas.size() && lineas[j].x == x) {
      	    insertRange(lineas[j].second);
      	    j++;
      	}
      	//Procesa Puntos
		while(i < ptos.size() && ptos[i].first.x == x) {
			if(!(BIT.cnt(ptos[i].first.y) & 1)) res += ptos[i].second;
			i++;
		}
    }
    //Limpia BIT
    for(j = 0; j < lineas.size(); j++) eraseRange(lineas[j].second);
    return res;
}

lld pointsInsidePolygon() {
	ptos.clear();
	lineas.clear();
	for(int i = 0; i < n; i++) ptos.push_back({plantas[i], i + 1});
	for(int i = 0; i < m; i++) {
	   if(poligono[i].x != poligono[(i + 1) % m].x) continue;
	   int y1 = poligono[i].y, y2 = poligono[(i + 1) % m].y;
	   if(y1 > y2) swap(y1, y2);
	   lineas.push_back({poligono[i].x, {y1, y2}});
	}
	sort(ptos.begin(), ptos.end());
	sort(lineas.begin(), lineas.end());
	return sweep_line();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n >> m) {
		for(int i = 0; i < n; i++) cin >> plantas[i].x >> plantas[i].y;
		for(int i = 0; i < m; i++) cin >> poligono[i].x >> poligono[i].y;
		BIT.init();
		cout << pointsInsidePolygon() << "\n";
	}
	return 0;
}
