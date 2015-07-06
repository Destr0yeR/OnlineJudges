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

void bs(int n, int t, int l, int r, long long _t[]){
    bool flag = check(t, _t[0]);
    int mid;
    while( r-l > 1){
        mid = (r+l)/2;
        if(check(t, _t[mid])){
            if(flag){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        else{
            if(flag){
                r = mid;
            }
            else{
                l = mid;
            }
        }
    }
    if(_t[r] > t){
        cout << 0 << endl;
    }
    else{
        cout << n - r << endl;
    }
}

int main()
{
    int n, t;

    cin >> n >> t;

    long long _t[n];

    for(int i = 0; i < n; ++i){
        cin>>_t[i];
    }

    for(int i = n-2 ; i >= 0 ; --i){
        _t[i] += _t[i+1];
    }

    bs(n, t, 0, n-1, _t);

    return 0;
}
