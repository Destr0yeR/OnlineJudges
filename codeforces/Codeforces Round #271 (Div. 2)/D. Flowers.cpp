#include<bits/stdc++.h>

#define mod 1000000007
#define MAX 100001
using namespace std;

int t, k, a, b;


int res[MAX];
int sum[MAX];

int main()
{
    //freopen(" - in.txt", "r", stdin);
    //freopen(" - out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin >> t >> k;
    memset(res, 0, sizeof(res));

    res[0] = 1;
    sum[0] = 0;
    for(int i = 1 ; i < k ; ++i)res[i] = 1;

    for(int i = k ; i <= MAX ; ++i){
        res[i] = res[i-1] + res[i-k];
        res[i] %= mod;
    }

    for(int i = 1 ; i <= MAX ; ++i){
        sum[i] = res[i] + sum[i-1];
        sum[i] %= mod;
    }

    while(t--){
        cin >> a >> b;
        int rpta = (sum[b] - sum[a-1]);
        if (rpta < 0)rpta+=mod;
        cout << rpta << endl;
    }

    return 0;
}
