#include<bits/stdc++.h>

using namespace std;

int c[5];

int main(){
	memset(c, 0, sizeof(c));
	
	int n, ans, aux;
	
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> aux;
		c[aux]++;
	}
	
	ans = min(c[1], c[3]);

	c[1]-=ans;
	c[3]-=ans;
	
	if(c[3])ans+=c[3];
	if(c[1]){
		aux = min((c[1] + 1)/2, c[2]);
		c[1]-=aux*2;
		c[2]-=aux;
		ans += aux;
		if(c[1]>0)ans+= (c[1] + 3)/4;
		
	}
	
	if(c[2]){
		ans+=(c[2] + 1)/2;
	}
	
	ans+=c[4];
	
	cout << ans << endl;
	
	return 0;
}
