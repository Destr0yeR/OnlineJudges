#include<bits/stdc++.h>

#define MAX 1000005

using namespace std;

bitset<MAX> b;
vector<int> p;

void sieve(){
	b.set();
	
	int sq = sqrt(MAX);
	
	for(int i = 4 ; i < MAX ; i+=2){
		b[i] = 0;
	}
	
	for(int i = 3 ; i < sq ; i+=2){
		if(b[i] == 1){
			for(int j = i ; i*j < MAX ; ++j){
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
	
	int n, sz = p.size(), a;
	bool found;
	
	while(scanf("%d", &n) == 1){
		if(n == 0)break;
		found = false;
		for(int i = 0 ; i < sz ; ++i){
			if(p[i]*2 > n)break;
			if(b[n-p[i]] == 1){
				a = p[i];
				found = true;
				break;
			}
		}
		printf("%d:\n", n); 
		if(found){
			printf("%d+%d\n",a, n-a);
		}
		else{
			printf("NO WAY!\n");
		}
	}
	
	return 0;
}
