#include <bits/stdc++.h>
#define MAX_N 10002
using namespace std;

int n, m, q;

int cont;

vector<int> E[MAX_N];
vector<int> B[MAX_N];

int vis[MAX_N], low[MAX_N], parent[MAX_N];
int c[MAX_N];

void bridge(int u){
	low[u] = vis[u] = ++cont;
	for(int i = 0; i < (int)E[u].size(); i++){
		int v = E[u][i];
		
		if(vis[v] == 0){
			parent[v] = u;
			bridge(v);
			
			if(low[v] > vis[u]){
				B[u].push_back(v);
				B[v].push_back(u);
				//cout << "bridge  " << u << " "  << v << "\n";
			}
			
			low[u] = min(low[u], low[v]);
		} else if(v != parent[u])
			low[u] = min(low[u], vis[v]);
		
	}
}

void components(int u, int color){
	c[u] = color;
	for(int i = 0; i < (int)B[u].size(); i++){
		int v = B[u][i];
		
		if(c[v] == 0)
			components(v, color);
	}
}



int main () {
	//ios_base::sync_with_stdio(0);cin.tie(0);
	
	cin >> n >> m >> q;
	while(n){
		cont = 0;
		fill(vis, vis + n + 1, 0);
		fill(low, low + n + 1, 0);
		fill(parent, parent + n + 1, 0);
		fill(c, c + n + 1, 0);
		for(int i = 1; i <= n; i++){
			E[i].clear();
			B[i].clear();
		}
		
		int a, b;
		for(int i = 1; i <= m; i++){
			cin >> a >> b;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		
		for(int i = 1; i <= n; i++){
			if(vis[i] == 0)
				bridge(i);
		}
		
		int color = 0;
		for(int i = 1; i <= n; i++){
			if(!c[i])
				components(i, ++color);
		}
		
		for(int i = 1; i <= q; i++){
			cin >> a >> b;
			if(c[a] == c[b])
				cout << "Y\n";
			else
				cout << "N\n";
		}
		cout << "-\n";
		
		cin >> n >> m >> q;
	}
}