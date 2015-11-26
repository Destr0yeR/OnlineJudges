#include<bits/stdc++.h>

#define MAX 100000001

using namespace std;

bitset<MAX> b;
vector<int> p;

void sieve(){
	b.set();
	b[0] = b[1] = 0;
	int sq = sqrt(MAX);
	
	for(int i = 4 ; i < MAX ; i+=2){
		b[i] = 0;
	}
	
	for(int i = 3 ; i <= sq ; i+=2){
		if(b[i] == 1){
			for(int j = i ; i*j < MAX ; j+=2){
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
	
	int n, a;
	bool found;
	
	while(scanf("%d", &n) == 1){
		found = false;
		int i = int(upper_bound(p.begin(), p.end(), n/2) - p.begin());
		
		
		if(n > 4){
			if(n%2 == 1){
				if(b[n-2] == 1){
					a = 2;
					found = true;
				}
			}
			else{
				for( ; i >= 0 ; --i){
					if(p[i]*2 == n)continue;
					if(b[n-p[i]] == 1){
						a = min(p[i], n-p[i]);
						found = true;
						break;
					}
				}
			}
		}
		if(!found){
			printf("%d is not the sum of two primes!\n", n);
		}
		else{
			printf("%d is the sum of %d and %d.\n", n, a, n-a);
		}
	}
	
	return 0;
}
