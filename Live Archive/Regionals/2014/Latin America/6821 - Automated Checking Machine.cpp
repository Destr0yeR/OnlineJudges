#include <bits/stdc++.h>

using namespace std;

int x[5], aux;

int main(){
	bool compatible;
	while(cin >> x[0]){
		compatible = true;
		for(int i = 1 ; i < 5 ; ++i)cin >> x[i];
		for(int i = 0 ; i < 5 ; ++i){
			cin >> aux;
			if(aux == x[i]){
				compatible = false;
			}
		}
		
		if(compatible)cout << "Y";
		else cout << "N";
		cout << endl;
	}

	return 0;
}
