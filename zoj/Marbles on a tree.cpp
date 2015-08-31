#include <bits/stdc++.h>
#define MAX 10001

using namespace std;

vector<int> mat[MAX];
int c[MAX];
int n, v, d, total, aux, q;
int u[MAX];

int dfs(int x){
	u[x] = 1;
	
	int sobra = c[x] - 1;
	int sz = mat[x].size();
	for(int i =  0 ; i < sz ; ++i){
		if(u[mat[x][i]] == 0){
			aux = dfs(mat[x][i]);
			sobra += aux;
			total += abs(aux);
		}
	}
	return sobra;
}

int main(){
	
	while(cin >> n){
		if(n == 0)break;
		memset(c, 0, sizeof(c));
		memset(u, 0, sizeof(u));
		for(int i = 0 ; i <= n ; ++i)mat[i].clear();
		for(int j =  0 ; j < n ; ++j){
			cin >> v;
			cin >> q;
			cin >> d;
			c[v] = q;
			for(int i = 0 ; i < d ; ++i){
				cin >> aux;
				mat[v].push_back(aux);
				mat[aux].push_back(v);
			}
		}
		total = 0;
		dfs(1);
		cout << total << endl;
	}
	
	return 0;
}
