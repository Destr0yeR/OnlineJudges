#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

struct par {
	int i;
	int v;
	int c;
	
	par(){}
	par(int i, int v):i(i), v(v){}
};

bool cmp(par x, par y) {
	if(x.v == y.v) return x.i < y.i;
	return x.v < y.v;
}

bool cmp2(par x, par y) {
	return x.i < y.i;
}

int main() {
	int n, m;
	
	cin >> n >> m;
	vi a(n);
	vector<par> b(m);
	
	for(int i = 0 ; i < n ; ++i)cin >> a[i];
	for(int i = 0 ; i < m ; ++i){
		cin >> b[i].v;
		b[i].i = i;
		b[i].c = 0;
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), cmp);
	
	int i = 0, j = 0;
	
	while(i < n && j < m) {
		if(a[i] <= b[j].v){
			++i;
		}
		else {
			b[j].c = i;
			++j;
		}
	}
	
	while(j < m) {
		b[j].c = i;
		j++;
	}
	
	
	sort(b.begin(), b.end(), cmp2);
	
	for(int i = 0 ; i < m ; ++i){
		if(i)cout << " ";
		cout << b[i].c;
	}
	
	puts("");
	
	return 0;
}
