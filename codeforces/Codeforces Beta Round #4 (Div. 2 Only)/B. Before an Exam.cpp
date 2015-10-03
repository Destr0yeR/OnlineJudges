#include<bits/stdc++.h>
#define MAX 31
using namespace std;

struct par{
	int l, r;
	
}in[MAX], acu[MAX];

int main(){
	int d, n, m;
	
	cin >> d >> n;
	
	for(int i = 0 ; i < d ; ++i)cin >> in[i].l >> in[i].r;
	acu[d-1] = in[d-1];
	for(int i = d-2 ; i >= 0 ; --i){
		acu[i].l = in[i].l + acu[i+1].l;
		acu[i].r = in[i].r + acu[i+1].r;
	}
	
	if(acu[0].l <= n && n <= acu[0].r){
		cout << "YES" << endl;
		for(int i = 0 ; i < d-1 ; ++i){
			m = n - acu[i+1].r;
			while(m < in[i].l)m++;
			cout << m << " ";
			n-=m;
		}
		cout << n << endl;
	}
	else cout << "NO" << endl;

	return 0;
}
