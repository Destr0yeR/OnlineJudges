#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	stringstream ss;
	
	int n, a, cont;
	
	while(getline(cin, s)){
		ss.clear();
		ss << s;
		
		ss >> n;
		cont = 0;
		getline(cin, s);
		ss.clear();
		ss << s;
		
		
		while(ss >> a){
			if(n == a)cont++;
		}
		cout << cont << endl;
	}
	
	return 0;
}
