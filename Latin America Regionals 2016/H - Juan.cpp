#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    while(cin >> n >> k) {
        int cnt = 0;
        priority_queue < int > monti;
        lld res = 0;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if(cnt >= k) {
                monti.push(-x);
                cnt -= k;
            } else {
                cnt++;
                if(monti.empty() || -monti.top() > x) {
                    res += x;
                } else {
                    res += -monti.top(); //quito punto
                    monti.pop();
                    monti.push(-x);
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}