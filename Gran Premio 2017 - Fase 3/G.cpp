#include <bits/stdc++.h>
using namespace std;
const int MAXN = 102;

int n;
int arr[MAXN];

int sol() {
    int mayor = INT_MIN;
    for(int i = 1; i <= n; i++) mayor = max(mayor, arr[i]);
    int c = 0, wrong = 0;
    for(int i = 1; i <= n; i++) {
        if(wrong) c++;
        if(arr[i] == mayor) {
            wrong ^= 1;
            if(wrong) c++;
        }
    }
    return c;
}

int main()
{
    int T;
    scanf("%d ", &T);
    for(int i = 1; i <= T; i++) {
        char c = ' ';
        n = 0;
        while(c != '\n') {
            scanf("%d%c", &arr[++n], &c);
        }
        printf("%d\n", sol());
    }
    return 0;
}
