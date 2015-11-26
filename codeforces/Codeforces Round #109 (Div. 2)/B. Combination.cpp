#include<bits/stdc++.h>

#define MAX 1001

using namespace std;

struct par{
	int p, c;
};

par a[MAX];

bool cmp(par x, par y){
	if(x.c == y.c){
		return x.p > y.p;
	}
	return x.c > y.c;
}

int main(){
	
	int n, tot = 0, rem = 1;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i].p >> a[i].c;
	}
	
	sort(a, a+n, cmp);
	
	for(int i = 0 ; i < n && rem; ++i){
		tot += a[i].p;
		rem += a[i].c;
		
		rem--;
	}
	
	cout << tot << endl;
	
	return 0;
}
