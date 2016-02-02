#include<bits/stdc++.h>

#define offset 100
#define MAX 201

using namespace std;

bitset<MAX> b;

typedef long long ll;

int memo[19][301];
ll dp[19][301];

void sieve(){
    b.set();

    b[0] = b[1] = 0;

    for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;

    int sq = sqrt(MAX);

    for(int i = 3 ; i <= sq ; i+=2)if(b[i])for(int j = i ; j*i < MAX ; j+=2)b[i*j] = 0;
}

ll F(int dig, int sum){
    if(dig == 0){
        if(sum > 0)return b[sum];
        else return 0;
    }

    if(memo[dig][sum + offset])return dp[dig][sum + offset];

    memo[dig][sum + offset] = 1;

    ll ans = 0LL;

    for(int i = 0 ; i < 10 ; ++i){
        if(dig % 2 == 0)ans += F(dig - 1, sum + i);
        else ans += F(dig - 1, sum - i);
    }

    return dp[dig][sum + offset] = ans;
}

ll solve(ll x){
    ll ans = 0LL, sum = 0LL;

    char cad[20];

    sprintf(cad, "%lld", x);

    int len = strlen(cad);
    int j = len;

    for(int i = 0 ; i < len ; ++i){
        j--;

        int d = cad[i] - '0';

        for(int k = 0 ; k < d ; ++k){
            if((j+1) % 2 == 0)ans += F(j, sum + k);
            else ans += F(j, sum - k);
        }

        if((j+1) % 2 == 0)sum += d;
        else sum -= d;
    }

    return ans;
}

int main(){
    sieve();

    int T;

    scanf("%d", &T);

    ll a, b;

    for(int tc = 1 ; tc <= T ; ++tc){
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", solve(b+1) - solve(a));
    }

    return 0;
}
