#include<bits/stdc++.h>

using namespace std;

int main(){
	int h, m, a;
	char c;
	string hh = "00", mm = "00";
	
	cin >> h >> c >> m;
	cin >> a;

	m += a%60;
	h += a/60;
	
	if(m >= 60){
		h+=1;
		m%=60;
	} 
	h %= 24;
	
	hh[0] = h/10 + '0';
	hh[1] = h%10 + '0';
	
	mm[0] = m/10 + '0';
	mm[1] = m%10 + '0';
	
	cout << hh << ":" << mm << endl;
	
	return 0;
}
