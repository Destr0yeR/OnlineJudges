#include<bits/stdc++.h>

using namespace std;

map<unsigned long long, bool> m;

int main(){
	
	unsigned long long i = 1, tot = 1, aux = (LLONG_MAX)/9, min = 0, inp;
	m[1] = 1;
	while(tot < aux && tot > min){
		i++;
		tot*=i;
		m[tot]=1;
		for(unsigned long long j = tot ; j <= aux ; j+=tot)m[j]=1;
	}
	
	int n;
	cin >> n;
	
	while(n--){
		cin >> inp;
		
		if ( m.find(inp) == m.end() ) {
		  cout << "NO" << endl;
		} else {
		  cout << "YES" << endl;
		}
	}
	
	return 0;
}
