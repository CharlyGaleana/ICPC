#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    int i, j;
    while(cin >> n){
        long long * A = new long long[n];
        long long * ans = new long long[n];
        
        for(i = 0; i < n; i++)
            cin >> A[i];
        sort(A, A + n);
        
        ans[0] = A[0];
        j = 0;
        for(i = 1; i < n; i += 2)
            ans[++j] = A[i];
        if(i == n) i--;
        else i -= 3;
        for(; i > 1; i -= 2)
            ans[++j] = A[i];
        
        long long area = 0;
        for(i = 0; i < n - 1; i++)
            area += ans[i] * ans[i + 1];
        area += ans[0] * ans[n - 1];
        
        cout << fixed << setprecision(3);
        cout << (long double)(area) / 2 * sin( (2 * M_PI) / n )<< "\n";
    }
    return 0;
}

