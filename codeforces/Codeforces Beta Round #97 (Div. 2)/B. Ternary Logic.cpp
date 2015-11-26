#include<bits/stdc++.h>

using namespace std;

string toBase(int x){
	string s = "";
	int aux;
	
	while(x){
		aux = x%3;
		s =  char(aux+'0') + s;
		x/=3;	
	}
	return s;
}

int fromBase(string s){
	int sz = s.size(), n = 0;
	
	int m = 1;
	
	for(int i = sz-1 ; i >= 0 ; --i){
		n+=(s[i]-'0')*m;
		m*=3;
	}
	
	return n;
}

int main(){
	
	int na, nb, nc;
	string a, b, c;
	int asz, csz, diff;
	
	cin >> na >> nc;
	
	a = toBase(na);
	c = toBase(nc);
	
	asz = a.size();
	csz = c.size();
	
	if(asz > csz){
		diff = asz - csz;
		for(int i = 0 ; i < diff ; ++i)c = '0'+c;
		csz += diff;
	}
	else if(csz > asz){
		diff = csz - asz;
		for(int i = 0 ; i < diff ; ++i)a = '0'+a;
		asz += diff;
	}
	b = c;
	for(int i = 0 ; i < csz ; ++i){
		diff = (c[i] - a[i]);
		if(diff < 0)diff+=3;
		b[i] = (diff+'0');
	}
	
	nb = fromBase(b);
	
	cout << nb << endl;
	
	return 0;
}
