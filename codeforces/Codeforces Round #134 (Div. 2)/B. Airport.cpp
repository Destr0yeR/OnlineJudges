#include<bits/stdc++.h>

#define MAX 1002

using namespace std;

int a[MAX];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	
	int n, m;
	
	cin >> n >> m;
	
	for(int i = 0 ; i < m ; ++i)cin >> a[i];
	
	sort(a, a+m);
	
	int maxi = 0, mini = 0, aux = n, tmp;
	
	for(int i = 0 ; i < m && n ; ++i){
		if(a[i] > n){
			tmp = a[i] - n;
			mini += (a[i]*(a[i]+1))/2 - (tmp*(tmp+1))/2;
			n = 0;
		}
		else{
			mini += (a[i]*(a[i]+1))/2;
			n -= a[i];
		}
	}
	
	n = aux;
	
	sort(a, a+m, cmp);
	a[m] = 0;
	
	while(n){
		
		maxi += a[0];
		a[0]--;
		sort(a, a+m, cmp);
		n--;
	}
	
	cout << maxi << " " << mini << endl;
	
	return 0;
}
