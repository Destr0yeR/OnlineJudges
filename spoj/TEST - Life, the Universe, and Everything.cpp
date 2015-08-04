#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen(" - in.txt", "r", stdin);
    //freopen(" - out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int n;
    bool encontrado = false;

    while(cin >> n){
        if(n == 42)encontrado = true;
        if(!encontrado)cout << n << endl;
    }
    return 0;
}
