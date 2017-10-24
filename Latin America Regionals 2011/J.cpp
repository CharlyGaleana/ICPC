#include <bits/stdc++.h>

using namespace std;

struct BIT{
	
	long long * bit;
	long long n;
	long long mod;
	
	BIT(int n, long long mod){
		this->n = n;
		this->mod = mod;
		bit = new long long[n + 2];
		fill(bit, bit + n + 2, 0);
	}
	
	void update(int x, long long v){
		for( ; x <= n; x += (x & -x) )
			bit[x] = (bit[x] + mod + v) % mod;
	}
	
	long long query(int x){
		if(x==0) return 0;
		
		long long ret = 0;
		for(; x; x -= (x & -x) )
			ret = (ret + bit[x]) % mod;
		return ret;
	}
	
	long long query(int l, int r){
		if(l > r) return 0;
		return (query(r) - query(l - 1) + mod) % mod;
	}
	
};

long long power(long long x, int n, long long mod){
	if(n == 0)
		return 1;
	
	if(n % 2)
		return (x * power(x, n - 1, mod)) % mod;
	long long aux = power(x, n / 2, mod);
	return (aux * aux) % mod;
}

int main () {
	//
	
	int i;
	long long B, P, L, N;
	cin >> B >> P >> L >> N;
	
	while(B){
		char op;
		BIT * bit = new BIT(L, P);
		long long * pot = new long long[L];
		long long * potinv = new long long[L];
		long long * A = new long long[L + 2];
		fill(A, A + L + 2, 0);
		
		pot[0] = 1;
		potinv[0] = 1;	
		for(i = 1; i < L; i++){
			pot[i] = (pot[i - 1] * B) % P;
			potinv[i] = power(pot[i], P - 2, P);
		}
		
		long long a, b;
		for(i = 0; i < N; i++){
			cin >> op >> a >> b;
			
			if(op == 'E'){
				bit->update(a, -A[a]);
				A[a] = (b * pot[L - a]);
				bit->update(a, A[a]);
			} else {
				long long ans = bit->query(a, b);
				ans *= potinv[L - b];
				ans %= P;
				cout << ans << "\n";
			}
			
		}
		cout << "-\n";
		
		cin >> B >> P >> L >> N;
	}

}