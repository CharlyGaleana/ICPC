#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, b, mp;

    while(cin >> n){
        cin >> m;

        int points = 0, maxPoints = 0;
        for(int i = 0; i < m; i++){
            cin >> b;
            cin >> mp;

            int sum = mp, p;
            for(int j = 1; j < n; j++){
                cin >> p;
                sum += p;
            }

            if(sum <= b) {
                points += mp;

                sum -= mp;
                while(sum + mp <= b && mp <= 10000){
                    mp *= 10;
                }

                mp/=10;

                maxPoints += mp;
            } else {
                sum -= mp;

                while(sum + mp > b && mp)
                    mp /= 10;

                maxPoints += mp;
            }

            //cout << "hola " << mp << "\n";
        }

        cout << maxPoints - points << "\n";
    }

    return 0;
}
