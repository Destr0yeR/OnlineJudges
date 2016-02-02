#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[19][181][2];

ll cnt(ll dig, ll sum, bool lst, vector<int> n){
    if(sum < 0)return 0;
    if(dig == n.size()){
        if(sum == 0)return 1;
        else return 0;
    }
    if(dp[dig][sum][lst] != -1)return dp[dig][sum][lst];

    ll ans = 0;

    int k = 9;

    if(!lst)k = n[dig];

    for(int i = 0 ; i <= k ; ++i){
        bool tlst;

        if(lst)tlst = true;
        else{
            tlst = (i < n[dig]);
        }

        ans += cnt(dig+1, sum-i, tlst, n);
    }

    return dp[dig][sum][lst] = ans;
}

ll solve(ll x, ll sum){
    vector<int> n;

    while(x > 0){
        n.push_back(x%10);
        x /= 10;
    }

    reverse(n.begin(), n.end());
    memset(dp, -1, sizeof(dp));

    return cnt(0, sum, false, n);
}

int main(){
    int T;

    ll ans, tmp;
    cin >> T;

    for(int tc = 1 ; tc <= T ; ++tc){
        ll a, b, x, max;
        cin >> a >> b >> x;

        ans = 0;

        max = b-a+1;

        for(ll sum = 1 ; sum <= x ; ++sum){
            if(ans >= max)break;

            tmp = solve(b, sum);

            if(a > 1)tmp -= solve(a-1, sum);

            tmp = min(x/sum, tmp);

            ans += tmp;
            x -= tmp*sum;
        }

        cout << ans << endl;
    }

    return 0;
}
