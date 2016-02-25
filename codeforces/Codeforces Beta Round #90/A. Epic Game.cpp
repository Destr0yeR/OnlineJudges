#include<bits/stdc++.h>

#define gcd(x,y) __gcd(x,y)

using namespace std;

int main()
{
    int a, b, n, g;

    cin >> a >> b >> n;

    while(true){
        g = gcd(a,n);
        if(g > n){
            cout << "1\n";
            break;
        }
        n-=g;
        g = gcd(b,n);
        if(g > n){
            cout << "0\n";
            break;
        }
        n-=g;
    }

    return 0;
}
