#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int T, n, x, y, aux;
	
	cin >> T;
	bool e, h;
	
	while(T--){
		cin >> n >> x >> y;
		
		e = false;
		h = false;
		
		for(int i = 1 ; i <= n ; ++i){
			cin >> aux;
			if(i == 1 && aux == x)e = true;
			if(i == n && aux == y)h = true;
		}
		
		if(e && h)cout << "BOTH";
		else if(e)cout << "EASY";
		else if(h)cout << "HARD";
		else cout << "OKAY";
		
		cout << '\n';
	}
	
	return 0;
}
