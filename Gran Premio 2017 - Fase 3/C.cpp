#include <bits/stdc++.h>
#define lld long long int
using namespace std;

lld h, n, b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> h) {
        cin >> b;
        n = (1ll << h) - 1;
        b = n - b + 1;
        stack < int > pila;
        while(b) {
            pila.push(b & 1);
            b >>= 1;
        }
        pila.pop();
        cout << "Instructions: ";
        while(!pila.empty()) {
            cout << (char)(pila.top() ? 'R' : 'L');
            pila.pop();
        }
        cout << "\n";
    }
    return 0;
}
