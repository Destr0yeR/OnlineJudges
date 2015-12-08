#include<bits/stdc++.h>

using namespace std;

int main(){
	int aux, mini = 1001, a, b;
	
	for(int i = 0 ; i < 4 ; ++i){
		cin >> aux;
		mini = min(mini, aux);
	}
	
	cin >> a >> b;
	
	if(b < mini){
		cout << b - a + 1<< endl;
	}
	else if( a <= mini){
		cout << mini - a << endl;
	}
	else cout << "0\n";

	return 0;
}
