#include<bits/stdc++.h>
#define MAX 11

using namespace std;

int p[MAX];
int r[MAX];
int c = 2 ;

int solve(int n){
	if(r[n] >= 0)return r[n];
	if(n == 0)return r[n] = 0;
	int q = -1;
	
	for(int i = 1 ; i < n ; ++i){
		q = max(q, p[i] + solve(n-i) - c);
	}
	q = max(q, p[n] + solve(0));
	return r[n] = q;
}

int main(){
	int n;
	memset(p, -1, sizeof(p));
	memset(r, -1, sizeof(r));
	p[0] = 0;
	p[1] = 1;
	p[2] = 5;
	p[3] = 8;
	p[4] = 9;
	p[5] = 10;
	p[6] = 17;
	while(cin >> n){
		cout << solve(n) << endl;
	}
}
