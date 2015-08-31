#include<bits/stdc++.h>

using namespace std;

struct par{
	int val;
	int ind;
};

par a[50001];
int b[50001];
int u[50001];

bool cmp(par a, par c){
	if(a.val == c.val)return b[a.ind] < b[c.ind];
	return a.val < c.val;
}

int main(){
	int n;
	
	cin >> n;
	memset(u, 0, sizeof(0));
	
	for(int i = 0 ; i < n ; ++i)
	{
		cin >> a[i].val >> b[i];
		a[i].ind = i;
	}
	
	sort(a, a+n, cmp);
	
	int maxi = 0;
	
	for(int i = 0; i < n ; ++i){
		if(maxi <= b[a[i].ind]){
			maxi = b[a[i].ind];
		}
		else{
			maxi = a[i].val;
		}
	}
	
	cout << maxi << endl;
	
	return 0;
}
