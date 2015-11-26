#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n, aux, neg = 0, sz, tot = 0;
	
	cin >> n;
	
	vector<int> v;
	
	for(int i = 0 ; i < n ; ++i){
		tot++;
		cin >> aux;
		if(aux < 0)neg++;
		if(neg == 3){
			tot--;
			v.push_back(tot);
			neg = 1;
			tot = 1;
		}
	}
	
	v.push_back(tot);
	
	sz = v.size();
	cout << sz << endl;
	cout << v[0];
	for(int i = 1 ; i < sz ; ++i)cout << " " << v[i];
	cout << endl;

	return 0;
}
