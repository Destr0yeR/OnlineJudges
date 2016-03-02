#include<bits/stdc++.h>

using namespace std;


int a[27];

bool cmp(int a, int b){return a > b;}

int main(){

    int n;

    cin >> n;

    for(int i = 0 ; i < n ; ++i)cin >> a[i];

    sort(a, a + n, cmp);

    long long last = LLONG_MAX;

    long long ans = 0LL;

    for(int i = 0 ; i < n ; ++i){
        if(last == 1)break;
        if(a[i] >= last)a[i] = last-1;
        ans += a[i];
        last = a[i];
    }

    cout << ans << endl;

    return 0;
}
