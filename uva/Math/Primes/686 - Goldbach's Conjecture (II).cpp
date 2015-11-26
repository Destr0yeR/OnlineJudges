#include<bits/stdc++.h>

#define MAX 1000001

using namespace std;

bitset<MAX> b;
vector<int> p;

void sieve(){
	b.set();
	
	int sq = sqrt(MAX);
	
	for(int j=2;j*2<MAX;j++){
		b[2*j] = 0;
	}
	
	for(int i = 3 ; i < sq ; i+=2){
		if(b[i]){
			for(int j=i;j*i<MAX;j++){
				b[i*j] = 0;
			}
		}
	}
	p.push_back(2);
	for(int i = 3 ; i < MAX ; i+=2){
		if(b[i]){
			p.push_back(i);
		}
	}
	
}

int main(){
	sieve();
	int n, sz = p.size(), cont;
	
	while(scanf("%d", &n) == 1){
		if(n == 0)break;
		cont = 0;
		for(int i = 0 ; i < sz ; ++i){
			if(2*p[i] > n)break;
			if(b[n-p[i]] == 1)cont++;
		}
		printf("%d\n", cont);
	}
	
	return 0;
}
