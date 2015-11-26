#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n, t, c, acu = 0, tot = 0, aux;
	cin >> n >> t >> c;
	for(int i = 0 ; i < n; ++i){
		cin >> aux;
		if(aux > t){
			if(acu >= c){
				tot+=(acu-c+1);
			}
			acu = 0;
		}
		else acu++;
	}
	
	if(acu >= c){
		tot+=(acu-c+1);
	}
	cout << tot << endl;
	return 0;
}
