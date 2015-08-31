#include<bits/stdc++.h>

#define err 1e-15

#define mset(x,y) memset(x, y, sizeof(x))

using namespace std;
typedef long long ll;
typedef long double ld;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    ld x;
    cin >> x;
    ll n, d;
    d = 100;
    int _x = int(x);
    while(abs(x - _x)> err){
		cout << x << " " << _x << endl;
        x*=10;
        d*=10;
        _x = int(x);
    }
    n = int(x);
    
    if(n == 0)cout << 0 << endl;
    else cout << d/gcd(n, d) << endl;
    
    return 0;
}
