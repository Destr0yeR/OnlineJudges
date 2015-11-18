#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, x, m;
	string s, sy;
	
	cin >> n >> x;
	x--;
	cin >> s;
	cin >> m;
	cin >> sy;
	
	cout << s[x];
	for(int i = 0 ; i < m ; ++i){
		if(sy[i] == 'R'){
			x++;
			if(x>=n)x=n-1;
		}
		else{
			x--;
			if(x<0)x=0;
		}
		cout << s[x];
	}
	cout << endl;
	
	return 0;
}
