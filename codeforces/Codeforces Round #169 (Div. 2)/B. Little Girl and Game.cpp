#include<bits/stdc++.h>

using namespace std;

int let[26];

int main(){
		
	string s;
	cin >> s;
	memset(let, 0, sizeof(let));
	for(int i = 0 ; i < s.size() ; ++i){
		let[s[i] - 'a']++;
	}
	
	int cont = 0;
	
	for(int i = 0 ; i < 26 ; ++i){
		if(let[i]%2)++cont;
	}
	
	if(cont == 0 || cont == 1 || cont%2){
		cout << "First" << endl;
	}
	else cout << "Second" << endl;
	
	return 0;
}
