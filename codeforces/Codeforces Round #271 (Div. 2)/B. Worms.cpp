#include<bits/stdc++.h>

using namespace std;

int bs(int _find, int a[], int n){
    int l = 0;
    int r = n+1;
    int mid;

    while(r-l > 1){
        mid = (l+r)/2;
        if(a[mid] >= _find){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    return r;
}

int main()
{
    //freopen(" - in.txt", "r", stdin);
    //freopen(" - out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n;
    cin >> n;

    int a[n+1];

    a[0] = 0;

    for(int i = 1 ; i <= n ; ++i){
        cin>>a[i];
        a[i]+=a[i-1];
    }

    int m;
    cin >> m;
    int q[m];

    for(int i = 0 ; i < m ; ++i)cin >> q[i];

    for(int i = 0 ; i < m ; ++i){
        cout << bs(q[i], a, n) << endl;
    }

    return 0;
}
