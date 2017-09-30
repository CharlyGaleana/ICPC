#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n) {
        if(!n) break;
        int r = 0;
        for(int a = 1; a <= n; a++) {
            for(int b = a; b <= n; b++) {
                int c = a * a + b * b;
                int root = sqrt(c);
                if(n >= root && root * root == c) r++;
            }
        }
        cout << r << "\n";
    }
    return 0;
}
