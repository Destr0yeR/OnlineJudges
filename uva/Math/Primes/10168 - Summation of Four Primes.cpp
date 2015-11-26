#include<bits/stdc++.h>

#define MAX 10000001

using namespace std;

bitset<MAX> b;
vector<int> p;

void sieve(){
	b.set();
	
	int sq = sqrt(MAX);
	
	b[0] = b[1] = 0;
	
	for(int j=4;j<MAX;j+=2){
		b[j] = 0;
	}
	
	for(int i = 3 ; i <= sq ; i+=2){
		if(b[i]){
			for(int j=i;j*i<MAX;j+=2){
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
	int n, sz = p.size(), a, c;
	bool found;
	
	while(scanf("%d", &n) == 1){
		found = false;
		if(n >= 8){
			if(n%2 == 0){
				a = 2;
				n-= 4;
			}
			else{
				a = 3;
				n-= 5;
			}
			for(int i = 0 ; i < sz ; ++i){
				if(2*p[i] > n)break;
				if(b[n-p[i]] == 1){
					c = p[i];
					found = true;
					break;
				}
			}
		}
		
		if(found){
			printf("%d %d %d %d\n", 2, a, c, n-c);
		}
		else{
			printf("Impossible.\n");
		}
	}
	
	return 0;
}
