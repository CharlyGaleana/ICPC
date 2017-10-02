#include <bits/stdc++.h>

using namespace std;

int n, m;

void color(int i, int j, int ** M, bool ** vis, int c){
	if(i < 0 || j < 0 || i == n || j == m)
		return;
	if(vis[i][j] || M[i][j] != c)
		return;
	
	vis[i][j] = true;
	color(i + 1, j, M, vis, c);
	color(i - 1, j, M, vis, c);
	color(i, j + 1, M, vis, c);
	color(i, j - 1, M, vis, c);
}

int newFace(int a, int b, int c, int d){
	if(a == b){
		if(c != d) 
			return 1;
		return 0;
	}	
	
	if(c != d){
		if(a < b){
			if(c < d){
				if(c >= b || d <= a)
					return 1;
				return 0;
			} else 
				return 1;
		} else {
			if(c > d){
				if(d >= a || c <= b)
					return 1;
				return 0;
			} else
				return 1;
		}
	}
	
	return 0;
}

int main(){
	//ios_base::sync_with_stdio(0);cin.tie(0);
	int i, j;
	
	while(cin >> n){
		cin >> m;
		int ** M = new int * [n];
		bool ** vis = new bool * [n];
		
		for(i = 0; i < n; i++){
			M[i] = new int [m];
			vis[i] = new bool [m];
			for(j = 0; j < m; j++){
				cin >> M[i][j];
				vis[i][j] = false;
			}
		}
		
		int faces = 5;
		
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				if(!vis[i][j]){
					color(i, j, M, vis, M[i][j]);
					faces++;	
				}
		
		int a, b, c, d;
		for(i = 0; i < n - 1; i++){
			a = b = 0;
			for(j = 0; j < m; j++){
				c = M[i][j]; d = M[i + 1][j];
				
				faces += newFace(a, b, c, d);
				
				a = c; b = d;
			}
		}
			
		for(j = 0; j < m - 1; j++){
			a = b = 0;
			for(i = 0; i < n; i++){
				c = M[i][j]; d = M[i][j + 1];
				
				faces += newFace(a, b, c, d);
				
				a = c; b = d;
			}
		}
		
		cout << faces << "\n";
	}	
	
	return 0;
}