#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int A[4];
    while(cin >> A[0]){
        cin >> A[1] >> A[2] >> A[3];
        sort(A, A + 4);
        cout << abs( (A[0]+ A[3]) - (A[1] + A[2]) ) << endl;
    }
    return 0;
}

