#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve(ll n, ll k) {
		int a[101];
		
		memset(a, 0, sizeof(a));
		
		int x = n % 100;
		int cnt = 0;
		
		while (a[x % 100] == 0) {
			a[x % 100] = cnt++;
			x = x + (x % 100);
		}
		
		int from = a[x % 100];
		int to = cnt - from;
		
		ll sum = x % 100;
		
		for (int j = 0; j < to; j++) {
			sum = sum + sum % 100;
		}
		
		sum -= (x % 100);

		for (int j = 0; k > 0 && j < from; j++) {
			n = n + n % 100;
			k--;
		}

		n += ((long) sum * (k / to));
		k %= to;
		
		for (int j = 0; j < k; j++) {
			n = n + n % 100;
		}

		return n;
	}

int main(){
	int T;
	ll n, k;
	cin >> T;
	
	while(T--){
		cin >> n >> k;
		
		cout << solve(n, k) << endl;
	}
	
	return 0;
}
