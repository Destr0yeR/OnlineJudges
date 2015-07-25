#include<bits/stdc++.h>

using namespace std;

int costo[101][2];


int n, k, d;

int dp(int falta , int visitado){
    int rpta;
    if(falta == 0){
        return visitado;
    }

    rpta = costo[falta][visitado];

    if(rpta > -1){
        return rpta;
    }

    int acu = 0;

    for(int i = 1 ; i <= k ; ++i){
        int v = visitado|(i>=d);
        if(falta>=i){
            acu += dp(falta-i, v);
            acu %= 1000000007;
        }
    }
    rpta = acu;
    costo[falta][visitado] = rpta;
    return rpta;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin >> n >> k >> d;

    memset(costo, -1, sizeof(costo));

    cout << dp(n,0) << endl;

    return 0;
}
