#include<bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
	return (a+b) < (b+a);
}

vector<string> v;

int main(){
	
	int n;
	string s;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> s;
		v.push_back(s);
	}
	
	sort(v.begin(), v.end(), cmp);
	
	int sz = v.size();
	
	for(int i = 0 ; i < sz ; ++i){
		cout << v[i];
	}
	
	cout << "\n";

	return 0;
}
