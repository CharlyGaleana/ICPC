#include <bits/stdc++.h>
#define llf long double
#define x first
#define y second
using namespace std;
typedef pair < llf, llf > pto;

llf sqr(llf x) { return x * x; }
llf dist(pto a, pto b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }

llf interseccion_x(pto f1, pto f2, llf y) {
	if(f1.x == f2.x) return f1.x;
	llf m = (f1.y - f2.y) / (f1.x - f2.x);
	llf b = f1.y - m * f1.x;
	return (y - b) / m;
}

pto min_point_in_elipse(pto f1, pto f2, llf L) {
	llf r = min(f1.y, f2.y), l = r - L;
	llf x, y;
	for(int i = 0; i < 200; i++) {
		y = (l + r) / 2;
		if(dist(f1, {f2.x, 2*y - f2.y}) <= L) r = y;
		else l = y;
	}
	y = (r + l) / 2;
	x = interseccion_x(f1, {f2.x, 2*y - f2.y}, y);
	return {x, y};
}

int main() {
	pto f1, f2;
	llf L;
	while(cin >> f1.x) {
		cin >> f1.y >> f2.x >> f2.y >> L;
		pto r = min_point_in_elipse(f1, f2, L);
		cout << setprecision(6) << fixed << r.x << " " << r.y << "\n";
	}
	return 0;
}