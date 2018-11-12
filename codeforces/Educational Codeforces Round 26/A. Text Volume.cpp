#include<bits/stdc++.h>

using namespace std;

int f(string s){
	int cnt = 0;
	
	for (int i = 0; i < (int)s.size(); i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')cnt++;
	}
	return cnt;
}

int main() {
	int n;
	cin >> n;
	string s;
	cin.ignore(255, '\n');
	getline(cin, s);
	
	string aux = "";
	
	int ans = 0;
	
	for (int i = 0; i < (int)s.size(); i++)
	{
		if(s[i] == ' '){
			ans = max(ans, f(aux));
			aux = "";
		}
		else aux += s[i];
	}
	
	cout << max(ans, f(aux)) << endl;
}
