#include<bits/stdc++.h>

using namespace std;

bitset<11> da;
bitset<11> db;

vector<int> getDivisors(int n){
	vector<int> aux;
	aux.push_back(1);
	if(n == 1)return aux;
	
	int sq = sqrt(n);
	
	for(int i =  2 ; i <= sq ; ++i){
		if(n%i == 0){
			aux.push_back(i);
			if(i*i != n)aux.push_back(n/i);
		}
	} 
	
	aux.push_back(n);
	
	return aux;
}

bool check(int a, int b){
	da.reset();
	db.reset();
	
	int r;
	
	while(a > 0){
		r = a%10;
		da[r] = 1;
		a/=10;
	}
	
	while(b > 0){
		r = b%10;
		db[r] = 1;
		b/=10;
	}
	
	for(int i = 0 ; i < 10 ; ++i)if(da[i] == 1 && db[i] == 1)return true;
	
	return false;
}

int main(){
	int n, cont = 0, sz;
	
	cin >> n;
	
	vector<int> d = getDivisors(n);
	
	sz = d.size();
	
	for(int i = 0 ; i < sz ; ++i){
		if(check(n, d[i]))cont++;
	}
	
	cout << cont << "\n";
	
	return 0;
}
