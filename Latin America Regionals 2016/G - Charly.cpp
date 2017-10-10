#include <bits/stdc++.h>
#define MAX_N 500000
#define ull unsigned long long int
using namespace std;

string s;
int n;
int A[MAX_N];
ull hNum[28];
ull hStr[28];
int nxt[MAX_N + 2][28];
const ull b = 29;

ull myHash(int x){
    ull ret = 0;
    for(int i = 0; i < n; i++)
        ret = ret * b + (A[i] == x ? b : 0); 
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int i, j;
    
    while(cin >> s){
        cin >> n;
        
        for(i = 0; i < n; i++)
            cin >> A[i];
        
        for(i = 1; i <= 26; i++)
            hNum[i] = myHash(i);
      
        fill(hStr, hStr + 28, 0);
        for(i = 0; i < n; i++){
            int x = s[i] - 'a' + 1;
            for(j = 1; j <= 26; j++)
                hStr[j] = hStr[j] * b + (x == j ? b : 0);
        }
        
        ull B = 1;
        for(i = 0; i < n; i++)
            B *= b;
       
        fill(nxt[s.size()], nxt[s.size()] + 27, s.size());
        for(i = s.size() - 1; i >= 0; i--){
            for(j = 1; j <= 26; j++)
                nxt[i][j] = (nxt[i + 1][j]);
            nxt[i][s[i] - 'a' + 1] = i;
        }
        
        int ans = 0;
        for(i = 0; i + n < s.size(); i++){
            for(j = 1; j <= 26; j++)
                if(nxt[i][j] < i + n)
                    if(hStr[ nxt[i][j] ] != hNum[ A[nxt[i][j] - i] ])
                        break;
          
            if(j > 26)
                ans++;
            
            //actualizar hashes
            int x = s[i] - 'a' + 1;
            for(j = 1; j <= 26; j++)
                hStr[j] -= (x == j ? B : 0);
            
            int x = s[i + n] - 'a' + 1;
            for(j = 1; j <= 26; j++)
                hStr[j] = hStr[j] * b + (x == j ? b : 0);
        }
        
        for(j = 1; j <= 26; j++)
            if(hStr[ nxt[i][j] ] != hNum[ A[nxt[i][j] - i] ])
                break;
        if(j > 26)
            ans++;
        
        cout << ans << "\n";
        
    }
    
    return 0;
}

