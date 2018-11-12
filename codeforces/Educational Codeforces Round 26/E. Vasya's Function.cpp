#include<bits/stdc++.h>

using namespace std;

map< int , map<int,int> > mp;

int f(int x, int y) {
	if(y == 0)return 0;
	int gc = __gcd(x, y);
	
	if(gc == x)return y/gc;
	return 1 + f(x, y - gc);
}

int main() {
	int a, b;
	
	cin >> a >> b;
	
	cout << f(a, b) << endl;
	
	return 0;
}
