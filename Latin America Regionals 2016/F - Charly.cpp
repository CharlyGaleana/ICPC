#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, c, s;
    int i;
    
    while(cin >> n){
        cin >> c >> s;
        
        int ans = 0, pos = 1, mov;
       
        for(i = 0; i < c; i++){
            if(pos == s)
                ans++;
            
            cin >> mov;
            pos += mov;
            if(pos > n) pos = 1;
            if(pos == 0) pos = n;
        }
        if(pos == s)
            ans++;
        
        cout << ans << "\n";
    }
    
    return 0;
}

