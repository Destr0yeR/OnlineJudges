#include<bits/stdc++.h>

#define MAX 1001

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
	for(int i = 1 ; i < MAX ; ++i){
		if(b[i]){
			p.push_back(i);
			cont++;
		}
		c[i] = cont;
	}
	
}

int main(){
	
	sieve();
	int n, k;
	
	while(scanf("%d %d", &n, &k) == 2){
		
		int from, to;
		
		
		if(c[n] % 2 == 0){
			from = c[n]/2 - k + 1;
			to = c[n]/2 + k;
		}
		else {
			from = (c[n]+1)/2 - k + 1;
			to = (c[n]+1)/2 + k - 1;
		}
		
		if(from < 1)from = 1;
		if(to > c[n])to = c[n];
		
		from --;
		
		printf("%d %d:", n, k);
		
		for(int i = from ; i < to ; ++i)printf(" %d", p[i]);
		
		printf("\n\n");
	}
	
	return 0;
}
