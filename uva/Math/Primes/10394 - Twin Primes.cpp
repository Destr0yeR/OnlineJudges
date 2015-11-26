#include<bits/stdc++.h>

#define MAX 20000001

using namespace std;

bitset<MAX> b;
vector<int> p;
vector<int> ans;

void sieve(){
	b.set();
	
	int sq = sqrt(MAX);
	
	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	
	for(int i = 3 ; i <= sq ; i+=2){
		if(b[i] == 1){
			for(int j = i ; j*i < MAX ; j+=2){
				b[i * j] = 0;
			}
		}
	}
	
	p.push_back(2);
	for(int i = 3 ; i < MAX ; i+=2){
		if(b[i] == 1)p.push_back(i);
	}
}

void solve(){
	int sz = p.size() - 1;
	ans.push_back(0);
	for(int i = 0 ; i < sz  ; ++i){
		if(p[i+1] - p[i] == 2)ans.push_back(p[i]);
	}
}

int main(){
	sieve();
	solve();
	
	int n, aux;
	
	while(scanf("%d", &n) == 1){
		aux = ans[n];
		printf("(%d, %d)\n", aux, aux + 2);
	}

	
	return 0;
}
