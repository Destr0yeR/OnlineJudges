#include<bits/stdc++.h>

#define MAX 1000001

using namespace std;

bitset<MAX> b;
vector<int> p;

int c[MAX];

void sieve(){
	b.set();
	
	int sq = sqrt(MAX);
	
	for(int j=2;j*2<MAX;j++){
		b[2*j] = 0;
	}
	
	for(int i = 3 ; i <= sq ; i+=2){
		if(b[i]){
			for(int j=i;j*i<MAX;j++){
				b[i*j] = 0;
			}
		}
	}
	int cont = 0;
	for(int i = 3 ; i < MAX ; ++i){
		if(b[i]){
			p.push_back(i);
			cont++;
		}
		c[i] = cont;
	}
	
}

int main(){
	
	sieve();
	int n, sz, a;
	
	while(scanf("%d", &n)){
		if(n == 0)break;
		sz = p.size();
		for(int i = 0 ; i < sz ; ++i){
			a = p[i];
			if(2*a > n)break;
			if(b[n-a] == 1)break;
		}
		
		
		if(2*a <= n)printf("%d = %d + %d\n", n, a, n-a);
		else printf("Goldbach's conjecture is wrong.\n");
	}
	
	return 0;
}
