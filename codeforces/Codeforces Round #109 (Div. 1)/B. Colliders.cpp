#include<bits/stdc++.h>

#define MAX 100005

using namespace std;

vector<int> d[MAX], acu[MAX];
bitset<MAX> b;
int cont[MAX];

vector<int> getDivisors(int n){
	vector<int> aux;
	vector<int> aux2;
	aux.push_back(1);
	if(n == 1)return aux;
	
	int sq = sqrt(n);
	
	for(int i =  2 ; i <= sq ; ++i){
		if(n%i == 0){
			aux.push_back(i);
			if(i*i != n)aux2.push_back(n/i);
		}
	}
	int sz = aux2.size();
	
	for(int i = 0 ; i < sz ; ++i)aux.push_back(aux2[i]);
	
	aux.push_back(n);
	
	return aux;
}

void generateDivisors(int n){
	
	for(int i = 1 ; i <= n ; ++i){
		d[i] = getDivisors(i);
	}
}

void off(int n){
	b[n] = 0;
	int sz = d[n].size();
	for(int i = 1 ; i < sz ; ++i)cont[d[n][i]]--;
}

int check(int n){
	int sz = d[n].size(), sz2, tmp;
	for(int i = 1 ; i < sz ; ++i){
		if(cont[d[n][i]] > 0){
			sz2 = acu[d[n][i]].size();
			for(int j = sz2-1 ; j >= 0 ; --j){
				tmp = acu[d[n][i]][j];
				if(b[tmp] == 1)return tmp;
				acu[d[n][i]].pop_back();
			}
		}
	}
	
	return -1;
}

void on(int n){
	b[n] = 1;
	int sz = d[n].size();
	for(int i = 1 ; i < sz ; ++i){
		cont[d[n][i]]++;
		acu[d[n][i]].push_back(n);
	}
}

int main(){
	int n, m, a, ans;
	char c;
	cin >> n >> m;
	
	memset(cont, 0, sizeof(cont));
	generateDivisors(n);
	
	for(int i = 0 ; i < m ; ++i){
		cin >> c >> a;
		if(c == '-'){
			if(b[a] == 0) cout << "Already off\n";
			else{
				off(a);
				cout << "Success\n";
			}
		}
		else{
			if(b[a] == 1) cout << "Already on\n";
			else{
				ans = check(a);
				if(ans == -1){
					on(a);
					cout << "Success\n";
				}
				else cout << "Conflict with " << ans << "\n";
			}
		}
	}
	
	return 0;
}
