#include <bits/stdc++.h>
using namespace std;

string minString(int bucket[], int l){
    string ret = "";

    int B[10];
    for(int i = 0; i <= 9; i++)
        B[i] = bucket[i];

    int pos = 0;
    while(l){
        while(!B[pos])
            pos++;

        ret += char(pos + '0');
        B[pos]--;
        l--;
    }

    return ret;
}

string maxString(int bucket[], int l){
    string ret = "";

    int B[10];
    for(int i = 0; i <= 9; i++)
        B[i] = bucket[i];

    int pos = 9;
    while(l){
        while(!B[pos])
            pos--;

        ret += char(pos + '0');
        B[pos]--;
        l--;
    }

    return ret;
}

long long stringToNum(string a){
    long long ret = 0;

    for(int i = 0; i < a.size(); i++){
        ret *= 10;
        ret += (long long)(a[i] - '0');
    }

    return ret;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);

    string num;
    int i, j;

    while(cin >> num){
        string ans = "";

        int B[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
        for(i = 0; i < num.size(); i++){
            int n = num[i] - '0';

            if(B[n]){
                B[n]--;
                if(minString(B, num.size() - i - 1) <= num.substr(i + 1, num.size() - i - 1) )
                    ans += char(n + '0');
                else
                    B[n]++;
            }

            if(ans.size() <= i){
                j = n - 1;
                while(!B[j])
                    j--;

                ans += char(j + '0');
                B[j]--;

                ans += maxString(B, num.size() - i - 1);
                break;
            }

        }

        cout << stringToNum( ans ) << "\n";
    }

    return 0;
}
