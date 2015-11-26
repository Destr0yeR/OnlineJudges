#include<bits/stdc++.h>

using namespace std;

int main(){
	
	string s, ans;
	
	cin >> s;
	bool founded = false;
	int sz = s.size();
	int i;
	for(i = 0 ; i < sz ; ++i){
		if(!founded && s[i] == '0'){
			founded = true;
			continue;
		}
		ans+=s[i];
	}
	
	i = 0;
	if(!founded)i++;
	sz = ans.size();
	
	for( ; i < sz ; ++i)cout<<ans[i];
	cout << '\n';
	
	return 0;
}
