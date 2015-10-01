#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve(ll n){
	if(n==0)return 0;
	ll q = n/10;
	
	return q*(45) + 10*solve(q);
}

ll tri(ll x){return (x*(x+1))>>1;}

ll rest(ll n){
	if(n == 0)return 0;
	ll p = 1;
	ll aux = n, sum = 0, r, ante = 0;
	
	while(aux>0){
		r = aux%10;
		if(r)sum+=p*tri(r-1);
		sum+=r*(ante+1);
		ante += r*p;
		p*=10;
		aux/=10;
	}
	
	return sum;
}

int main(){
	ll n, m;
	
	while(cin >> m >> n){
		if(n == 0 && m == 0)break;
		cout << (solve(n) + rest(n)) - (solve(m-1) + rest(m-1)) << endl;
	}
	
	return 0;
}
