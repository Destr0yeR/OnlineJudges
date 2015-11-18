#include<bits/stdc++.h>

using namespace std;

int main(){
	unsigned long long a, b;
	
	while(cin >> a >> b){
		a^=b;
		cout << a << endl;
	}
	
	return 0;
}
