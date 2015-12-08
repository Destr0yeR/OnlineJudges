#include<bits/stdc++.h>

#define MAX 100005

using namespace std;

int a[MAX];

vector<int> getDivisors(int n){
	vector<int> aux;
	aux.push_back(1);
	if(n == 1)return aux;
	
	int sq = sqrt(n);
	
	for(int i =  2 ; i <= sq ; ++i){
		if(n%i == 0){
			aux.push_back(i);
			if(i*i != n)aux.push_back(n/i);
		}
	} 
	
	aux.push_back(n);
	
	return aux;
}
int main(){
	
	int n;
	
	cin >> n;
	
	for(int i = 1 ; i <= n ; ++i)cin >> a[i];
	
	vector<int> d = getDivisors(n);
	int sz = d.size();
	bool posible;
	
	sort(d.begin(), d.end());
	
	for(int i = 0 ; i < sz && d[i]*3 <= n ; ++i){
		for(int j = 0 ; j < d[i] ; ++j){
			posible = true;
			for(int k = 1 + j ; k <= n ; k+=d[i]){
				if(a[k] == 0){
					posible = false;
					break;
				}
			}
			if(posible)break;
		}
		if(posible)break;
	}
	
	if(posible)cout << "YES\n";
	else cout << "NO\n";
	
	return 0;
}
