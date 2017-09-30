#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> T) {
        int cnt = 0;
        for(int i = 0; i < 5; i++) {
            int x;
            cin >> x;
            if(x == T) cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
