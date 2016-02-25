#include<bits/stdc++.h>

using namespace std;

int main(){
	
	string s;
	int f = 0, v = 0, sz;
	
	cin >> s;
	
	sz = s.size();
	
	for(int i = 0 ; i < sz ; ++i){
		if(s[i] == '4')f++;
		else if(s[i] == '7')v++;
	}
	
	if(!f && !v)cout << "-1";
	else if(f >= v)cout << "4";
	else cout << "7";
	
	cout << "\n";
	
	return 0;
}
