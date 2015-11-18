#include<bits/stdc++.h>

using namespace std;

int main(){
	unsigned long long a, b;
	
	cin >> a >> b;
	
	if(a<b)swap(a,b);
	
	cout << (a+1) * b << endl;
	
	return 0;
}
