#include <bits/stdc++.h>
using namespace std;

#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back

typedef unsigned long long ull;

bool check(int t, long long _t){
    return _t <= t;
}

int bs(int t, int l, int r, long long p[]){
    long long offset = p[l-1];
    if(!check(t, p[l] - offset))return 0;
    int ini = l;
    while(r-l > 1){
        int mid = (l+r)/2;

        if(check(t, p[mid]-offset)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return r-ini;
}

int main()
{
    int n, t;

    cin >> n >> t;

    long long a[n+2], acumulado[n+2];

    for(int i = 1; i <= n; ++i){
        cin>>a[i];
    }
    a[n+1] = t+1;
    acumulado[0] = 0;

    for(int i = 1 ; i <= n ; ++i){
        acumulado[i] = acumulado[i-1] + a[i];
    }
    int maxi = 0;
    for(int i = 1 ; i <= n ; ++i){
        int aux = bs(t, i , n+1 , acumulado);
        maxi = max(maxi, aux);
    }

    cout << maxi << endl;

    return 0;
}
