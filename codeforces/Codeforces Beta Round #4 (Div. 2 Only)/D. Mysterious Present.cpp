#include<bits/stdc++.h>
#define MAX 5001

using namespace std;

struct par{
	int w, h, i;
	par(int _w, int _h, int _i){
		w = _w;
		h = _h;
		i = _i;
	}
};

bool cmp(par a, par b){
	if(a.h == b.h)return a.w > b.w;
	return a.h < b.h;
}

vector<par> p;

vector<int> LIS(vector<par> X){
	int n = X.size(), L, M[n+1], P[n];
	
	int lo, hi, mi;
	
	L = 0;
	M[0] = 0;
	
	for(int i = 0, j ; i < n ; ++i){
		lo = 0; hi = L;
		
		while(lo != hi){
			mi = (lo+hi+1)>>1;
			if(X[M[mi]].w < X[i].w /*&& X[M[mi]].h != X[i].h*/) lo = mi;
			else hi = mi-1;
		}
		
		j = lo;
		
		P[i] = M[j];
		
		if(j == L || ((X[i].w < X[M[j+1]].w) /*&& (X[i].h != X[M[j+1]].h)*/)){
			M[j+1] = i;
			L = max(L, j+1);
		}
	}
	
	int a[L];
	
	for(int i = L-1 , j=M[L] ; i >=0 ; --i){
		a[i] = X[j].i;
		j = P[j];
	}
	
	return vector<int>(a, a+L);
}

int main(){
	
	int n, w, h, _w, _h, sz;
	
	cin >> n >> w >> h;
	
	for(int i = 1 ; i <= n ; ++i){
		cin >> _w >> _h;
		if(_w <= w || _h <= h)continue;
		p.push_back(par(_w,_h, i));
	}
	
	sort(p.begin(), p.end(), cmp);
	
	vector<int> ans = LIS(p);
	
	sz = ans.size();
	
	cout << sz << endl;
	if(sz){
		for(int i = 0 ; i < sz ; ++i){
			if(i)cout << " ";
			cout << ans[i];
		}
	}
	cout << endl;
	
	
	return 0;
}
