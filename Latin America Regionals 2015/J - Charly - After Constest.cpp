#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long POW(long long x, int n){
	if(n == 0)
		return 1;
	if(n % 2)
		return (x * POW(x, n - 1)) % mod;
	
	long long ret = POW(x, n/2);
	return (ret * ret) % mod;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	
	long long n, k, q;
	long long i, t;
	
	while(cin >> n){
		cin >> q;
		
		long long * C = new long long[n];
		C[0] = 1;
		for(i = 1; i < n; i++)
			C[i] = ( (C[i - 1] * (n - i + 1)) % mod * POW(i, mod - 2)) % mod; 
		
		for(i = 0; i < q; i++){
			cin >> k;
			k = min(n, k);
			long long ans = 0;
			
			for(t = 0; t < k; t++){
				ans += ((t % 2) ? -1 : 1 ) * (C[t] * POW(k - t, n)) % mod;
				ans %= mod;
			}
			ans = (ans + mod) % mod;
			
			cout << ans;
			if(i == q - 1)
				cout << "\n";
			else
				cout << " ";
		}
	}
	
} 