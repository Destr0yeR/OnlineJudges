#include<bits/stdc++.h>

using namespace std;

int main(){
	
	string a;
	string b;
	
	int cf = 0, cs = 0, sz;
	
	cin >> a;
	cin >> b;
	
	sz = a.size();
	
	for(int i = 0 ; i < sz ; ++i){
		if(a[i] != b[i]){
			if(a[i] == '4')cf++;
			else cs++;
		}
	}
	
	cout << max(cs, cf) << endl;
	

	return 0;
}
