#include <bits/stdc++.h>
#define MAX 10000007
using namespace std;
typedef long long ll;

bitset<MAX + 1> bs;
vector<ll> primes;
map<ll, int> primes2;

int cont = 0;

void segmented_sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i = 2; i <= MAX; ++i){
		if(bs[i]){
			primes.push_back(i);
			primes2[i] = ++cont;
			for(ll j = i*i; j <= MAX; j+=i){
				bs[j] = 0;
			}
		}
	}
}

bool isPrime(ll num){
	if(primes2[num])return true;
	
	if(num <= MAX) return bs[num];
	if(!(num&1)) return false;
	
	ll i = 0, p = primes[i];
	
	while((p*p <= num) && i <= MAX){
		if(num % p == 0) return false;
		p = primes[++i];
	}
	primes2[num] = ++cont;
	return true;
}


int main(){
	segmented_sieve();
	
	ll a, b, k, ans;
	
	cin >> a >> b >> k;
	
	
	
	cout << ans << endl;
	
	return 0;
}
