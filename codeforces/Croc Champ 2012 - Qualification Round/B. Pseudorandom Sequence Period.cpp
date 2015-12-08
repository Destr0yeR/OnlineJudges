#include<bits/stdc++.h>

#define MAX 1000005

using namespace std;

int v[MAX];

int main(){
	
	int a, b, m, r;
	
	memset(v, 0, sizeof(v));
	
	cin >> a >> b >> m >> r;
	int i = 0;
	v[r] = i++;
	while(!v[r]){
		v[r] = i++;
		r = (r * a + b) % m;
	}
	
	cout << i - v[r] << "\n";
	
	return 0;
}
