#include<bits/stdc++.h>

using namespace std;

vector<int> p, im;

int main(){
	
	int n, aux;
	cin >> n;
	for(int i = 0 ; i < n ; ++i){
		cin >> aux;
		if(aux%2 == 1) im.push_back(aux);
		else p.push_back(aux);
	}
	
	int ans = 0, psz = p.size(), isz = im.size();
	
	if(im.size() >= 1){
		int i;
		
		for(i = 0 ; i < psz ; ++i)ans+=p[i];
		
		sort(im.begin(), im.end());
		i = 1;
		if(isz%2 == 1)i = 0;
		
		for( ; i < isz ; ++i)ans+=im[i];
	}
	
	cout << ans << endl;

	return 0;
}
