#include<bits/stdc++.h>

#define mset(x,y) memset(x, y, sizeof(x))

using namespace std;

int main(){
	
	int na, nb, pa, pb, a, b, aux;
	
	cin >> na >> nb;
	
	cin >> pa >> pb;
	
	for(int i = 0 ; i < na ; ++i){
		cin >> aux;
		if(i == pa-1){
			a = aux;
		}
	}
	
	for(int i = 0 ; i < nb ; ++i){
		cin >> aux;
		if(i == nb-pb){
			b = aux;
		}
	}
	
	if(b > a)cout << "YES";
	else cout << "NO";
	cout <<endl;

	return 0;
}
