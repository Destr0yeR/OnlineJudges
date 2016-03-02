#include<bits/stdc++.h>

#define MAX 1000005

using namespace std;

typedef long long ll;

int p[MAX];
ll R[MAX], L[MAX];

int main(){
	int n;
	ll a = 0LL, b = 0LL;
	
	string s;
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i)cin >> p[i];
	cin >> s;
	int sz = s.size();
	
	for(int i = 0 ; i < sz ; ++i){
		if(s[i] == 'A'){
			a += p[i];
			L[i] = p[i];
		}
		else{
			b += p[i];
			L[i] = -p[i];
		}
		if(i){
			L[i] += L[i-1];
		}
	}
	
	for(int i = sz - 1 ; i >= 0 ; --i){
		if(s[i] == 'A'){
			R[i] = p[i];
		}
		else{
			R[i] = -p[i];
		}
		
		if(i != sz-1){
			R[i] += R[i+1];
		}
	}
	
	ll tmp = 0;
	
	for(int i = 0 ; i < sz ; ++i){
		tmp = max(tmp, max(L[i], R[i]));
	}
	
	cout << b + tmp << endl;

	return 0;
}
