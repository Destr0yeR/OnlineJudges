#include<bits/stdc++.h>

#define MAX 1000001

using namespace std;

bitset<MAX> b;
vector<int> p;

void sieve(){
	b.set();
	
	int sq = sqrt(MAX);
	
	for(int j=2;j<MAX;j+=2){
		b[j] = 0;
	}
	
	for(int i = 3 ; i <= sq ; i+=2){
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
	
	int T, a, b, last, sz = p.size(), max, ans, prim;
	bool single;
	
	scanf("%d", &T);
	
	while(T--){
		scanf("%d %d", &a, &b);
		map<int, int> m;
		
		last = -1;
		prim = 0;
		for(int i = 0 ; i < sz ; ++i){
			if(b < p[i])break;
			if(a <= p[i]){
				if(last != -1){
					m[p[i] - last]++;
				}
				last = p[i];
				prim++;
			}
		}
		
		max = -1;
		ans = -1;
		single = true;
		map<int,int>::iterator it;
		
		for(it = m.begin() ; it != m.end() ; ++it){
			if(it->second == max){
				single = false;
			}
			else if(it->second > max){
				max = it->second;
				ans = it->first;
				single = true;
			}
		}
		
		if(single && prim >= 2)printf("The jumping champion is %d\n", ans);
		else printf("No jumping champion\n");
	}
	
	return 0;
}
