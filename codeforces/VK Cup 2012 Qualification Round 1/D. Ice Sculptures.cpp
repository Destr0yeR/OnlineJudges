#include<bits/stdc++.h>

#define MAX 20001
#define INF (1<<30)
using namespace std;

int a[MAX];

vector<int> d;

void getDivisors(int n){
	int sq = sqrt(n);
	int i;
	
	for( i = 1 ; i <= sq ; ++i){
		if(n%i == 0){
			d.push_back(i);
			if(i*i != n)d.push_back(n/i);
		}
	}
	
	sort(d.begin() , d.end());
}

int main(){
	
	int n;
	
	cin >> n;
	getDivisors(n);
	
	int sz = d.size(), maxi = -INF, tmp, aux;
	
	for(int i = 1 ; i <= n ; ++i)cin >> a[i];
	
	for(int i = 0 ; i < sz ; ++i){
		tmp = d[i];
		for(int k = 0 ; k < tmp && d[i]*3 <= n; ++k){
			aux = 0;
			for(int j = 1+k ; j <= n ; j+=tmp){
				aux += a[j];
			}
			maxi = max(aux, maxi);
		}
	}
	
	cout << maxi << endl;
	
	return 0;
}
