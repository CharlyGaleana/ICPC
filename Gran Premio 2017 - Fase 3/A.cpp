#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1002;

int n, k;
int suff[MAXN][4][MAXN];
int preff[MAXN][4][MAXN];
string s[MAXN];
int dp[MAXN];

int f(char c) {
    switch(c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'T': return 2;
        case 'G': return 3;
    }
    return 0;
}

void init(int i) {
    for(int c = 0; c < 4; c++) {
        fill(preff[i][c], preff[i][c] + s[i].size(), 0);
        fill(suff[i][c], suff[i][c] + s[i].size(), 0);
    }
    preff[i][f(s[i][0])][0]++;
    for(int m = 1; m < s[i].size(); m++) {
        for(int c = 0; c < 4; c++)
            preff[i][c][m] = preff[i][c][m - 1];
        preff[i][f(s[i][m])][m]++;
    }
    suff[i][f(s[i][s[i].size()-1])][s[i].size()-1]++;
    for(int m = s[i].size()-2; m >= 0; m--) {
        for(int c = 0; c < 4; c++)
            suff[i][c][m] = suff[i][c][m + 1];
        suff[i][f(s[i][m])][m]++;
    }
}

bool take(int i, int j) {
    if(s[i].size() < k || s[j].size() < k) return false;
    for(int c = 0; c < 4; c++) {
        if(suff[i][c][s[i].size() - k] != preff[j][c][k - 1])
            return false;
    }
    return true;
}

int f(int i) {
    if(i >= n) return 0;
    if(dp[i] == -1) {
        dp[i] = 0;
        for(int j = i + 1; j < n; j++) {
            if(take(i, j))
                dp[i] = max(dp[i], f(j));
        }
        dp[i]++;
    }
    return dp[i];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    for(cin >> T; T; T--) {
        cin >> n >> k;
        n++;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
            init(i);
        }
        fill(dp, dp + n, -1);
        cout << f(0) - 1 << "\n";
    }
    return 0;
}
