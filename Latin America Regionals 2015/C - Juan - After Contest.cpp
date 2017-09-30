#include <bits/stdc++.h>
#define lld long long int
#define x first
#define y second
using namespace std;
const int MAXN = 100002;
typedef pair < lld, lld > pto; 

int n;
pto arr[MAXN];

pto operator-(pto a, pto b) { return {a.x - b.x, a.y - b.y}; } 

lld cross(pto p, pto q) { return p.x * q.y - q.x * p.y; }
lld areaTriangle(pto a, pto b, pto c) { return abs(cross(b - a, c - a)); }

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n) {
		for(int i = 0; i < n; i++) 
			cin >> arr[i].x >> arr[i].y;
		lld A = 0;
		for(int i = 1; i < n - 1; i++) 
			A += areaTriangle(arr[0], arr[i], arr[i + 1]);
		
		int j = 1;
		lld areaAct = 0, maxArea = 0;
		for(int i = 0; i < n; i++) {
			while(2 * areaAct < A) {
				areaAct += areaTriangle(arr[i], arr[j], arr[(j + 1) % n]);
				j = (j + 1) % n;
			}
			if(A - areaAct > areaAct - areaTriangle(arr[i], arr[j], arr[(j - 1 + n) % n])) {
				//Me conviene elegir j
				maxArea = max(maxArea, areaAct);
			} else {
				//Me conviene la j anterior
				areaAct -= areaTriangle(arr[i], arr[j], arr[(j - 1 + n) % n]);
				j = (j - 1 + n) % n;
				maxArea = max(maxArea, A - areaAct);
			}
			areaAct -= areaTriangle(arr[i], arr[(i + 1) % n], arr[j]);
		}
		cout << maxArea << " " << A - maxArea << "\n";
	}
	
	return 0;
}