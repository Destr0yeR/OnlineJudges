#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	
	cin >> n >> m;
	bool zero;
	
	if(n-1 > m || m > 2*(n+1)){
		cout << "-1" << endl;
	}
	else{
		if(m == n-1 || m == n){
			zero = true;
			for(int i = 0 ; i < m+n ; ++i){
				if(zero)cout << 0;
				else cout << 1;
				zero = !zero;
			}
			cout << endl;
		}
		else{
			zero = false;
			int cont;
			if(m == 2*(n+1)){
				cont = n+1;
			}
			else cont = m%(n+1);
			m -=cont;
			for(int i = 0 ; i < m+n ; ++i){
				if(zero)cout<<"0";
				else{
					cout<<"1";
					if(cont){
						cout<<"1";
						cont--;
					}
				}
				zero = !zero;
			}
		}
	}
	
	return 0;
}
