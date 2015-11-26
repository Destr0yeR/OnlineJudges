#include<bits/stdc++.h>

using namespace std;

map<string, int> m;

int q(string s){
	if(m.count(s) == 0){
		m[s] = 0;
		return 0;
	}
	m[s]++;
	return m[s];
}

int main(){
	
	int n, aux;
	string s;
	
	cin >> n;
	
	while(n--){
		cin >> s;
		aux = q(s);
		
		if(aux == 0)cout << "OK";
		else cout << s << aux;
		cout << '\n';
	}
	
	return 0;
}
