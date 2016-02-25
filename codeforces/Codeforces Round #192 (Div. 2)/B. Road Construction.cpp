#include<bits/stdc++.h>
#define MAX 1001

using namespace std;

struct par{
	int i, v;
};

bool cmp(par x, par y){
	return x.v < y.v;
}

int main(){
	int n, m, x, y;
	par a[MAX];
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; ++i){
		a[i].i = i;
		a[i].v = n-1;
	}
	
	for(int i = 0 ; i < m ; ++i){
		cin >> x >> y;
		a[x].v--;
		a[y].v--;
	}
	
	sort(a, a + n + 1, cmp);
	
	x = a[n].i;
	
	cout << n-1 << endl;
	for(int i = 1 ; i <= n ; ++i){
		if(x == i)continue;
		cout << x << " " << i << endl;
	}
	
	return 0;
}
