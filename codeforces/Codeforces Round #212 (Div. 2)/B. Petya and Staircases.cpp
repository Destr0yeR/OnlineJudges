#include<bits/stdc++.h>

using namespace std;

int s[3001];

int main(){
	
	int n, m;
	
	cin >> n >> m;
	
	for(int i = 0 ; i < m ; ++i)cin >> s[i];
	
	sort(s, s+m);
	bool posible = true;
	for(int i = 0 ; i < m-2 ; ++i){
		if(s[i] == s[i+1]-1 && s[i] == s[i+2]-2){
			posible = false;
			break;
		}
	}
	
	if(s[0] == 1) posible = false;
	if(s[m-1] == n) posible = false;
	
	if(posible) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}
