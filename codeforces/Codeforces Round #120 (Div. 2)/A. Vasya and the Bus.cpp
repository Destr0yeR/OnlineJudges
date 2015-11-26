#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n, m, maxi, mini;
	
	cin >> n >> m;
	
	if(n == 0 && m != 0)cout << "Impossible\n";
	else {
		if(m){
			maxi = m+n-1;
			mini = m+(n-min(n, m));
		}
		else{
			maxi = n;
			mini = n;
		}
		
		cout << mini << " " << maxi << "\n";
	}
	
	
	
	return 0;
}
