#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

bool cmp(int a, int b){
    return a < b;
}

int main()
{
    //freopen(" - in.txt", "r", stdin);
    //freopen(" - out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    ll n, l;

    cin >> n >> l;

    map<ll, ll> p;
    ll points[n+1];

    ll aux;
    ll cont = 0;

    for(int i = 0 ; i < n ; ++i){
        cin >> aux;
        if(!p[aux]){
            p[aux] = 1;
            points[cont++] = aux;
        }
    }

    sort(points, points + cont, cmp);

    ll maxi = -1000;

    ll last = -points[0];

    for(int i = 0 ; i < cont ; ++i){
        ll aux = abs(last- points[i]);
        maxi = max(maxi, aux);
        last = points[i];
    }

    maxi = max(maxi,2*(l- points[cont-1]));

    cout << setprecision(10)<<(maxi)*0.5 << endl;

    return 0;
}
