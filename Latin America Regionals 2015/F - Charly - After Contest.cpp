#include <bits/stdc++.h>

using namespace std;

struct Bit{
	long long * B;
	int * array;
	int n;
	
	Bit(int * A, int n){
		array = new int[n], B = new long long[n + 2];
		for(int i = 0; i < n; i++) array[i] = A[i];
		sort(array, array + n);
		n = unique(array, array + n) - array;
		this->n = n;
		fill(B, B + n + 2, 0);
	}
	
	~Bit(){
		delete B;
		delete array;
	}
	
	int find(int x){
		return lower_bound(array, array + n, x) - array;
	}
	
	void update(int x, int v){ 
		x = find(x) + 1;
		for(; x <= n; x += (x & -x))
			B[x] += (long long)v;
	}
	
	long long query(int x){
		x++;
		if(x <= 0) return 0;
		long long ret = 0;
		for(; x; x -= (x & -x))
			ret += B[x];
		return ret;
	}
	
	long long query(int l, int r){
		int x = find(l);
		int y = find(r);
		if(y >= n) y--;
		if(array[y] > r) y--;
		if(y < x) return 0;
		
		return query(y) - query(x - 1);
	}
};

struct Query{
	int l, r, h, idx;
	
	Query(){}
	
	Query(int l, int r, int h, int idx) : l(l), r(r), h(h), idx(idx) {}
};

bool operator<(Query a, Query b){
	return a.h < b.h;
}

struct pnt{
	int x, y, idx;
};

bool operator<(pnt a, pnt b){
	return a.y < b.y;
}

int main(){
//	ios_base::sync_with_stdio(0);cin.tie(0);
	
	int P, V;
	int i, j;
	
	while(cin >> P){
		cin >> V;
		
		int n = P, Q = 0;
		int * X = new int[P], * pointsUnder = new int[V];
		pnt * plants = new pnt[P];
		pnt * poly = new pnt[V];
		Query * querys = new Query[V];
		fill(pointsUnder, pointsUnder + V, 0);
		
		for(i = 0; i < P; i++){
			cin >> plants[i].x >> plants[i].y;
			plants[i].idx = i;
			X[i] = plants[i].x;
		}
		
		for(i = 0; i < V; i++){
			cin >> poly[i].x >> poly[i].y;
			if(i > 0)
				if(poly[i].y == poly[i - 1].y)
					querys[Q++] = Query( min(poly[i].x, poly[i - 1].x), max(poly[i].x, poly[i - 1].x) - 1, poly[i].y, i );
		}
		if(poly[0].y == poly[V - 1].y)
			querys[Q++] = Query( min(poly[0].x, poly[V - 1].x), max(poly[0].x, poly[V - 1].x) - 1, poly[0].y, 0 );
	
		sort(querys, querys + Q);
		sort(plants, plants + P);
		Bit *  BIT = new Bit(X, n);
		n = BIT->n;
		
		j = 0;
		for(i = 0; i < Q; i++){
			while(j < P && plants[j].y < querys[i].h){
				BIT->update(plants[j].x, plants[j].idx + 1);
				j++;
			}
			
			pointsUnder[querys[i].idx] = BIT->query(querys[i].l, querys[i].r);
		}
		
		long long lim = ((long long)P * (long long)(P + 1)) / 2;
		long long ans = lim;
		for(i = 0; i < V; i++){
			pnt ant = i == 0 ? poly[V - 1] : poly[i - 1];
			if(poly[i].y == ant.y){
				if(poly[i].x > ant.x)
					ans += (long long) pointsUnder[i];
				else
					ans -= (long long) pointsUnder[i];
				//cout << ans << "\n";
			}
		}
		
		if(ans <= lim)
			cout << ans << "\n";
		else 
			cout << 2 * lim - ans << "\n";
		
	}
	
}