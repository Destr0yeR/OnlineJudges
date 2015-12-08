#include<bits/stdc++.h>

#define MAX 10000001
#define INF LLONG_MAX

typedef long long ll;

using namespace std;

bitset<MAX> b;

void sieve(){
	b.set();
	b[0] = b[1] = 0;
	
	int sq = sqrt(MAX);
	
	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	
	for(int i = 3 ; i <= sq ; i+=2)if(b[i] == 1)for(int j = i ; i*j < MAX ; j+=2)b[i*j] = 0;
}

bool isPrime(ll n){
	if(n == 1)return true;
	if(n == 2)return true;
	if(n%2 == 0)return false;
	int sq = sqrt(n);
	
	for(ll i = 3 ; i <= sq ; ++i)if(n%i == 0)return false;
	
	return true;
}

void solve(ll n){
	ll sq = sqrt(n), ans = INF, aux;
	
	bool posible = false;
	
	if(isPrime(n)){
		cout << "1\n0\n";
	}
	else{
		for(ll i = 2 ; i <= sq ; ++i){
			if(n%i == 0){
				if(b[i] == 0){
					posible = true;
					ans = min(ans, i);
				}
				else {
					aux = n/i;
					if(aux < MAX){
						if(b[n/i] == 0){
							posible = true;
							ans = min(ans, n/i);
						}
					}
					else if(!isPrime(aux)){
						posible = true;
						ans = min(ans, n/i);
					}
					
				}
			}
		}
		
		if(posible){
			cout << "1\n" << ans << "\n";
		}
		else cout << "2\n";
	}
}

int main(){
	sieve();
	ll n;
	
	cin >> n;
	
	solve(n);
	
	return 0;
}
