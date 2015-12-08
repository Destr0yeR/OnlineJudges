#include<bits/stdc++.h>

#define MAX 3001

using namespace std;

bitset<MAX> b;

vector<int> p;

void sieve(){
	
	int sq = sqrt(MAX);
	b.set();
	b[0] = b[1] = 1;
	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	
	for(int i = 3 ; i <= sq ; i+=2){
		if(b[i] == 1)for(int j = i ; i*j < MAX ; i+=2)b[i*j] = 0;
	}
	
	p.push_back(2);
	for(int i = 3 ; i < MAX ; i+=2)if(b[i] == 1)p.push_back(i);
}

bool almost(int x){
	int sz = p.size(), cont = 0;
	
	for(int i = 0 ; i < sz ; ++i){
		if(x % p[i] == 0){
			cont++;
			while(x%p[i] == 0)x/=p[i];
		}
	}
	return cont == 2;
}

int main(){
	sieve();
	
	int n, cont = 0;
	
	cin >> n;
	
	for(int i = 1 ; i <= n ; ++i)if(almost(i))cont++;
	
	cout << cont << endl;
	
	return 0;
}
