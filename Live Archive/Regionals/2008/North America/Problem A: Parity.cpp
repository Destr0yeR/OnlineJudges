#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	int cont, sz;
	
	while(cin >> s){
		sz = s.size();
		if(sz == 1 && s[0] == '#')break;
		bool par = true;
		if(s[sz - 1] == 'o')par = false;
		cont = 0;
		for(int i = 0 ; i < sz ; ++i){
			if(s[i] == '1')cont++;
		}
		
		if(par){
			if(cont%2 == 0)s[sz-1]='0';
			else s[sz-1] = '1';
		}
		else {
			if(cont%2 == 1)s[sz-1]='0';
			else s[sz-1] = '1';
		}
		
		cout << s << endl;
	}
	
	return 0;
}
