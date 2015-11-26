#include<bits/stdc++.h>

#define MAX 100001

using namespace std;

bitset<MAX> b;
vector<int> p;

void sieve(){
	b.set();
	
	int sq = sqrt(MAX);
	
	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	
	for(int i = 3 ; i < sq ; i+=2){
		if(b[i] == 1){
			for(int j = i ; j*i < MAX ; ++j){
				b[j*i] = 0;
			}
		}
	}
	p.push_back(2);
	for(int i = 3 ; i < MAX ; i+=2){
		if(b[i] == 1)p.push_back(i);
	}
	
}

int main(){
	sieve();
	
	int T, n, sz = p.size(), maxi, aux, a, diff;
	
	scanf("%d", &T);
	
	while(T--){
		cin >> n;
		maxi = 0;
		for(int i = 0 ; i < sz ; ++i){
			if(p[i] > n)break;
			aux = n/p[i];
			diff = n - aux*p[i];
			
			if(diff > maxi){
				a = p[i];
				maxi = diff;
			}
		}
		
		printf("%d\n", a);
	}
	
	return 0;
}
