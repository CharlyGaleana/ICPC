#include <bits/stdc++.h>
using namespace std;

bool possible(long long * A, int n, long long maxV, int k){
    int cont = 0;
    long long sum = 0;
    int i;

    for(i = 0; i < n; i++){
        if(A[i] > maxV)
            return false;

        sum += A[i];
        if(sum > maxV){
            cont++;
            sum = A[i];
        }
    }

    cont++;

    return cont <= k;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    int i;

    const long long maxv = 1000000000000;

    while(cin >> n){
        cin >> k;

        long long * A = new long long [n];
        for(i = 0; i < n; i++)
            cin >> A[i];


        long long b = 1, e = maxv, m;
        while(b != e){
            //cout << b << " " << e << "\n";

            m = (b + e) / 2;
            //cout << m << "\n";

            if(possible( A, n, m, k ))
                e = m;
            else
                b = m + 1;

        }

        //cout << possible(A, n, 3, k) << "\n" ;
        cout << b << "\n";

    }
    return 0;
}
