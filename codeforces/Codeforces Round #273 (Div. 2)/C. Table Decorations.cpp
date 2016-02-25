#include<bits/stdc++.h>


using namespace std;

int main(){
	long long r, g, b, ans;
	
	cin >> r >> g >> b;
	
	ans = min((r+g+b)/3, (r+g+b) - max(r, max(g, b)));

	cout << ans << endl;
	
	return 0;
}
