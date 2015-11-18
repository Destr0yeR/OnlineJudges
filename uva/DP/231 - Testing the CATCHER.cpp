#include<bits/stdc++.h>

using namespace std;

vector<int> LIS(vector<int> X){
	int n = X.size(), L, M[n+1], P[n];
	
	int lo, hi, mi;
	
	L = 0;
	M[0] = 0;
	
	for(int i = 0, j ; i < n ; ++i){
		lo = 0; hi = L;
		
		while(lo != hi){
			mi = (lo+hi+1)>>1;
			if(X[M[mi]] >= X[i]) lo = mi;
			else hi = mi-1;
		}
		
		j = lo;
		
		P[i] = M[j];
		
		if(j == L || X[i] >= X[M[j+1]]){
			M[j+1] = i;
			L = max(L, j+1);
		}
	}
	
	int a[L];
	
	for(int i = L-1 , j=M[L] ; i >=0 ; --i){
		a[i] = X[j];
		j = P[j];
	}
	
	return vector<int>(a, a+L);
}

int main(){
	vector<int> v;
	int tc = 1, a;
	
	while(cin >> a){
		if(a == -1)break;
		v.clear();
		v.push_back(a);
		while(cin >> a){
			if(a == -1)break;
			v.push_back(a);
		}
		v = LIS(v);
		if(tc>1)cout << endl;
		cout << "Test #" << tc++ << ":" << endl;
		cout << "  maximum possible interceptions: " << v.size() << endl;
	}
	
	return 0;
}
