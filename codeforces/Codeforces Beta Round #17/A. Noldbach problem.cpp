#include<bits/stdc++.h>

#define MAX 1001

using namespace std;

bitset<MAX> b;
vector<int> p;


void sieve(){
	int sq = sqrt(MAX);
	b.set();
	b[0] = b[1] = 0;
	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	
	for(int i = 3 ; i <= sq ; i+=2)if(b[i] == 1)for(int j = i ; j*i < MAX ; j+=2)b[i*j] = 0;
	
	p.push_back(2);
	
	for(int i = 3 ; i < MAX ; i+=2)if(b[i] == 1)p.push_back(i);
}

bool is(int n){
	n--;
	int sz = p.size() - 1;
	
	for(int i = 0 ; i < sz ; ++i){
		if(p[i] + p[i+1] == n)return true;
	}
	
	return false;
}

int main(){
	sieve();
	
	int n, k, cont = 0, sz = p.size();
	
	cin >> n >> k;
	
	for(int i = 0 ; i < sz ; ++i){
		if(p[i] > n)break;
		if(is(p[i]))cont++;
		if(cont == k)break;
	}
	
	if(cont == k)cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}
