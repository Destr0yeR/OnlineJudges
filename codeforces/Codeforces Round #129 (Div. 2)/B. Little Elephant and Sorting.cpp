#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	
	long long last = 0, acu = 0, aux;
	cin >> n;
	for(int i = 0 ; i < n ; ++i){
		cin >> aux;
		if(aux < last){
			acu += last-aux;
		}
		last = aux;
	}
	
	cout << acu << '\n';
	
	return 0;
}
