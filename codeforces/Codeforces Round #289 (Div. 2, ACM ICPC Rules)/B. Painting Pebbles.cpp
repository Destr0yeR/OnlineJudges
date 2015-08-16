#include<bits/stdc++.h>

using namespace std;
int n, k;

int a[101];

int main(){
	
	cin >> n >> k;
	
	int mini = 101, maxi = 0;
	
	for(int i = 0 ; i < n ; ++i){
		cin>>a[i];
		maxi = max(a[i], maxi);
		mini = min(a[i], mini);
	}
	
	int cont;
	if(k < maxi-mini){
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		for(int i = 0 ; i < n ; ++i){
			cont = 1;
			for(int j = 0 ; j < a[i] ; ++j){
				if(j)cout << " ";
				if(j < mini)cout << cont;
				else cout << cont++;
			}
			cout << endl;
		}
	}
	
	
	return 0;
}
