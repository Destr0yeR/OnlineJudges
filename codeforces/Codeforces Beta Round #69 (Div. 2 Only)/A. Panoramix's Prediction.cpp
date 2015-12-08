#include<bits/stdc++.h>

#define MAX 100

using namespace std;

bitset<MAX> b;
vector<int> p;

void sieve(){
	int sq = sqrt(MAX);
	
	b.set();
	
	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	
	for(int i = 3 ; i <= sq ; i+=2)if(b[i] == 1)for(int j = i ; i*j < MAX ; j+=2)b[i*j] = 0;
	
	p.push_back(2);
	for(int i = 3 ; i < MAX ; i+=2)if(b[i] == 1)p.push_back(i);
}

int main(){
	sieve();
	int n, m, sz = p.size(), i;
	cin >> n >> m;
	
	for(i = 0 ; i < sz ; ++i){
		if(p[i] == n)break;
	}
	
	if(p[i+1] == m)cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}
