#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,i;
	string a[6]={"170","020","200","110","050","080"};
	cin >> n;
	
	if(n<3){
		cout << "-1\n";
	}
	else if(n==3){
		cout << "210\n";
	}
	else{
		cout << 1;
		for(i = 1; i <= n-4; ++i)cout << 0;
		
		cout << a[n%6] << "\n";
	}
}
