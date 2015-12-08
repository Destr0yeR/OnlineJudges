#include<bits/stdc++.h>

#define MAX (1LL<<16)

using namespace std;

typedef long long ll;

bitset<MAX> b;
vector<int> p;

void sieve(){
	int sq = sqrt(MAX);
	
	b[0] = b[1] = 0;
	
	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	
	for(int i = 3 ; i <= sq ; i+=2)if(b[i] == 1)for(int j = i ; i*j < MAX ; j+=2)b[i*j] = 0;
	
	p.push_back(2);
	for(int i = 3 ; i < MAX ; i+=2)if(b[i] == 1)p.push_back(i);
}

int main(){
	sieve();
	
	ll n, m;
	
	cin >> n >> m;
	
	
	
	return 0;
}
