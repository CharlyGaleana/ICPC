#include <bits/stdc++.h>
using namespace std;

int M[10] = {14, 1, 5, 3, 11, 9, 7, 15, 13, 6};

char getChar(int i, int p) {
    if(i & (1 << p)) return '*';
    else return '.';
}

int f(char c) {
    if(c == '*') return 1;
    else return 0;
}

void print(string &s) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < s.size(); j++) {
            cout << getChar(M[s[j] - '0'], 2*i) << getChar(M[s[j] - '0'], 2*i + 1);
            if(j < s.size() - 1) cout << " ";
        }
        cout << "\n";
    }
}

int find(int x) {
    for(int i = 0; i < 10; i++)
        if(M[i] == x) return i;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int D;
    while(cin >> D) {
        if(D == 0) break;
        char c;
        cin >> c;
        if(c == 'S') {
            string s;
            cin >> s;
            print(s);
        } else {
            char arr[3][2 * D];
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 2*D; j++)
                    cin >> arr[i][j];
            for(int i = 0; i < 2*D; i += 2) {
                int num = find(f(arr[0][i]) + 2*f(arr[0][i + 1]) + 4*f(arr[1][i]) + 8*f(arr[1][i + 1]));
                cout << num;
            }
            cout << "\n";
        }
    }
    return 0;
}
