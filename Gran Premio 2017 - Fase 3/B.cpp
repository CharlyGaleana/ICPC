#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n, m;
    int i, j;

    cin >> t;

    while(t){
        cin >> n;

        int **DP = new int * [n];
        int *A = new int [n];

        for(i = 0; i < n; i++){
            cin >> A[i];
            DP[i] = new int[2];
        }

        for(i = 0; i < n; i++)
            for(j = 0; j < 2; j++)
                DP[i][j] = 0;

        for(i = n - 1; i >= 0; i--){
            for(j = i + 1; j < n; j++)
                if(A[j] < A[i])
                    DP[i][1] = max( DP[i][1], DP[j][1] );
            DP[i][1]++;

            DP[i][0] = DP[i][1];
            for(j = i + 1; j < n; j++)
                if(A[j] > A[i])
                    DP[i][0] = max(DP[i][0], DP[j][0] + 1);
        }

        int ans = 0;
        for(i = 0; i < n; i++)
            ans = max(ans, max(DP[i][0], DP[i][1]) );

        cout << ans << "\n";

        t--;
    }
    return 0;
}
