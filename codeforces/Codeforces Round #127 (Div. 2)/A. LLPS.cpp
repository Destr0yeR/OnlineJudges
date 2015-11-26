#include<bits/stdc++.h>

using namespace std;

int main(){
	
	string s;
	char last = 'a'-1;
	
	cin >> s;
	
	int sz = s.size(), tot = 0;
	
	for(int i = 0 ; i < sz ; ++i){
		if(s[i] == last)tot++;
		else if(s[i] > last){
			tot = 1;
			last = s[i];
		}
	}
	
	while(tot--)cout<<last;
	cout << '\n';
	
	return 0;
}
