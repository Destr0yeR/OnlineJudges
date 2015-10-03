#include<bits/stdc++.h>
#define MAX 200005
using namespace std;

typedef long long ll;

ll x[MAX], a[MAX];

struct par{
	ll i, v;
	par(){}
	par(ll _i, ll _v){i=_i;v=_v;}
};

bool cmp(par a, par b){
	if(a.v == b.v)return a.i < b.i;
	return a.v > b.v;
}

par p[MAX], l[MAX], r[MAX];
int main(){
	int n, k, of;
	
	cin >> n >> k;
	
	for(int i = 1 ; i <= n ; ++i)cin >> x[i];
	
	a[0] = 0;
	
	for(int i = 1 ; i <= n ; ++i)a[i]=a[i-1]+x[i];
	of = n-k+1;
	for(int i = 1 ; i <= of ; ++i){
		p[i] = par(i, a[i+k-1]-a[i-1]);
	}
	
	l[0].v = r[of+1].v = 0;
	for(int i = 1 ; i <= of ; ++i){
		if(p[i].v > l[i-1].v){
			l[i] = p[i];
		}
		else l[i] = l[i-1];
	}
	
	for(int i = of ; i >= 1 ; --i){
		if(p[i].v >= r[i+1].v){
			r[i] = p[i];
		}
		else r[i] = r[i+1];
	}
	
	/*for(int i = 1 ; i <= of ; ++i){
		cout << i << " " << l[i].i << " " << l[i].v << " " << r[i].i << " " << r[i].v << endl;
	}*/
	
	par a, b;
	a.v = 0;
	b.v = 0;
	of = n-2*k+1;
	
	for(int i = 1 ; i <= of ; ++i){
		if((a.v + b.v)< l[i].v + r[i+k].v){
			a = l[i];
			b = r[i+k];
		}
	}
	
	
	cout << a.i << " " << b.i << endl;
	
	return 0;
}
