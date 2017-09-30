#include <bits/stdc++.h>
using namespace std;


void stackPermutations(stack<char> s, string op, string a, string b, string target){
    if(op.size() == 8 ){
        if(b == target){
            for(int i = 0; i < 7; i++)
                cout << op[i] << " ";
            cout << op[7] << "\n";
        }
        return;
    }

    //cout << op << " " << a << " " << b << "\n";

    if( a != "" ){
        s.push( a[0] );
        string aux = a.substr( 1, a.size() - 1 );
        stackPermutations(s, op + "i", aux, b, target );
        s.pop();
    }

    if( !s.empty() ){
        char aux = s.top();
        s.pop();
        stackPermutations(s, op + "o", a, b + aux, target);
        s.push(aux);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    string a, b;
    int i;

    cin >> n;
    for(i = 0; i < n; i++){
        cin >> a >> b;
        cout << "Output for " << a << " " << b << "\n[\n";

        stack<char> s;
        stackPermutations( s, "", a, "", b );
        cout << "]\n";
    }

    return 0;
}
